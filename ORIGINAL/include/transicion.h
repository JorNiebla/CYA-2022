/**
 * @file transicion.h
 * @author Jorge Niebla Núñez
 * @brief Contiene la declaracion de la clase Transicion.
 * @version 1
 * @date 2022-11-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulación de autómatas finitos
// Autor: Jorge Niebla Núñez
// Correo: alu0101215457@ull.edu.es
// Fecha: 09/11/2022
// Archivo transicion.h: Clase para las transiciones del nfa.
// Contiene la declaracion de la clase Transicion.

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
       * \param destino Puntero al estado que va
       * \param simbolo Simbolo que admite la transición
    */
    Transicion(Estado* destino = nullptr, Simbolo simbolo = "&");

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