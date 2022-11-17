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

  NFA automata((std::string)(argv[1]));

  Gramatica G = automata.ConvertToGrammar();

  std::ofstream fileout(argv[2]);
  fileout << G;

  return 0;
}