/*
 * Part.hpp
 *
 *  Created on: 15 Oct 2015
 *      Author: dsl114
 */

#ifndef PART_HPP_
#define PART_HPP_

#include <sstream>
#include <vector>
#include <iostream>

//Constants
const int ALPHABET_BEGIN = 65;
const int NUMBER_OF_ALPHABETS = 26;

using namespace std;

class Part {
public:
	Part(istringstream* iss);
	virtual ~Part();
	char map(int x);
	char mapToAlphabet(int x);
	void printMappings();
	char reflect(int x);
	vector<int> getMappings();
private:
	vector<int> mappings;
};

#endif /* PART_HPP_ */
