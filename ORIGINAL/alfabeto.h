// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Jorge Niebla Núñez
// Correo: alu0101215457@ull.edu.es
// Fecha: 04/10/2022
// Archivo alfabeto.h: estructura y declaraciones de la clase Alfabeto.
// Contiene la clase Alfabeto y sus definiciones.

#ifndef ALFABETO_H
#define ALFABETO_H

#include "simbolo.h"

#include <set>

class Alfabeto {
  private:
    std::set<Simbolo> data_;

  public:
    Alfabeto();
    Alfabeto(std::set<Simbolo> data);
    
    void insertar(Simbolo s);
    std::set<Simbolo> getConjunto();
    // Cadena pertenece(std::string cadena_data);

};

#endif