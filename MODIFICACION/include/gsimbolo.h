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

#ifndef GSIMBOLO_H
#define GSIMBOLO_H

#include <set>
#include <utility>
#include <iostream>
#include "cadena.h"

class GSimbolo {
  private:
    std::string ID_;
   	std::set<std::pair<Cadena,GSimbolo*>> producciones_;
   	//std::set<Estado*> final_states_;

  public:
    /** 
       * \brief Constructor con fichero .fa
       * \param nfafile Nombre del fichero .fa
    */
    GSimbolo(std::string identificador);

    void setID(std::string identificador);

    std::string GetId() const;

    std::set<std::pair<Cadena,GSimbolo*>> GetProd();

    void addProd(std::pair<Cadena,GSimbolo*> prod);

    friend std::ostream& operator<<(std::ostream& os, const GSimbolo& g);
  };

#endif