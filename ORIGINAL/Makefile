languages: cya-P03-Calculator.cc alfabeto.o cadena.o lenguaje.o calculadora.o
	g++ -o p03_calculator *.o cya-P03-Calculator.cc -I.

all: languages

alfabeto.o: alfabeto.cc
	g++ -c alfabeto.cc -o alfabeto.o

calculadora.o: calculadora.cc
	g++ -c calculadora.cc -o calculadora.o

cadena.o: cadena.cc
	g++ -c cadena.cc -o cadena.o

lenguaje.o: lenguaje.cc
	g++ -c lenguaje.cc -o lenguaje.o

doc:
	doxygen

.PHONY: clean

clean:
	rm -f *.o
	rm -f p03_calculator
	rm -f fileout*.txt