enigma: Main.o Part.o Rotor.o Plugboard.o Util.o
	g++ -o enigma -std=c++11 -stdlib=libc++ -Werror -pedantic -Wall Main.o Part.o Rotor.o Plugboard.o Util.o

Main.o: Main.cpp 
	g++ -c Main.cpp

Part.o: Part.cpp
	g++ -c Part.cpp

Rotor.o: Rotor.cpp
	g++ -c Rotor.cpp

Plugboard.o: Plugboard.cpp
	g++ -c Plugboard.cpp
	
Util.o: Util.cpp
	g++ -c Util.cpp

clean:
	rm -rf enigma *.o

.PHONY: clean
