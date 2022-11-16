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

#ifndef GRAMATICA_H
#define GRAMATICA_H

#include "nfa.h"
#include "gsimbolo.h"

class NFA;

class Gramatica {
  private:
    Alfabeto GSterminales_;
   	std::vector<GSimbolo> GSnoterminales_;
   	GSimbolo* GSarranque_;

  public:
    /** 
       * \brief Constructor con fichero .fa
       * \param nfafile Nombre del fichero .fa
    */
    Gramatica(NFA &dfa);

    friend std::ostream& operator<<(std::ostream& os, const Gramatica& G);
  };

#endif