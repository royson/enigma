/*
 * Part.cpp
 *
 *  Created on: 15 Oct 2015
 *      Author: dsl114
 */

#include "Part.hpp"
#include "Util.hpp"

using namespace std;

Part::Part(tr1::shared_ptr<istringstream> iss) {
	int tmp;

	while ((*iss) >> tmp) {
		mappings.push_back(tmp);
	}
}

Part::~Part() {}

vector<int> Part::getMappings() {
	return mappings;
}

void Part::printMappings() {
	for (vector<int>::const_iterator i = mappings.begin();
			i != mappings.end(); ++i) {
		int x = *i;
		cout << mapToAlphabet(x) << ' ';
	}
	cout << endl;
}

