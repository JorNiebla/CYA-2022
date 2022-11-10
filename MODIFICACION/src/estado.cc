/**
 * @file estado.cc
 * @author Jorge Niebla Núñez
 * @brief Contiene las definiciones de los metodos de la clase Estado
 * @version 1
 * @date 2022-11-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../include/estado.h"

Estado::Estado(int identificador) : id_(identificador), accesible_(false) {
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

bool Estado::GetAccesible() {
  return accesible_;
}

void Estado::setAccesible(bool a) {
  accesible_ = a;
}