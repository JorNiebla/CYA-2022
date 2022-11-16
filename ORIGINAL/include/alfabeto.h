/**
 * @file alfabeto.h
 * @author Jorge Niebla Núñez
 * @brief Contiene la clase Alfabeto y sus definiciones.
 * @version 1
 * @date 2022-11-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

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
    Alfabeto uni(Alfabeto alf) const;
    std::set<Simbolo> getConjunto() const;
    int size() const;
};

#endif