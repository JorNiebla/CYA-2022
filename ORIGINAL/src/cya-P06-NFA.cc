// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Simulación de autómatas finitos
// Autor: Jorge Niebla Núñez
// Correo: alu0101215457@ull.edu.es
// Fecha: 09/11/2022
// Archivo cya-P06-NFA.cc: Programa cliente.
// Fichero que se encarga de leer la entrada, crear el automata
// y procesar cadenas con los archivos dados.

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