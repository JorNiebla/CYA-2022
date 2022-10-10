// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Jorge Niebla Núñez
// Correo: alu0101215457@ull.edu.es
// Fecha: 04/10/2022
// Archivo simbolo.h: Alias para Simbolo
// Contiene un simple alias de tipo para simplificar la implementación de Simbolos, ya que no hay operaciones sobre ellos.

#ifndef SIMBOLO_H
#define SIMBOLO_H

#include <string>

using Simbolo = std::string;

// class Simbolo {
//     private:
//         std::string data_;

//     public:
//         Simbolo();
//         Simbolo(std::string data);
//         std::string getData() const;

//     friend bool operator==(const Simbolo& s1, const Simbolo& s2){
//         return s1.getData() == s2.getData(); // keep the same order
//     }
// };

#endif