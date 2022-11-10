/**
 * @file cadena.h
 * @author Jorge Niebla Núñez
 * @brief Contiene la clase Cadena y sus definiciones.
 * @version 1
 * @date 2022-11-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef CADENA_H
#define CADENA_H

#include "simbolo.h"
#include "alfabeto.h"

#include <vector>
#include <iostream>

class Cadena {
  private:
    std::vector<Simbolo> data_;
    Alfabeto alf_;

  public:
    Cadena();
    Cadena(std::string cadena_data);
    Cadena(Alfabeto alf, std::string cadena_data);
    Cadena(Alfabeto alf, std::vector<Simbolo> data);
    Cadena(std::vector<Simbolo> data);

    Alfabeto getAlf() const;
    std::vector<Simbolo> getData() const;

    void concatenar(Simbolo s);
    void concatenar(Cadena c);
    Cadena concatenada(Cadena c);
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