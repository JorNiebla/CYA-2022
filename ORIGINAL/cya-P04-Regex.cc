// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Calculadora de lenguajes formales
// Autor: Jorge Niebla Núñez
// Correo: alu0101215457@ull.edu.es
// Fecha: 16/11/2022
// Archivo cya-P03-Calculator.cc: programa cliente.
// Contiene la función main del proyecto que usa las clases Alfabeto, Cadena y Simbolo
// para ejecutar las operaciones básicas sobre cadenas, longintud, inversa, 
// calcular prefijos, sufijos y subcadenas leyendo la entrada de un archivo 
// con simbolos y una cadena por linea o una cadena (que se dividiría en caracteres = simbolo)

#include "analyzer.h"

#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char **argv) {

  if (argc > 1 && std::string(argv[1]) == "--help") {
    std::cout 
    << "Para utilizar este programa se tiene que ejecutar de la siguiente forma:\n"
    << "./p04_calculator code.cc codescheme.txt\n"
    << "Siendo code.cc un fichero de código estándar de c++.\n"
    << "Siendo codescheme.txt el fichero de texto donde imprimir la información\n"
    << "analizada del fichero de entrada." << std::endl;
    return 0;
  }
  if (argc != 3) {
    std::cout 
    << "No hubo la cantidad de parametros esperados, ejecuta el programa de la forma:\n"
    << "./p04_calculator code.cc codescheme.txt\n" 
    << "Ejecuta con el parametro --help para más información." << std::endl;
    return 0;
  }

  std::ofstream fileout(argv[2]);
  
  Analyzer ana;
  ana.analyzeFile(std::string(argv[1]));
  fileout << ana;

  return 0;
}