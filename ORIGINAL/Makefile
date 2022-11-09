NFA: src/cya-P06-NFA.cc nfa.o cadena.o alfabeto.o estado.o transicion.o
	mkdir -p bin
	g++ -o bin/p06_automata_simulator obj/* src/cya-P06-NFA.cc -I.

all: NFA doc

nfa.o: src/nfa.cc
	mkdir -p obj
	g++ -c src/nfa.cc -o obj/nfa.o

cadena.o: src/cadena.cc
	g++ -c src/cadena.cc -o obj/cadena.o

alfabeto.o: src/alfabeto.cc
	g++ -c src/alfabeto.cc -o obj/alfabeto.o

estado.o: src/estado.cc
	g++ -c src/estado.cc -o obj/estado.o

transicion.o: src/transicion.cc
	g++ -c src/transicion.cc -o obj/transicion.o

doc:
	doxygen

.PHONY: clean

clean:
	rm -rf html
	rm -f bin/*
	rm -f obj/*