// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Calculadora de lenguajes formales
// Autor: Jorge Niebla Núñez
// Correo: alu0101215457@ull.edu.es
// Fecha: 16/11/2022
// Archivo cadena.cc: declaraciones de la clase Cadena.
// Contiene todos los métodos de la clase Cadena declarados.

#include "../include/cadena.h"

Cadena::Cadena() {
  data_ = std::vector<Simbolo>();
}

Cadena::Cadena(std::string cadena_data){
  data_ = std::vector<Simbolo>();
  alf_ = Alfabeto();
  for (auto c : cadena_data) {
    Simbolo s = Simbolo(1,c);
    alf_.insertar(s);
    data_.push_back(s);
  }
}

Cadena::Cadena(Alfabeto alf, std::string cadena_data) {
  data_ = std::vector<Simbolo>();
  alf_ = alf;
  bool imposible = false;
  while(cadena_data!="" && !imposible) {
    int pos = 1;
    Simbolo s = cadena_data.substr(0,pos);
    if (s == "&") {
      concatenar(s);
      cadena_data.erase(0,cadena_data.find(s)+s.length());
      continue;
    }
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

Cadena::Cadena(std::vector<Simbolo> data) {
  data_ = data;
}

Cadena::Cadena(Alfabeto alf, std::vector<Simbolo> data) {
  alf_ = alf;
  data_ = data;
}

Alfabeto Cadena::getAlf() const {
  return alf_;
}

std::vector<Simbolo> Cadena::getData() const {
  return data_;
}

void Cadena::concatenar(Simbolo s) {
  data_.push_back(s);
}

void Cadena::concatenar(Cadena c) {
  data_.insert(data_.end(), c.getData().begin(), c.getData().end());
}

Cadena Cadena::concatenada(Cadena c) {
  if (c.data_[0] == "&") return *this;
  if (data_[0] == "&") return c;
  std::vector<Simbolo> resdata = data_;
  resdata.insert(resdata.end(), c.data_.begin(), c.data_.end());
  Alfabeto resalf = alf_.uni(c.alf_);
  return Cadena(resalf,resdata);
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

//Retrocede hasta el inicio, creando una nueva cadena en cada pasada.
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
