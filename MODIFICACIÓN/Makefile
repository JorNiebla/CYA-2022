strings: cya-P01-Strings.cc alfabeto.o cadena.o
	g++ -o p01_strings *.o cya-P01-Strings.cc -I.

all: strings

simbolo.o: simbolo.cc
	g++ -c simbolo.cc -o simbolo.o

alfabeto.o: alfabeto.cc
	g++ -c alfabeto.cc -o alfabeto.o

cadena.o: cadena.cc
	g++ -c cadena.cc -o cadena.o

doc:
	doxygen

.PHONY: clean

clean:
	rm -f *.o
	rm -f p01_strings
	rm -f fileout*.txt