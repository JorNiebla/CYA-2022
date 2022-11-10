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
      << "./p06_automata_simulator automata.fa input.txt\n"
      << "Siendo automata.fa un fichero de un autómata.\n"
      << "Siendo input.txt un fichero con las cadenas a analizar" << std::endl;
      return 0;
    }
  }
  if (argc != 3) {
    std::cout 
    << "No hubo la cantidad de parametros esperados, ejecuta el programa de la forma:\n"
    << "./p06_automata_simulator automata.fa input.txt\n" 
    << "Ejecuta con el parametro --help para más información." << std::endl;
    return 0;
  }

  NFA automata((std::string)(argv[1]));

  std::ifstream filein(argv[2]);
  std::string cadena;
  while (std::getline(filein,cadena)) {
    std::cout << cadena << " --- " << automata.ProcessInput(cadena) << std::endl;
  }

  return 0;
}