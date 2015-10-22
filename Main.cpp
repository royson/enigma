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

	//Add the plugboard
	istringstream* iss = readPart(argv[pbArg]);
	Plugboard* plugboard = new Plugboard(iss);
	delete iss;

	//Accept input
	char ch;
	while (cin >> ws >> ch) {
		if (ch < ALPHABET_BEGIN
				|| ch >= ALPHABET_BEGIN + NUMBER_OF_ALPHABETS) {
			continue;
		}

		//PlugBoard
		ch = plugboard->map(ch);

		int tmp;
		//Rotors (Forward)
		for (int i = 0; i < rotors.size(); i++) {
			if (i == 0) {
				ch = rotors[i]->map(ch, FORWARD);
			} else {
				tmp = mapToNumber(
						(ch - rotors[i - 1]->getRotation())
								+ NUMBER_OF_ALPHABETS)
						% NUMBER_OF_ALPHABETS;
				ch = rotors[i]->map(mapToAlphabet(tmp), FORWARD);
			}
		}

		//Reflect
		int reflectIndex = mapToNumber(ch);
		reflectIndex = reflect(reflectIndex);
		ch = mapToAlphabet(reflectIndex);

		//Rotors (Inverse)
		for (int i = rotors.size() - 1; i >= 0; i--) {
			if (i == 0) {
				ch = rotors[i]->map(ch, BACKWARD);
			} else {
				tmp = mapToNumber(
						rotors[i]->map(ch, BACKWARD)
								+ rotors[i - 1]->getRotation())
						% NUMBER_OF_ALPHABETS;
				ch = mapToAlphabet(tmp);
			}
		}

		//PlugBoard
		ch = plugboard->map(ch);

		//Rotation
		if (rotors.size() > 0) {
			int rotateRotor = 0;
			while (rotors[rotateRotor]->rotate()) {
				rotateRotor = (++rotateRotor);
				if (rotateRotor >= rotors.size()) {
					break;
				}
			}
		}

		cout << ch;

	}

	return 0;
}
