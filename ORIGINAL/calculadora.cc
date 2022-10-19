#include "calculadora.h"

Calculadora::Calculadora() {
  op_.insert('+');
  op_.insert('|');
  op_.insert('^');
  op_.insert('-');
  op_.insert('!');
  op_.insert('*');

  variables_ = std::map<std::string,Lenguaje>();
}

std::map<std::string,Lenguaje> Calculadora::getVariables() const {
  return variables_;
}

void Calculadora::leerVariable(std::string in) {
  std::string name = in.substr(0, in.find_first_of('='));
  std::set<Cadena> data;
  Alfabeto alf;
  in = in.substr(in.find_first_of('=')+1);
  in.erase(std::remove(in.begin(), in.end(), '{'), in.end());
  in.erase(std::remove(in.begin(), in.end(), '}'), in.end());
  std::string cadenadata = "";
  for (char c : in) {
    if (c == ',') {
      Cadena cad(cadenadata);
      // std::cout << cadenadata << " " << cad.getAlf().getConjunto().size() << std::endl;
      alf = alf.uni(cad.getAlf());
      data.insert(cad);
      cadenadata = "";
      continue;
    }
    cadenadata = cadenadata + c;
  }
  if (cadenadata.length() != 0) {
    Cadena cad(cadenadata);
    alf = alf.uni(cad.getAlf());
    data.insert(cad);
  }

  Lenguaje l(alf,data);
  variables_.emplace(name,l);
}

Lenguaje Calculadora::calcular(std::string in) {
  // std::cout << "Numero de variables disponibles " << variables_.size() << std::endl;
  std::stringstream s(in);
  std::string op;
  std::stack<Lenguaje> pila;
  std::stack<int> potencias;
  while (std::getline(s,op,' ')) {
    bool number = true;
    if (op_.find(op[0]) == op_.end()) { //No es una operación
      for (auto c : op) {
          if (!std::isdigit(c)) {
            number = false;
            break;
          }
      }
      if (number) {
        potencias.push(std::stoi(op));
      } else {
        pila.push(variables_.at(op));
      }
    } else { //Es una operación
      Lenguaje l1 = pila.top();
      pila.pop();
      Lenguaje l2 = pila.top();
      pila.pop();
      switch (op[0]) {
      case '+':
        pila.push(l1 + l2);
        break;
      case '|':
        pila.push(l1 | l2);
        break;
      case '^':
        pila.push(l1 ^ l2);
        break;
      case '-':
        pila.push(l1 - l2);
        break;
      case '!':
        pila.push(!l1);
        break;
      case '*':
        pila.push(l1 * potencias.top());
        potencias.pop();
        break;
      }
    }    
  }
  return pila.top();
}

void Calculadora::leerEntrada(std::string in) {
  //Definición de variable, quito espacios por comodidad
  if (in.find('=') != std::string::npos) { 
    in.erase(std::remove(in.begin(), in.end(), ' '), in.end());
    leerVariable(in);
  } else { //No definición, debe ser operación
    std::cout << calcular(in) << std::endl;
  }
}
