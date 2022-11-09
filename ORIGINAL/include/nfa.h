// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Computabilidad y Algoritmia
// 2º de Carrera
// Práctica 8. NFA
// Referencia:
// https://campusingenieriaytecnologia.ull.es/mod/assign/view.php?id=273855
// Autor: Jorge Niebla Núñez
// Contact: alu0101215457@ull.edu.es
// Archivo actual: Cabecera clase DFA .h */

#ifndef NFA_H
#define NFA_H


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <queue>

#include "alfabeto.h"
#include "simbolo.h"
#include "cadena.h"
#include "estado.h"

class NFA {
  private:
    Alfabeto alf_;
    std::vector<Estado> states_;
    Estado* initial_state_;
    std::set<int> final_states_;

  public:
    NFA();
    /** 
       * \brief Constructor con fichero .fa
       * \param dfafile Nombre del fichero .fa
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
       * \return Resultado de procesar, -1 si falla el alfabeto, 0 si no es aceptada y 1 si es aceptada
    */
    std::string ProcessInput(const std::string& input);

    void CheckEpsilon(Estado& q, std::queue<int>& states);
  };

#endif