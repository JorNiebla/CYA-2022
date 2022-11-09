// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulación de autómatas finitos
// Autor: Jorge Niebla Núñez
// Correo: alu0101215457@ull.edu.es
// Fecha: 09/11/2022
// Archivo nfa.cc: Implementación de la clase estado.
// Contiene las definiciones de los metodos de la clase Estado

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