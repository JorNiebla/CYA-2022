regex: cya-P04-Regex.cc analyzer.o 
	g++ -o p04_code_analyzer *.o cya-P04-Regex.cc -I.

all: regex

analyzer.o: analyzer.cc
	g++ -c analyzer.cc -o analyzer.o

doc:
	doxygen

.PHONY: clean

clean:
	rm -f *.o
	rm -f p0*
	rm -f codescheme.txt