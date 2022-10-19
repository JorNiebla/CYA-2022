// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 3: Calculadora de lenguajes formales
// Autor: Jorge Niebla Núñez
// Correo: alu0101215457@ull.edu.es
// Fecha: 16/11/2022
// Archivo lenguaje.cc: declaraciones de la clase Lenguaje.
// Contiene todos los métodos de la clase Lenguaje declarados.

#include "lenguaje.h"

Lenguaje::Lenguaje() {
  alf_ = Alfabeto();
  data_ = std::set<Cadena>();
}

Lenguaje::Lenguaje(Alfabeto alf) {
  alf_ = alf;
}

Lenguaje::Lenguaje(Alfabeto alf, std::set<Cadena> data) {
  alf_ = alf;
  data_ = data;
}

Alfabeto Lenguaje::getAlf() const {
  return alf_;
}

std::set<Cadena> Lenguaje::getData() const{
  return data_;
}

Lenguaje Lenguaje::concatenar(Lenguaje l) const {
  if (data_.size() == 0 || l.data_.size() == 0) {
    return Lenguaje();
  }

  Alfabeto resalf = alf_.uni(l.getAlf());

  if (data_.size() == 1 && data_.begin()->getData()[0] == "&") return l;
  if (l.data_.size() == 1 && l.data_.begin()->getData()[0] == "&") return *this;

  std::set<Cadena> resdata;
  for (Cadena c1 : data_) {
    for (Cadena c2 : l.data_) {
      resdata.insert(c1.concatenada(c2));
    }
  }

  return Lenguaje(resalf, resdata);
}

Lenguaje Lenguaje::uni(Lenguaje l) const {
  Alfabeto resalf = alf_.uni(l.getAlf());
  std::set<Cadena> resdata = data_;
  for (Cadena c : l.data_) {
    resdata.insert(c);
  }

  return Lenguaje(resalf,resdata);
}

Lenguaje Lenguaje::interseccion(Lenguaje l) const {
  Alfabeto resalf = alf_.uni(l.getAlf());
  std::set<Cadena> resdata;
  for (Cadena c1 : data_) {
    for (Cadena c2 : l.data_) {
      if (c1 == c2) {
        resdata.insert(c1);
        break;
      }
    }
  }
  return Lenguaje(resalf, resdata);
}

Lenguaje Lenguaje::diferencia(Lenguaje l) const {
  std::set<Cadena> resdata;
  for (Cadena c1 : data_) {
    bool found = false;
    for (Cadena c2 : l.data_) {
      if (c1 == c2) {
        found = true;
        break;
      }
    }
    if (!found)
      resdata.insert(c1);
  }
  return Lenguaje(alf_, resdata);
}

Lenguaje Lenguaje::inversa() const {
  std::set<Cadena> resdata;
  for (Cadena c : data_) {
    resdata.insert(c.inversa());
  }
  return Lenguaje(alf_, resdata);
}

Lenguaje Lenguaje::potencia(int n) const {
  if (n == 0) {
    Cadena cVacia;
    cVacia.concatenar("&");
    std::set<Cadena> resdata;
    resdata.insert(cVacia);
    return Lenguaje(alf_, resdata);
  } else if (n > 0) {
    return this->concatenar(potencia(n-1));
  }
  return this->concatenar(potencia(n-1));
}

Lenguaje Lenguaje::operator+(const Lenguaje& l) const {
  return concatenar(l);
}

Lenguaje Lenguaje::operator|(const Lenguaje& l) const {
  return uni(l);
}

Lenguaje Lenguaje::operator^(const Lenguaje& l) const {
  return interseccion(l);
}

Lenguaje Lenguaje::operator-(const Lenguaje& l) const {
  return diferencia(l);
}

Lenguaje Lenguaje::operator!() const {
  return inversa();
}

Lenguaje Lenguaje::operator*(const int& n) const {
  return potencia(n);
}

std::ostream& operator<<(std::ostream& os, const Lenguaje& l) {
  os << "{ ";
  for (Simbolo s : l.alf_.getConjunto())
    os << s << " ";
  os << "} { ";
  for (Cadena c : l.data_) {
    os << c << " ";
  }
  os << "}";
  return os;
}

// std::istream& operator>>(std::istream& is, Lenguaje& l) {
//   Alfabeto alf;
//   std::string rawdata;
//   int keycounter = 0;
//   while (std::getline(is,rawdata,' ')){
//     if (rawdata == "{")
//       continue;
//     if (rawdata == "}") {
//       keycounter++;
//       continue;      
//     }
//     if (keycounter == 0) {
//       alf.insertar(rawdata);
//     } else if (keycounter == 1) {
//       Cadena c(alf,rawdata);
//       l.data_.push_back(c);
//     }
//   }

//   l.alf_ = alf;
//   return is;
// }