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
// Archivo actual: Clase transición .h */

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
  return (simbolo_ == "~");
}