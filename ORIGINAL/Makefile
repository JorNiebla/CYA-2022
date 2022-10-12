languages: cya-P02-p02_Languages.cc alfabeto.o cadena.o
	g++ -o p02_languages *.o cya-P01-Strings.cc -I.

all: languages

simbolo.o: simbolo.cc
	g++ -c simbolo.cc -o simbolo.o

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