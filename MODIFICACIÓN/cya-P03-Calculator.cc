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
    << "Para utilizar este programa se tiene que ejecutar de la siguiente forma:\n"
    << "./p03_calculator filein.txt\n"
    << "Siendo filein.txt el fichero que contiene los lenguajes y operaciones.\n"
    << "Para hacer declaraciones de lenguajes en el fichero se tiene que hacer\n"
    << "de la siguiente manera:\n"
    << "L1 = {0, 1, 110, 100}\n"
    << "Donde L1 es el nombre del lenguaje (no puede ser solo dígitos) y dentro\n"
    << "de las llaves estarían las cadenas separadas por comas (se asume cada \n"
    << "caracter que compone la cadena como un símbolo)." << std::endl;
    return 0;
  }
  if (argc != 2) {
    std::cout 
    << "No hubo la cantidad de parametros esperados, ejecuta el programa de la forma:\n"
    << "./p03_calculator filein.txt" << std::endl;
    return 0;
  }

  std::ifstream filein(argv[1]);
  if (filein.is_open()) {
    std::string linea;
    Calculadora c;
    while (std::getline(filein,linea)) { //Lee todas las lineas del fichero 1 a 1.
      std::cout << "Lee esta línea del fichero: " << linea << std::endl;
      c.leerEntrada(linea);
    }
    std::cout 
    << "-------------------------------------------\n"
    << "Entrada interactiva, pulse \"q\" para salir\n" 
    << "-------------------------------------------" 
    << std::endl;
    while (std::getline(std::cin,linea)) {
      if (linea == "q") break;
      c.leerEntrada(linea);
    }
  } else {
    std::cout << "Hubo un error abriendo el archivo" << std::endl;
  }

  return 0;
}