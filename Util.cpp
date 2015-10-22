using namespace std;
#include <cstdlib>
#include "Util.hpp"

//Shared Methods

char mapToAlphabet(int x) {
	return x + ALPHABET_BEGIN;
}

int mapToNumber(char x) {
	return x - ALPHABET_BEGIN;
}

int reflect(int x) {
	return (x + REFLECT_FORWARD) % NUMBER_OF_ALPHABETS;
}

istringstream* readPart(const char* filepath) {
	string mappings;
	ifstream filePart(filepath);
	if (filePart.is_open()) {
		getline(filePart, mappings);
		//std::shared_ptr<istringstream> iss (new istringstream(mappings));
		istringstream* iss = new istringstream(mappings);
		return iss;
	} else {
		cerr << "Unable to open " << filepath << endl;
		exit(EXIT_FAILURE);
	}
}
