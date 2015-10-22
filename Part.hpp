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
#include "Util.hpp"

using namespace std;

class Part {
public:
	Part(istringstream* iss);
	virtual ~Part();
	void printMappings();
	vector<int> getMappings();
protected:
	vector<int> mappings;
};

#endif /* PART_HPP_ */
