// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Jorge Niebla Núñez
// Correo: alu0101215457@ull.edu.es
// Fecha: 04/10/2022
// Archivo alfabeto.cc: declaraciones de la clase Alfabeto.
// Contiene todos los métodos de la clase Alfabeto declarados.

#include "alfabeto.h"

Alfabeto::Alfabeto() {
  data_ = std::set<Simbolo>();
}

Alfabeto::Alfabeto(std::set<Simbolo> data) {
  data_ = data;
}

//Funcion que crea una cadena si es posible utilizando
//nuestro alfabeto, en caso que no se pueda se devuelve una cadena
//de tamaño 0.
// Cadena Alfabeto::pertenece(std::string cadena_data) {
//   Cadena resultado;
//   while(cadena_data!="") {
//     int pos = 1;
//     Simbolo s = cadena_data.substr(0,pos);
//     while(data_.count(s) == 0) {
//       if (pos == cadena_data.length())
//         return Cadena(std::vector<Simbolo>());
//       pos++;
//       s = cadena_data.substr(0,pos);
//     }
//     resultado.concatenar(s);
//     cadena_data.erase(0,cadena_data.find(s)+s.length());
//   }
//   return resultado;
// }

void Alfabeto::insertar(Simbolo s) {
  data_.insert(s);
}

std::set<Simbolo> Alfabeto::getConjunto() {
  return data_;
}