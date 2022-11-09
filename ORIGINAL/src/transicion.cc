// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulación de autómatas finitos
// Autor: Jorge Niebla Núñez
// Correo: alu0101215457@ull.edu.es
// Fecha: 09/11/2022
// Archivo transicion.cc: Implementación de la clase transicion.
// Contiene las definiciones de los metodos de la clase Transicion

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