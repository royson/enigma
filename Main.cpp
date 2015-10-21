// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Rotor.hpp"
#include "Plugboard.hpp"

using namespace std;

istringstream* readPart(const char* filepath) {
	string mappings;
	ifstream filePart(filepath);
	if (filePart.is_open()) {
		getline(filePart, mappings);
		shared_ptr<istringstream> iss = new istringstream(mappings);
		return iss;
	} else {
		cerr << "Unable to open " << filepath << endl;
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char **argv) {
	//Check if there is an least a plugboard
	if (argc <= 1) {
		cerr << "Please include at least a plugboard" << endl;
		exit(EXIT_FAILURE);
	}

	//Add the rotors
	vector<Rotor *> rotors;

	int pbArg = argc - 1;

	for (int i = 1; i < pbArg; i++) {
		Rotor* rotor = new Rotor(readPart(argv[i]));
		rotors.push_back(rotor);
	}

	//DEBUG: Print rotors
	for (vector<Rotor *>::const_iterator i = rotors.begin(); i != rotors.end();
			++i) {
		Rotor* r = *i;
		(*r).printMappings();
	}
	//END_DEBUG

	//Add the plugboard
	Plugboard* plugboard = new Plugboard(readPart(argv[pbArg]));

	//DEBUG: Print plugboard
	(*plugboard).printMappings();
	//END_DEBUG

	//Accept input
	char ch;
	while(cin >> ch){
		if(ch < ALPHABET_BEGIN || ch >= ALPHABET_BEGIN+NUMBER_OF_ALPHABETS){
			cerr << "Please enter a capital letter." << endl;
			exit(EXIT_PROCESS);
		}
	}

	return 0;
}
