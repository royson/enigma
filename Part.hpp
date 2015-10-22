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
#include <tr1/memory>
#include "Util.hpp"

using namespace std;

class Part {
public:
	Part(tr1::shared_ptr<istringstream> iss);
	virtual ~Part();
	void printMappings();
	vector<int> getMappings();
protected:
	vector<int> mappings;
};

#endif /* PART_HPP_ */
