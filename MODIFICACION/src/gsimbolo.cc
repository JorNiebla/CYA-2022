/**
 * @file gramatica.h
 * @author Jorge Niebla Núñez
 * @brief Contiene la declaracion de la clase Gramatica.
 * @version 1
 * @date 2022-11-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../include/gsimbolo.h"

GSimbolo::GSimbolo(std::string identificador) {
  ID_ = identificador;
}

void GSimbolo::setID(std::string identificador) {
  ID_ = identificador;
}

std::string GSimbolo::GetId() const {
  return ID_;
}

std::set<std::pair<Cadena,GSimbolo*>> GSimbolo::GetProd() {
  return producciones_;
}

void GSimbolo::addProd(std::pair<Cadena,GSimbolo*> prod) {
  producciones_.insert(prod);
}

std::ostream& operator<<(std::ostream& os, const GSimbolo& g) {
  for (auto p : g.producciones_) {
    os << g.ID_ << " -> " << std::get<0>(p);
    if (std::get<1>(p) != nullptr) {
      os << std::get<1>(p)->GetId();
    }
    os << std::endl;
  }
  return os;
}