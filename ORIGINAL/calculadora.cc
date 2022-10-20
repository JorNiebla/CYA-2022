// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Calculadora de lenguajes formales
// Autor: Jorge Niebla Núñez
// Correo: alu0101215457@ull.edu.es
// Fecha: 16/11/2022
// Archivo calculadora.h: Clase Calculadora
// Contiene todos los métodos de la clase Calculadora

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
  std::stringstream s(in);
  std::string op;

  std::stack<Lenguaje> pila;
  std::stack<int> potencias;

  while (std::getline(s,op,' ')) { //Leo espacio a espacio la entrada dada
    bool number = true;
    if (op_.find(op[0]) == op_.end()) { //No es una operación
      //Compruebo si la cadena está compuesta por todo números
      for (auto c : op) {
          if (!std::isdigit(c)) {
            number = false;
            break;
          }
      }
      if (number) { //Si es un número lo guardo en pila de potencias
        potencias.push(std::stoi(op)); 
      } else {  //Si no es un número debe ser un lenguaje
        try {
          pila.push(variables_.at(op));
        } catch(const std::out_of_range&) {
          std::cerr << "ERROR! Se ha utilizado una variable no declarada: " << std::endl;
          return Lenguaje();
        }
      }
    } else { //Es una operación
      Lenguaje l1 = pila.top();
      pila.pop();
      Lenguaje l2;
      if (op[0] != '*') {
        l2 = pila.top();
        pila.pop();
      }
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
