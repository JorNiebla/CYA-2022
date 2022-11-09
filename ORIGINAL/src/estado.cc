// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Computabilidad y Algoritmia
// 2º de Carrera
// Práctica 8. NFA
// Referencia:
// https://campusingenieriaytecnologia.ull.es/mod/assign/view.php?id=273855
// Autor: Jorge Niebla Núñez
// Contact: alu0101215457@ull.edu.es
// Archivo actual: Clase estado */

#include "../include/estado.h"

Estado::Estado(int identificador) : id_(identificador) {
  transiciones_.clear();
}

void Estado::AddTransition(Estado* nextstate, Simbolo symbol) {
  transiciones_.push_back(Transicion(nextstate,symbol));
}

const std::vector<Transicion>& Estado::GetTransi() {
  return transiciones_;
}

int Estado::GetId() {
  return id_;
}