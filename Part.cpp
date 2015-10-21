/*
 * Part.cpp
 *
 *  Created on: 15 Oct 2015
 *      Author: dsl114
 */

#include "Part.hpp"

using namespace std;

Part::Part(const istringstream* iss) {
//	int tmp;
//
//	while ((*iss) >> tmp) {
//		mappings.push_back(tmp);
//	}
}

Part::~Part() {
	// TODO Auto-generated destructor stub
}

vector<int> Part::getMappings() {
	return mappings;
}

char Part::mapToAlphabet(int x) {
	const int OFFSET_TO_ALPHABET = 65;
	return x + OFFSET_TO_ALPHABET;
}

void Part::printMappings() {
	for (vector<int>::const_iterator i = mappings.begin(); i != mappings.end();
			++i) {
		int x = *i;
		cout << mapToAlphabet(x) << ' ';
	}
}

char Part::map(int x){
	return 'a';
}

char Part::reflect(int x) {
	// TODO throw exception when x < 0
	// TODO REPLACE MAGIC NUMBERS
	return mapToAlphabet((x + 13) % 26);
}

