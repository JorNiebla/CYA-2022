// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Jorge Niebla Núñez
// Correo: alu0101215457@ull.edu.es
// Fecha: 04/10/2022
// Archivo cadena.h: estructura y declaraciones de la clase Cadena.
// Contiene la clase Cadena y sus definiciones.

#ifndef CADENA_H
#define CADENA_H

#include "simbolo.h"
#include "alfabeto.h"

#include <vector>
#include <iostream>
#include <set>

class Cadena {
  private:
    std::vector<Simbolo> data_;
    Alfabeto alf_;

  public:
    Cadena();
    Cadena(Alfabeto alf, std::string cadena_data);
    Cadena(std::vector<Simbolo> data);

    void concatenar(Simbolo s);
    int longitud() const;
    Cadena inversa();
    std::vector<Cadena> prefijos();
    std::vector<Cadena> sufijos();
    std::vector<Cadena> subcadenas();

    bool operator==(const Cadena& c) const;
    bool operator<(const Cadena& c) const;
    friend std::ostream& operator<<(std::ostream& os, const Cadena& c);

};

#endif