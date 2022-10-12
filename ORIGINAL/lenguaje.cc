#include "lenguaje.h"

Lenguaje::Lenguaje() {
  alf_ = Alfabeto();
  data_ = std::vector<Cadena>();
}

Lenguaje::Lenguaje(Alfabeto alf) {
  alf_ = alf;
}

Lenguaje::Lenguaje(Alfabeto alf, std::vector<Cadena> data) {
  alf_ = alf;
  data_ = data;
}

Lenguaje::Lenguaje(std::vector<Simbolo> data) {

}

Alfabeto Lenguaje::getAlf() const {
  return alf_;
}

std::vector<Cadena> Lenguaje::getData() const{
  return data_;
}

Lenguaje Lenguaje::concatenar(Lenguaje l) {
  Alfabeto resalf = alf_.uni(l.getAlf());

  std::vector<Cadena> resdata;
  for (Cadena c1 : data_) {
    for (Cadena c2 : l.data_) {
      resdata.push_back(c1.concatenada(c2));
    }
  }

  return Lenguaje(resalf, resdata);
}

Lenguaje Lenguaje::uni(Lenguaje l) {
  Alfabeto resalf = alf_.uni(l.getAlf());
  std::vector<Cadena> resdata = data_;
  resdata.insert(resdata.end(), l.getData().begin(), l.getData().end());

  return Lenguaje(resalf,resdata);
}

Lenguaje Lenguaje::interseccion(Lenguaje l) {
  
}

Lenguaje Lenguaje::diferencia(Lenguaje l) {

}

Lenguaje Lenguaje::inversa(Lenguaje l) {

}

Lenguaje Lenguaje::potencia(Lenguaje l) {

}

std::ostream& operator<<(std::ostream& os, const Lenguaje& l) {

}

std::istream& operator>>(std::istream& is, const Lenguaje& l) {

}