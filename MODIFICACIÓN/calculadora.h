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
// Contiene la clase Calculadora

#ifndef CALCULADORA_H
#define CALCULADORA_H

#include "lenguaje.h"

#include <iostream>
#include <sstream>
#include <stack>
#include <map>
#include <algorithm>
#include <set>

class Calculadora {
  private:
    std::map<std::string,Lenguaje> variables_;
    std::set<char> op_;

    void leerVariable(std::string in);
    Lenguaje calcular(std::string in);

  public:
    Calculadora();
    std::map<std::string,Lenguaje> getVariables() const;
    void leerEntrada(std::string in);

};

#endif