// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 1: Símbolos, alfabetos y cadenas
// Autor: Jorge Niebla Núñez
// Correo: alu0101215457@ull.edu.es
// Fecha: 04/10/2022
// Archivo cadena.cc: declaraciones de la clase Cadena.
// Contiene todos los métodos de la clase Cadena declarados.

#include "cadena.h"

Cadena::Cadena() {
  data_ = std::vector<Simbolo>();
}

Cadena::Cadena(std::vector<Simbolo> data) {
  data_ = data;
}

Cadena::Cadena(Alfabeto alf, std::string cadena_data) {
  data_ = std::vector<Simbolo>();
  alf_ = alf;
  bool imposible = false;
  while(cadena_data!="" && !imposible) {
    int pos = 1;
    Simbolo s = cadena_data.substr(0,pos);
    while(alf.getConjunto().count(s) == 0) {
      if (pos == cadena_data.length())
        imposible = true;
        break;
      pos++;
      s = cadena_data.substr(0,pos);
    }
    concatenar(s);
    cadena_data.erase(0,cadena_data.find(s)+s.length());
  }
  if (imposible)
    data_ = std::vector<Simbolo>();
}

void Cadena::concatenar(Simbolo s) {
  data_.push_back(s);
}

int Cadena::longitud() const {
  return data_.size();
}

//Creamos una cadena recorriendo la nuestra del revés.
Cadena Cadena::inversa() {
  Cadena temp;
  for (int i = data_.size() - 1; i >= 0; i--) {
    Simbolo s = data_[i];
    temp.concatenar(s);
  }
  return temp;
}

//Recorremos la cadena multiples veces hasta un punto que
//avanza hasta el final, creando una nueva cadena en cada pasada.
std::vector<Cadena> Cadena::prefijos() {
  Cadena cVacia;
  cVacia.concatenar("&");
  std::vector<Cadena> temp;
  temp.push_back(cVacia);
  for (int i = 0; i < data_.size(); i++) {
    Cadena prefijo;
    for (int j = 0; j < i+1; j++) {
      prefijo.concatenar(data_[j]);
    }
    temp.push_back(prefijo);
  }
  return temp;
}

//Rec>etrocede hasta el inicio, creando una nueva cadena en cada pasada.
std::vector<Cadena> Cadena::sufijos() {
  Cadena cVacia;
  cVacia.concatenar("&");
  std::vector<Cadena> temp;
  temp.push_back(cVacia);
  for (int i = 0; i < data_.size(); i++) {
    Cadena sufijo;
    for (int j = data_.size() - 1 - i; j < data_.size(); j++) {
      sufijo.concatenar(data_[j]);
    }
    temp.push_back(sufijo);
  }
  return temp;
}

//Recorremos multiples veces la cadena avanzando el punto de inicio y de fin
//creando una cadena nueva en cada pasada hasta recorrer todo, este método
//no tiene en cuenta cadenas equivalentes, 
//pj: abbab, "a" y "a" aparece 2 veces como subcadena
std::vector<Cadena> Cadena::subcadenas() {
  Cadena cVacia;
  cVacia.concatenar("&");
  std::vector<Cadena> temp;
  temp.push_back(cVacia);
  for (int i = 0; i < data_.size(); i++) {
    for (int j = i; j < data_.size(); j++) {
      Cadena subcadena;
      for (int k = i; k <= j; k++)
        subcadena.concatenar(data_[k]);
      temp.push_back(subcadena);
    }
  }

  std::vector<Cadena> resultado;
  for (int i = 0; i < temp.size(); i++) {
    bool repetido = false;
    for (int j = 0; j < resultado.size(); j++) {
      if (temp[i] == resultado[j]) {
        repetido = true;
        break;
      }
    }
    if (!repetido) {
      resultado.push_back(temp[i]);
    }
  }
  return resultado;
}

std::vector<Cadena> Cadena::prefijosMenosSufijos() {
  auto pref = prefijos();
  auto suf = sufijos();
  std::vector<Cadena> temp;

  for (int i = 0; i < pref.size(); i++) {
    bool repetido = false;
    for (int j = 0; j < suf.size(); j++) {
      if (pref[i] == suf[j]) {
        repetido = true;
        break;
      }
    }
    if (!repetido) {
      temp.push_back(pref[i]);
    }
  }
  return temp;
}

//Sobrecarga para simplificar la salida
std::ostream& operator<<(std::ostream& os, const Cadena& c) {
  for (Simbolo s : c.data_) {
    os << s;
  }
  return os;
}

bool Cadena::operator==(const Cadena& c) const{
  return data_ == c.data_;
}

bool Cadena::operator<(const Cadena& c) const{
  return data_ < c.data_;
}
