languages: cya-P02-Languages.cc alfabeto.o cadena.o lenguaje.o
	g++ -o p02_languages *.o cya-P02-Languages.cc -I.

all: languages

alfabeto.o: alfabeto.cc
	g++ -c alfabeto.cc -o alfabeto.o

cadena.o: cadena.cc
	g++ -c cadena.cc -o cadena.o

lenguaje.o: lenguaje.cc
	g++ -c lenguaje.cc -o lenguaje.o

doc:
	doxygen

.PHONY: clean

clean:
	rm -f *.o
	rm -f p02_languages
	rm -f fileout*.txt