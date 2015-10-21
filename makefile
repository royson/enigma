# edit this makefile so that running make compiles your enigma program

enigma: Main.o Part.o Rotor.o
	g++ -o enigma -std=c++11 -Werror -pedantic -Wall Main.o Part.o Rotor.o

Main.o: Main.cpp 
	g++ -c Main.cpp

Part.o: Part.cpp
	g++ -c Part.cpp

Rotor.o: Rotor.cpp
	g++ -c Rotor.cpp

clean:
	rm -rf enigma *.o

.PHONY: clean
