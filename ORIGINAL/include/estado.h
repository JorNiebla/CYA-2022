#ifndef ESTADO_H
#define ESTADO_H

#include <vector>
#include <string>
#include <list>
#include <queue>
#include "transicion.h"
#include "simbolo.h"
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
// Archivo actual: Cabecera clase Estado .h */

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
     * \brief Getter del id
     * \return Id del estado
  */
  const std::vector<Transicion>& GetTransi();
};

#endif