// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Operaciones con lenguajes
// Autor: Jorge Niebla Núñez
// Correo: alu0101215457@ull.edu.es
// Fecha: 04/10/2022
// Archivo lenguaje.h: Clase Lenguaje
// Contiene la clase Lenguaje

#ifndef LENGUAJE_H
#define LENGUAJE_H

#include "cadena.h"
#include "alfabeto.h"

#include <vector>
#include <iostream>
#include <set>

class Lenguaje {
  private:
    std::set<Cadena> data_;
    Alfabeto alf_;

  public:
    Lenguaje();
    Lenguaje(Alfabeto alf);
    Lenguaje(Alfabeto alf, std::set<Cadena> data);

    Alfabeto getAlf() const;
    std::set<Cadena> getData() const;

    Lenguaje concatenar(Lenguaje l);
    Lenguaje uni(Lenguaje l);
    Lenguaje interseccion(Lenguaje l);
    Lenguaje diferencia(Lenguaje l);
    Lenguaje inversa();
    Lenguaje potencia(int n);

    bool operator==(const Lenguaje& l) const;
    bool operator<(const Lenguaje& l) const;
    friend std::ostream& operator<<(std::ostream& os, const Lenguaje& l);
    friend std::istream& operator>>(std::istream& is, Lenguaje& l);

};

#endif