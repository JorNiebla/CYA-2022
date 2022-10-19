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

#include "calculadora.h"
#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char **argv) {

  if (argc > 1 && std::string(argv[1]) == "--help") {
    std::cout 
    << "Para utilizar este programa se tiene que ejecutar de la siguiente forma:"
    << "./p03_calculator filein.txt\n"
    << "Siendo filein.txt el fichero que contiene los lenguajes y operaciones\n";
    return 0;
  }
  if (argc != 2) {
    std::cout 
    << "No hubo la cantidad de parametros esperados, ejecuta el programa de la forma\n"
    << "./p03_calculator filein.txt\n";
    return 0;
  }

  std::ifstream filein(argv[1]);
  if (filein.is_open()) {
    std::string linea;
    Calculadora c;
    while (std::getline(filein,linea)) {                //Lee todas las lineas del fichero 1 a 1.
      std::cout << "Lee esta linea: " << linea << std::endl;
      c.leerEntrada(linea);
    }
  } else {
    std::cout << "Hubo un error abriendo el archivo\n";
  }

  return 0;
}