#include "../include/gramatica.h"

Gramatica::Gramatica(NFA &dfa) {
  GSterminales_ = dfa.getAlf();

  GSnoterminales_ = std::vector<GSimbolo>();
  for (int i = 0 ; i < dfa.getEstados().size() ; i++) {
    std::string id(1,('A' + i));
    GSimbolo noterminal(id);
    GSnoterminales_.push_back(noterminal);
  }

  for (Estado q : dfa.getEstados()) {
    for (Transicion t : q.GetTransi()) {
      GSnoterminales_[q.GetId()].addProd(std::make_pair(t.GetSim(),
                      &GSnoterminales_[t.GetDest()->GetId()]));
    }
  }

  for (Estado * q : dfa.getFinales()) {
    GSnoterminales_[q->GetId()].addProd(std::make_pair(Cadena("&"),nullptr));
  }

  GSarranque_ = &GSnoterminales_[dfa.getInicial()->GetId()];
}

Gramatica::Gramatica(Alfabeto alf, Cadena cadena) {
  GSterminales_ = alf;
  GSimbolo S("S");
  GSnoterminales_.push_back(S);
  for (Simbolo sim : GSterminales_.getConjunto()) {
    GSnoterminales_[0].addProd(std::make_pair(Cadena(alf,sim),&GSnoterminales_[0]));
  }
  GSnoterminales_[0].addProd(std::make_pair(cadena,nullptr));
  GSarranque_ = &GSnoterminales_[0];
}


std::ostream& operator<<(std::ostream& os, const Gramatica& G) {
  //1. Simbolos terminales
  os << G.GSterminales_.size() << "\n";
  for (Simbolo s : G.GSterminales_.getConjunto()) {
    os << s << "\n";
  }

  //2. Conjunto de simbolos no terminales
  os << G.GSnoterminales_.size() << "\n";
  for (GSimbolo g : G.GSnoterminales_) {
    os << g.GetId() << "\n";
  }

  //3. Simbolo de arranque
  os << G.GSarranque_->GetId() << "\n";

  //4. Producciones
  int nprod = 0;
  for (GSimbolo g : G.GSnoterminales_) {
    nprod += g.GetProd().size();
  }
  os << nprod << "\n";
  for (GSimbolo g : G.GSnoterminales_) {
    os << g;
  }
  return os;
}