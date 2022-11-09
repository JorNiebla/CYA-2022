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
// Archivo actual: Cabecera clase Set .h */

#ifndef TRANSI_H
#define TRANSI_H

#include "estado.h"
#include "simbolo.h"

class Estado;

class Transicion {

  private:
    Estado* destino_;
    Simbolo simbolo_;

  public:
    /** 
       * \brief Constructor principal de la transición
       * \param fuente Puntero al estado del que viene
       * \param destino Puntero al estado que va
       * \param simbolo Simbolo que admite la transición
    */
    Transicion(Estado* destino = nullptr, Simbolo simbolo = "~");

    /** 
       * \brief Getter del destino
       * \return Puntero al estado destino
    */
    Estado* GetDest();

    /** 
       * \brief Getter del simbolo
       * \return Simbolo de la transición
    */
    Simbolo GetSim();

    /** 
       * \brief Método que determina si es una epsilon transición
       * \return True si lo es, false si no
    */
    bool IsEpsilon();

};

#endif