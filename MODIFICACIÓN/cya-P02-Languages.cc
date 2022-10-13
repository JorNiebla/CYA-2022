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
#include "lenguaje.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char **argv) {

  if (argc > 1 && std::string(argv[1]) == "--help") {
    std::cout 
    << "Para utilizar este programa se tiene que ejecutar de la siguiente forma:"
    << "./p02_languages filein1.txt filein2.txt fileout.txt opcode\n"
    << "Siendo filein1.txt el fichero con el primer lenguaje\n"
    << "Siendo filein2.txt el fichero con el segundo lenguaje\n"
    << "Siendo fileout.txt el fichero donde se obtendrán los resultados\n"
    << "Siendo opcode el código de la operación, 1-Concatenación, 2-Unión, 3-Intersección, 4-Diferencia, 5-Inversa, 6-Potencia\n"
    << "Cabe destacar que en operaciones no binarias se ignorará los lenguajes en el segundo archivo, y en operaciones binarias\n"
    << "se debe utilizar la misma cantidad de lenguajes en ambos ficheros de entrada.";
    return 0;
  }
  if (argc != 6) {
    std::cout 
    << "No hubo la cantidad de parametros esperados, ejecuta el programa de la forma\n"
    << "./p02_languages filein1.txt filein2.txt fileout.txt opcode cadena\n";
    return 0;
  }
  

  std::ifstream filein1(argv[1]);
  std::ofstream fileout(argv[3]);
  int opcode = std::stoi(argv[4]);
  //En operaciones no binarias simplemente abrimos el primer archivo dos veces para utilizar el mismo código
  if (opcode == 5 || opcode == 6) { 
    std::ifstream filein2(argv[1]);
  }
  int n;
  if (opcode == 6) {
    std::cout << "Introduzca la potencia: "; // no flush needed
    std::cin >> n;
  }
  std::ifstream filein2(argv[2]);

  if (filein1.is_open() && filein2.is_open() && fileout.is_open()) {
    std::string linea1;
    std::string linea2;
    while (std::getline(filein1,linea1) && std::getline(filein2,linea2)) {                //Lee todas las lineas del fichero 1 a 1.
      Simbolo s;

      Lenguaje l1;
      std::stringstream f1l(linea1);
      f1l >> l1;

      Lenguaje l2;
      std::stringstream f2l(linea1);
      f2l >> l2;

      std::string rawcadena = argv[5];

      Alfabeto alf;
      for (char s : rawcadena) {
        Simbolo sim = Simbolo(1,s);
        alf.insertar(sim);
      }
      Cadena c(alf,rawcadena);
      std::vector<Cadena> l3data;
      l3data.push_back(c);
      Lenguaje l3(alf,l3data);

      switch (opcode) {
      case 1: //Concatenación
        fileout << l1.concatenar(l2).concatenar(l3);
        break;
      case 2: //Unión
        fileout << l1.uni(l2).concatenar(l3);
        break;
      case 3: //Intersección
        fileout << l1.interseccion(l2).concatenar(l3);
        break;
      case 4: //Diferencia
        fileout << l1.diferencia(l2).concatenar(l3);
        break;
      case 5: //Inversa
        fileout << l1.inversa().concatenar(l3);
        break;
      case 6: { //Potencia 
        fileout << l1.potencia(n).concatenar(l3);
        break;
        }
      default:
        break;
      }
      fileout << std::endl;
    }
  } else {
    std::cout << "Hubo un error abriendo el archivo\n";
  }

  return 0;
}