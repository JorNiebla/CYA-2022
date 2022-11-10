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

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <queue>

class NFA {
  private:
    Alfabeto alf_;
    std::vector<Estado> states_;
    Estado* initial_state_;
    std::set<int> final_states_;

  public:
    /** 
       * \brief Constructor con fichero .fa
       * \param nfafile Nombre del fichero .fa
    */
    NFA (const std::string& nfafile);

    /** 
       * \brief Comprueba si una cadena es compatible con nuestro alfabeto
       * \param stringtocheck Cadena que queremos comprobar
    */
    bool isStringValid(const std::string& stringtocheck) const;
    
    /** 
       * \brief Procesa toda una cadena
       * \param input Cadena a procesar
       * \return Resultado de procesar, string "Rejected" si rechazada y string "Accepted" si es aceptada
    */
    std::string ProcessInput(const std::string& input);

    /** 
       * \brief Busca epsilon transiciones en un estado dado y las añade a una cola dada
       * \param q Estada en el que buscas las epsilon transiciones
       * \param states Cola donde mete las transciones encontradas
    */
    void CheckEpsilon(Estado& q, std::queue<int>& states);
  };

#endif