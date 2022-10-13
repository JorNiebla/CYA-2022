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

Lenguaje::Lenguaje(std::vector<Simbolo> data) { }

Alfabeto Lenguaje::getAlf() const {
  return alf_;
}

std::vector<Cadena> Lenguaje::getData() const{
  return data_;
}

Lenguaje Lenguaje::concatenar(Lenguaje l) {
  if (data_.size() == 0) {
    return *this;
  }

  Alfabeto resalf = alf_.uni(l.getAlf());

  if (data_.size() == 1 || l.data_.size() == 1) {
    // std::cout << data_[0] << std::endl;
    if (data_[0].getData()[0] == "&")
      return l;
    else if (l.data_[0].getData()[0] == "&")
      return *this;
  }

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
  Alfabeto resalf = alf_.uni(l.getAlf());
  std::vector<Cadena> resdata;
  for (Cadena c1 : data_) {
    for (Cadena c2 : data_) {
      if (c1 == c2) {
        resdata.push_back(c1);
        break;
      }
    }
  }
  return (Lenguaje(resalf, resdata));
}

Lenguaje Lenguaje::diferencia(Lenguaje l) {
  std::vector<Cadena> resdata;
  for (Cadena c1 : data_) {
    bool found = false;
    for (Cadena c2 : l.data_) {
      if (c1 == c2) {
        found = true;
        break;
      }
    }
    if (!found)
      resdata.push_back(c1);
  }
  return Lenguaje(alf_, resdata);
}

Lenguaje Lenguaje::inversa() {
  std::vector<Cadena> resdata;
  for (Cadena c : data_) {
    resdata.push_back(c.inversa());
  }
  return Lenguaje(alf_, resdata);
}

Lenguaje Lenguaje::potencia(int n) {
  if (data_.size() == 0) {
    return *this;
  }
  if (n == 0) {
    Cadena cVacia;
    cVacia.concatenar("&");
    std::vector<Cadena> resdata;
    resdata.push_back(cVacia);
    return Lenguaje(alf_, resdata);
  } else if (n > 0) {
    return this->concatenar(potencia(n-1));
  }
  return this->concatenar(potencia(n-1));
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

std::istream& operator>>(std::istream& is, Lenguaje& l) {
  Alfabeto alf;
  std::string rawdata;
  int keycounter = 0;
  while (std::getline(is,rawdata,' ')){
    if (rawdata == "{")
      continue;
    if (rawdata == "}") {
      keycounter++;
      continue;      
    }
    if (keycounter == 0) {
      alf.insertar(rawdata);
    } else if (keycounter == 1) {
      Cadena c(alf,rawdata);
      l.data_.push_back(c);
    }
  }

  l.alf_ = alf;
  return is;
}