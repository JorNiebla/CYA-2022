// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Calculadora de lenguajes formales
// Autor: Jorge Niebla Núñez
// Correo: alu0101215457@ull.edu.es
// Fecha: 16/11/2022
// Archivo alfabeto.cc: declaraciones de la clase Alfabeto.
// Contiene todos los métodos de la clase Alfabeto declarados.

#include "../include/alfabeto.h"

Alfabeto::Alfabeto() {
  data_ = std::set<Simbolo>();
}

Alfabeto::Alfabeto(std::set<Simbolo> data) {
  data_ = data;
}

void Alfabeto::insertar(Simbolo s) {
  if (s != "&")
    data_.insert(s);
}

Alfabeto Alfabeto::uni(Alfabeto alf) const {
  std::set<Simbolo> resdata;
  for (Simbolo s : data_) {
    resdata.insert(s);
  }
  for (Simbolo s : alf.getConjunto()) {
    resdata.insert(s);
  }

  return Alfabeto(resdata);
}

std::set<Simbolo> Alfabeto::getConjunto() const {
  return data_;
}