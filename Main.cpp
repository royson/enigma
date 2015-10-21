// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Rotor.hpp"

using namespace std;

int main(int argc, char **argv) {
//	char *args = *argv;

	//Add the rotors
	vector<Rotor *> rotors;
	string mappings;
	for (int i = 1; i < argc - 1; i++) {

		ifstream rotorfile(argv[i]);
		if (rotorfile.is_open()) {
			getline(rotorfile, mappings);
			istringstream iss(mappings);

//			vector<int> inputs;
//			int tmp;
//
//			while (iss >> tmp) {
//				inputs.push_back(tmp);
//			}

			//create rotor pointer
			Rotor* rotor = new Rotor(&iss);
			//rotors.push_back(rotor);

			rotorfile.close();
		} else {
			cout << "Unable to open file.";
		}

	}

	//DEBUG: Print rotors
	/*for (auto i = mappings.begin(); i != mappings.end();
			++i) {
		Rotor r = *i;
		r.printMappings();
	}
*/
	return 0;
}
