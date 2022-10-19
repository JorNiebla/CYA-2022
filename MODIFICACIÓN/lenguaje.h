// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Calculadora de lenguajes formales
// Autor: Jorge Niebla Núñez
// Correo: alu0101215457@ull.edu.es
// Fecha: 16/11/2022
// Archivo lenguaje.h: Clase Lenguaje
// Contiene la clase Lenguaje

#ifndef LENGUAJE_H
#define LENGUAJE_H

#include "cadena.h"
#include "alfabeto.h"

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

    Lenguaje concatenar(Lenguaje l) const;
    Lenguaje uni(Lenguaje l) const;
    Lenguaje interseccion(Lenguaje l) const;
    Lenguaje diferencia(Lenguaje l) const;
    Lenguaje inversa() const;
    Lenguaje potencia(int n) const;

    Lenguaje operator+(const Lenguaje& l) const;
    Lenguaje operator|(const Lenguaje& l) const;
    Lenguaje operator^(const Lenguaje& l) const;
    Lenguaje operator-(const Lenguaje& l) const;
    Lenguaje operator!() const;
    Lenguaje operator*(const int& n) const;

    friend std::ostream& operator<<(std::ostream& os, const Lenguaje& l);
    friend std::istream& operator>>(std::istream& is, Lenguaje& l);

};

#endif