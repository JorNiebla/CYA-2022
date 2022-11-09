// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulación de autómatas finitos
// Autor: Jorge Niebla Núñez
// Correo: alu0101215457@ull.edu.es
// Fecha: 09/11/2022
// Archivo estado.h: Clase estado para el nfa.
// Contiene la declaracion de la clase Estado

#ifndef ESTADO_H
#define ESTADO_H

#include "transicion.h"
#include "simbolo.h"

#include <vector>
#include <string>
#include <list>
#include <queue>

class Transicion;

class Estado {
  const int id_;
  std::vector<Transicion> transiciones_;

  public:
  /** 
     * \brief Constructor principal del estado
     * \param identificador El identificador del estado, por ejemplo el estado 0 tiene id 0, etc
  */
  Estado(int identificador);

  /** 
     * \brief Método que añade una nueva transición al estado
     * \param nextstate Puntero al estado siguiente
     * \param symbol Caracter que admite la transición
  */
  void AddTransition(Estado* nextstate, Simbolo symbol);

  /** 
     * \brief Getter del id
     * \return Id del estado
  */
  int GetId();

  /** 
     * \brief Getter de las transiciones
     * \return Vector con las transiciones
  */
  const std::vector<Transicion>& GetTransi();
};

#endif