#include "analyzer.h"

Analyzer::Analyzer() {
  main_ = false;
  activecomment_ = false;
}

void Analyzer::searchvariable(std::string linea, int n) {
  std::regex r_variable("\\s*((?:const\\s+)?(?:double|int))\\s+(.*);$");
  std::smatch matches;
  if (std::regex_search(linea,matches,r_variable)) {
    variables_.push_back(std::make_tuple(n, matches[1].str(),matches[2].str()));
  }
}

void Analyzer::searchstatement(std::string linea, int n) {
  std::regex r_statement("\\s*(for|while)\\s*\\(.*\\)");
  std::smatch matches;
  if (std::regex_search(linea,matches,r_statement)) {
    statements_.push_back(std::make_tuple(n, "LOOP",matches[1].str()));
  }
}

void Analyzer::searchcomment(std::string linea, int n) {
  std::smatch matches;
  if (!activecomment_) {
    std::regex r_singlecomment("\\/\\/.*");
    std::regex r_multicomment("\\/\\*.*\\*\\/");
    std::regex r_multistartcomment("\\/\\*.*");
    if (std::regex_search(linea,matches,r_singlecomment)) {
      comments_.push_back(std::make_tuple(n, n,matches[0]));
    }
    if (std::regex_search(linea,matches,r_multicomment)) {
      comments_.push_back(std::make_tuple(n, n,matches[0].str()));
    } else if (std::regex_search(linea,matches,r_multistartcomment)) {
      comments_.push_back(std::make_tuple(n, n,matches[0].str()));
      activecomment_ = true;
    }

  } else {
    auto currentcomment = *comments_.rbegin();
    comments_.pop_back();
    std::regex r_multiendcomment(".*\\*\\/");
    std::string comment = std::get<2>(currentcomment);
    if (std::regex_search(linea,matches,r_multiendcomment)) {
      comment += "\n" + matches[0].str();
      activecomment_ = false;
    } else {
      comment += "\n" + linea;
    }
    comments_.push_back(std::make_tuple(std::get<0>(currentcomment),n , comment));
  }
}

void Analyzer::searchmain(std::string linea) {
  std::regex r_main("\\s*int\\s+main\\s*\\(.*");
  main_ = std::regex_search(linea,r_main);
}

void Analyzer::analyzeFile(std::string filename) {
  filename_ = filename;
  std::ifstream input(filename);  
  if (input.is_open()) {
    analyzeFile(input);
  } else {
    std::cerr << "Hubo un error abriendo el archivo\n";
  }
}

void Analyzer::analyzeFile(std::istream& input) {
  std::string linea;
  int n = 1;
  while (std::getline(input,linea)) {
    searchvariable(linea,n);
    searchstatement(linea,n);
    searchcomment(linea,n);
    if (!main_) searchmain(linea);
    n++;
  }
}

std::ostream& operator<<(std::ostream& os, const Analyzer& ana) {
  os << "PROGRAM: " << ana.filename_ << std::endl;
  if (std::get<0>(ana.comments_[0]) == 1) {
    os << "DESCRIPTION:\n" << std::get<2>(ana.comments_[0]) << std::endl;
  }
  os << "\nVARIABLES:\n";
  for (auto v : ana.variables_) {
    os << "[Line " << std::get<0>(v) << "] ";
    os << std::get<1>(v) << ": " << std::get<2>(v) << "\n";
  }
  os << std::endl << "STATEMENTS:\n";
  for (auto s : ana.statements_) {
    os << "[Line " << std::get<0>(s) << "] ";
    os << std::get<1>(s) << ": " << std::get<2>(s) << "\n";
  }
  os << std::endl << "MAIN:\n";
  if (ana.main_) os << "True";
  else os << "False";
  os << std::endl << "\nCOMMENTS:\n";
  for (auto c : ana.comments_) {
    os << "[Line ";
    int starting_line = std::get<0>(c);
    int finishing_line = std::get<1>(c);
    std::string comment;
    if (starting_line == 1)
      comment = "DESCRIPTION";
    else 
      comment = std::get<2>(c);
    if (starting_line != finishing_line) {
      os << starting_line << "-" << finishing_line << "] ";
    } else {
      os << starting_line << "]  ";
    }
    os << comment << "\n";
  }
  os << std::endl;
  return os;
}

// std::istream& operator>>(std::istream& is, Analyzer& ana) {
//   ana.analyzeFile(is);
//   return is;
// }