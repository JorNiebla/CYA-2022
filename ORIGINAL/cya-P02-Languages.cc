// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Jorge Niebla Núñez
// Correo: alu0101215457@ull.edu.es
// Fecha: 04/10/2022
// Archivo cya-P01-Strings.cc: programa cliente.
// Contiene la función main del proyecto que usa las clases Alfabeto, Cadena y Simbolo
// para ejecutar las operaciones básicas sobre cadenas, longintud, inversa, 
// calcular prefijos, sufijos y subcadenas leyendo la entrada de un archivo 
// con simbolos y una cadena por linea o una cadena (que se dividiría en caracteres = simbolo)

#include "cadena.h"
#include "alfabeto.h"
#include "simbolo.h"
#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char **argv) {

  if (argc > 1 && std::string(argv[1]) == "--help") {
    std::cout 
    << "Para utilizar este programa se tiene que ejecutar de la siguiente forma:"
    << "./p01_strings filein.txt fileout.txt opcode\n"
    << "Siendo filein.txt el fichero con los simbolos y cadenas\n"
    << "Siendo fileout.txt el fichero donde se impriman los resultados\n"
    << "Siendo opcode la operación usada 1-Longitud, 2-Inversa, 3-Prefijos, 4-Sufijos, 5-Subcadenas\n";
    return 0;
  }
  if (argc != 4) {
    std::cout 
    << "No hubo la cantidad de parametros esperados, ejecuta el programa de la forma\n"
    << "./p01_strings filein.txt fileout.txt opcode\n";
    return 0;
  }
  

  std::ifstream filein(argv[1]);
  std::ofstream fileout(argv[2]);
  int opcode = std::stoi(argv[3]);
  if (filein.is_open() && fileout.is_open()) {
    std::string linea;
    while (std::getline(filein,linea)) {                //Lee todas las lineas del fichero 1 a 1.
      Alfabeto alf;
      auto espacio = linea.find_first_of(" ");
      if (espacio != std::string::npos){              //Caso en el que encontremos símbolos (no hay espacios).
        while (espacio != std::string::npos) {
          Simbolo sim(linea.substr(0, espacio));
          alf.insertar(sim);

          linea = linea.substr(espacio+1);
          espacio = linea.find_first_of(" ");
        }
      } else {                                        //Caso sin simbolos, dividimos por caracteres.
        for (auto c : linea) {
          if (c != '\n') {
            alf.insertar(Simbolo(1,c));
          }
        }
      }
      std::string cadena_data = linea;
      //Si es posible creamos una cadena con el alfabeto que tenemos
      //que tenga los mismos caracteres que la ultima palabra de la linea.
      Cadena c(alf, cadena_data);          
      if (c.longitud() == 0) {                        
        fileout << "Error";
      } else {
        switch (opcode) {
        case 1: //Longitud
          fileout << c.longitud();
          break;
        case 2: //Inversa
          fileout << c.inversa();
          break;
        case 3: //Prefijos
          for (Cadena pr : c.prefijos()) {
            fileout << pr << " ";
          }
          break;
        case 4: //Sufijos
          for (Cadena pr : c.sufijos()) {
            fileout << pr << " ";
          }
          break;
        case 5: //Subcadenas
          for (Cadena pr : c.subcadenas()) {
            fileout << pr << " ";
          }
          break;
        default:
          break;
        }
      }
      fileout << std::endl;
    }
  } else {
    std::cout << "Hubo un error abriendo el archivo\n";
  }

  return 0;
}