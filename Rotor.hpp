/*
 * Rotor.hpp
 *
 *  Created on: 15 Oct 2015
 *      Author: dsl114
 */

#ifndef ROTOR_HPP_
#define ROTOR_HPP_

#include <sstream>
#include "Part.hpp"

using namespace std;

class Rotor: public Part {
public:
	Rotor(tr1::shared_ptr<istringstream> iss);
	virtual ~Rotor();
	char map(char x, bool direction);
	bool rotate();
	int getRotation();
private:
	int rotation;
};

#endif /* ROTOR_HPP_ */
