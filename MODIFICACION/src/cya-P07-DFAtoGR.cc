/**
 * @file cya-P06-NFA.cc
 * @author Jorge Niebla Núñez
 * @brief Fichero que se encarga de leer la entrada, crear el automata
 * y procesar cadenas con los archivos dados.
 * @version 1
 * @date 2022-11-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../include/gramatica.h"
#include "../include/nfa.h"
#include "../include/alfabeto.h"

#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char **argv) {

  for (int i = 0; i < argc; i++) {
    std::string param = argv[i];
    if (param == "--help") {
      std::cout 
      << "Para utilizar este programa se tiene que ejecutar de la siguiente forma:\n"
      << "./p07_dfa2grammar automata.fa gramatica.gra\n"
      << "Siendo automata.fa un fichero de un autómata.\n"
      << "Siendo gramatica.gra el fichero de salida con la especificación de la gramatica" << std::endl;
      return 0;
    }
  }
  if (argc != 3) {
    std::cout 
    << "No hubo la cantidad de parametros esperados, ejecuta el programa de la forma:\n"
    << "./p07_dfa2grammar automata.fa gramatica.gra\n" 
    << "Ejecuta con el parametro --help para más información." << std::endl;
    return 0;
  }

  Alfabeto alf;
  alf.insertar("0");
  alf.insertar("1");
  alf.insertar("2");
  alf.insertar("3");
  alf.insertar("4");
  alf.insertar("5");
  alf.insertar("6");
  alf.insertar("7");
  alf.insertar("8");
  alf.insertar("9");
  std::string cadena = argv[1];
  Gramatica G(alf,cadena);

  std::cout << "AQUI" << std::endl;
  std::ofstream fileout(argv[2]);
  fileout << G;

  return 0;
}