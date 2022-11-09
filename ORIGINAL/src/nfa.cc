// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Computabilidad y Algoritmia
// 2º de Carrera
// Práctica 8. NFA
// Referencia:
// https://campusingenieriaytecnologia.ull.es/mod/assign/view.php?id=273855
// Autor: Jorge Niebla Núñez
// Contact: alu0101215457@ull.edu.es
// Archivo actual: Clase FFA .h */

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
  int statecounter = 0;
  while (std::getline(nfainput, linea)) {
    std::stringstream ss(linea);
    std::string data;

    std::getline(ss, data, ' ');
    int id = std::stoi(data);
    std::getline(ss, data, ' ');
    bool final = std::stoi(data);
    if (final) final_states_.insert(id);
    std::getline(ss, data, ' ');
    int ntran = std::stoi(data);

    for (int i = 0; i < ntran; i++) {
      std::getline(ss, data, ' ');
      Simbolo s = data;
      std::getline(ss, data, ' ');
      int idto = std::stoi(data);
      states_[id].AddTransition(&states_[idto], s);
    }
  }
  nfainput.close();
}

std::string NFA::ProcessInput(const std::string &input) {

  Cadena entrada(alf_, input);

  std::queue<int> cola;
  std::queue<int> temp;
  for (int i = 0; i < states_.size(); i++) {
    if (states_[i].GetId() == initial_state_->GetId()) {
      cola.push(i);
      break;
    }
  }
  // Compruebo las epsilon transiciones del estado de arranque y meto los estados en la cola
  CheckEpsilon(states_[cola.front()], cola);

  // Proceso la entrada simbolo a simbolo
  for (Simbolo s : entrada.getData()) {
    //Voy vaciando la cola de entrada, las transiciones que contengan el simbolo
    //de entrada son admitidas y sus destinos añadidos a una cola temporal.
    while (!cola.empty()) {
      for (Transicion t : states_[cola.front()].GetTransi()) {
        if (t.GetSim() == s) {
          temp.push(t.GetDest()->GetId());
        }
      }
      cola.pop();
    }
    //Voy vaciando la cola temporal, buscando epsilon transiciones y metiendo
    //los nuevos estados en la cola de entrada.
    while (!temp.empty()) {
      cola.push(temp.front());
      CheckEpsilon(states_[temp.front()], cola);
      temp.pop();
    }
  }

  //Cuando se me acaban los simbolos de entrada miro la cola de entrada por si hay
  //algun estado de aceptación.
  while (!cola.empty()) {
    int id = states_[cola.front()].GetId();
    if (final_states_.find(id) != final_states_.end()) {
      return "Accepted";
    }
    cola.pop();
  }
  return "Rejected";
}

void NFA::CheckEpsilon(Estado &q, std::queue<int> &states)
{
  for (Transicion t : q.GetTransi())
  {
    if (t.IsEpsilon())
    {
      states.push(t.GetDest()->GetId());
      CheckEpsilon(*t.GetDest(), states);
    }
  }
}

bool NFA::isStringValid(const std::string &stringtocheck) const {
  return true;
}