
#ifndef ANALYZER_H
#define ANALYZER_H

#include <vector>
#include <string>
#include <tuple>
#include <regex>
#include <iostream>
#include <fstream>

class Analyzer {
  private:
    std::string filename_;
    std::vector<std::tuple<int,std::string, std::string>> variables_;
    std::vector<std::tuple<int,std::string, std::string>> statements_;
    bool main_;
    std::vector<std::tuple<int,int,std::string>> comments_;
    bool activecomment_;

    void searchvariable(std::string linea, int n);
    void searchstatement(std::string linea, int n);
    void searchcomment(std::string linea, int n);
    void searchmain(std::string linea);

  public:
    Analyzer();
    void analyzeFile(std::string filename); //Versión en la que se le da el nombre del fichero
    void analyzeFile(std::istream& input); //Versión por stream, incapaz de deducir filename_

    friend std::ostream& operator<<(std::ostream& os, const Analyzer& ana);
    friend std::istream& operator>>(std::istream& is, const Analyzer& ana);
};

#endif