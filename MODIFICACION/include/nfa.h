/**
 * @file nfa.h
 * @author Jorge Niebla Núñez
 * @brief Contiene la declaracion de la clase NFA.
 * @version 1
 * @date 2022-11-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef NFA_H
#define NFA_H

#include "alfabeto.h"
#include "simbolo.h"
#include "cadena.h"
#include "estado.h"
#include "transicion.h"
#include "gramatica.h"

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <set>

class Gramatica;

class NFA {
  private:
   	bool dfa_;
   	Alfabeto alf_;
   	std::vector<Estado> states_;
   	Estado* initial_state_;
   	std::set<Estado*> final_states_;

  public:
    /** 
       * \brief Constructor con fichero .fa
       * \param nfafile Nombre del fichero .fa
    */
    NFA (const std::string& nfafile);

		bool isDFA();

		Gramatica ConvertToGrammar();
    
    /** 
       * \brief Procesa toda una cadena
       * \param input Cadena a procesar
       * \return Resultado de procesar, string "Rejected" si rechazada y string "Accepted" si es aceptada
    */
    bool ProcessInput(const std::string& input);

    /** 
       * \brief Busca epsilon transiciones en un estado dado y las añade a una cola dada
       * \param q Estada en el que buscas las epsilon transiciones
       * \param states Cola donde mete las transciones encontradas
    */
    void CheckEpsilon(Estado* &q, std::set<Estado*>& states);

    Alfabeto getAlf();

    std::vector<Estado> getEstados();

    Estado* getInicial();

    std::set<Estado*> getFinales();
  };

#endif