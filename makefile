# edit this makefile so that running make compiles your enigma program

enigma: Main.o
	g++ -o enigma -Werror -pendatic -Wall Main.o

Main.o: Main.cpp 
	g++ -c Main.cpp

clean:
	rm -rf enigma *.o

.PHONY: clean
