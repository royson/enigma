
#include "Util.hpp"

using namespace std;

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

tr1::shared_ptr<istringstream> readPart(const char* filepath) {
	string mappings;
	ifstream filePart(filepath);
	if (filePart.is_open()) {
		getline(filePart, mappings);

		tr1::shared_ptr<istringstream> iss (new istringstream(
				mappings));
		return iss;
	} else {
		cerr << "Unable to open " << filepath << endl;
		exit(EXIT_FAILURE);
	}
}
