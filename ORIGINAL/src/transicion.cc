/**
 * @file transicion.cc
 * @author Jorge Niebla Núñez
 * @brief Contiene las definiciones de los metodos de la clase Transicion
 * @version 1
 * @date 2022-11-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../include/transicion.h"

Transicion::Transicion(Estado* destino, Simbolo simbolo) {
  destino_ = destino;
  simbolo_ = simbolo;
}

Estado* Transicion::GetDest() {
  return destino_;
}

Simbolo Transicion::GetSim() {
  return simbolo_;
}

bool Transicion::IsEpsilon() {
  return (simbolo_ == "&");
}