/*
 * Plugboard.hpp
 *
 *  Created on: 15 Oct 2015
 *      Author: dsl114
 */

#ifndef PLUGBOARD_HPP_
#define PLUGBOARD_HPP_

#include <sstream>
#include "Part.hpp"

using namespace std;

class Plugboard: public Part {
public:
	Plugboard(tr1::shared_ptr<istringstream> iss);
	virtual ~Plugboard();
	char map(char x);
};

#endif /* PLUGBOARD_HPP_ */
