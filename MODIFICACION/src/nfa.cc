/**
 * @file nfa.cc
 * @author Jorge Niebla Núñez
 * @brief Contiene las definiciones de los metodos de la clase NFA
 * @version 0.1
 * @date 2022-11-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "../include/nfa.h"

NFA::NFA(const std::string& nfafile) {
  std::ifstream nfainput(nfafile);
  std::string linea;

  // Primera linea alfabeto
  std::getline(nfainput, linea);
  std::stringstream ss(linea);
  while (std::getline(ss, linea, ' ')) {
    alf_.insertar(linea);
  }

  // Segunda línea, numero total de estados
  std::getline(nfainput, linea);
  for (int i = 0; i < std::stoi(linea); i++) {
    states_.push_back(Estado(i));
  }

  // Tercera línea, estado inicial
  std::getline(nfainput, linea);
  initial_state_ = &states_[std::stoi(linea)];

  // Resto de líneas, estados y sus definiciones
  while (std::getline(nfainput, linea)) {
    std::stringstream ss(linea);
    std::string data;

    std::getline(ss, data, ' ');
    int id = std::stoi(data);
    std::getline(ss, data, ' ');
    bool final = std::stoi(data);
    if (final) final_states_.insert(&states_[id]);
    std::getline(ss, data, ' ');
    int ntran = std::stoi(data);


    //COMPROBAMOS TAMBIEN SI ES UN DFA
    std::set<Simbolo> ts;

    for (int i = 0; i < ntran; i++) {
      std::getline(ss, data, ' ');
      Simbolo s = data;
      ts.insert(s);
      std::getline(ss, data, ' ');
      int idto = std::stoi(data);
      states_[id].AddTransition(&states_[idto], s);
    }

    dfa_ = false;
    if (alf_.getConjunto() == ts && ntran == alf_.getConjunto().size())
      dfa_ = true;
  }
  nfainput.close();
}

bool NFA::ProcessInput(const std::string &input) {
  Cadena entrada(alf_, input);

  std::set<Estado*> cola;
  std::set<Estado*> temp;
  for (int i = 0; i < states_.size(); i++) {
    if (states_[i].GetId() == initial_state_->GetId()) {
      cola.insert(&states_[i]);
      break;
    }
  }
  // Compruebo las epsilon transiciones del estado de arranque y meto los estados en la cola
  for (auto q : cola) {
    CheckEpsilon(q, cola);
  }
  // Proceso la entrada simbolo a simbolo
  for (Simbolo s : entrada.getData()) {
    //Voy vaciando la cola de entrada, las transiciones que contengan el simbolo
    //de entrada son admitidas y sus destinos añadidos a una cola temporal.
    for (Estado* q : cola) {
      for (Transicion t : q->GetTransi()) {
        if (t.GetSim() == s) {
          temp.insert(t.GetDest());
        }
      }
    }
    cola.clear();
    //Voy vaciando la cola temporal, buscando epsilon transiciones y metiendo
    //los nuevos estados en la cola de entrada.
    for (Estado* q : temp) {
      cola.insert(q);
      CheckEpsilon(q, cola);
    }
    temp.clear();
  }

  //Cuando se me acaban los simbolos de entrada miro la cola de entrada por si hay
  //algun estado de aceptación.
  for (Estado* q : cola) {
    if (final_states_.find(q) != final_states_.end()) {
      return true;
    }
  }
  return false;
}


void NFA::CheckEpsilon(Estado* &q, std::set<Estado*> &states) {
  for (Transicion t : q->GetTransi()) {
    if (t.IsEpsilon()) {
      Estado* dest = t.GetDest();
      states.insert(dest);
      CheckEpsilon(dest, states);
    }
  }
}

bool NFA::isDFA() {
  return dfa_;
}

Gramatica NFA::ConvertToGrammar() {
  if (!dfa_) {
    throw "No es un dfa";
  }
  return Gramatica(*this);
}

Alfabeto NFA::getAlf() {
  return alf_;
}

std::vector<Estado> NFA::getEstados() {
  return states_;
}

Estado* NFA::getInicial() {
  return initial_state_;
}

std::set<Estado*> NFA::getFinales() {
  return final_states_;
}