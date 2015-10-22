// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <memory>

#include "Rotor.hpp"
#include "Plugboard.hpp"

using namespace std;

int DEBUG = false;

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
		istringstream* iss = readPart(argv[i]);
		Rotor* rotor = new Rotor(readPart(argv[i]));
		delete iss;
		rotors.push_back(rotor);
	}

	if (DEBUG) {
		for (vector<Rotor *>::const_iterator i = rotors.begin();
				i != rotors.end(); ++i) {
			Rotor* r = *i;
			(*r).printMappings();
		}
	}

	//Add the plugboard
	istringstream* iss = readPart(argv[pbArg]);
	Plugboard* plugboard = new Plugboard(iss);
	delete iss;

	if (DEBUG) {
		(*plugboard).printMappings();
	}

	//Accept input
	char ch;
	while (cin >> ch) {
		if (ch < ALPHABET_BEGIN || ch >= ALPHABET_BEGIN + NUMBER_OF_ALPHABETS) {
			cerr << "Please enter a capital letter." << endl;
			exit(EXIT_FAILURE);
		} else {
			if (DEBUG) {
				cout << "Input: " << ch << endl;
			}
			//Rotors (Forward) (SINGLE ROUTER ONLY)
			for (int i = 0; i < rotors.size(); i++) {
				ch = rotors[i]->map(ch, FORWARD);
				if (DEBUG) {
					cout << "After rotor " << i << ": " << ch << endl;
				}
			}

			//Reflect
			int reflectIndex = mapToNumber(ch);
			reflectIndex = reflect(reflectIndex);
			ch = mapToAlphabet(reflectIndex);
			if (DEBUG) {
				cout << "After reflect: " << ch << endl;
			}

			//Rotors (Inverse)
			for (int i = 0; i < rotors.size(); i++) {
				ch = rotors[i]->map(ch, BACKWARD);
				if (DEBUG) {
					cout << "After rotor inverse " << i << ": " << ch << endl;
				}
			}

			cout << ch << endl;

		}
	}

	return 0;
}
