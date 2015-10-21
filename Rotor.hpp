/*
 * Rotor.hpp
 *
 *  Created on: 15 Oct 2015
 *      Author: dsl114
 */

#ifndef ROTOR_HPP_
#define ROTOR_HPP_

#include <vector>
#include "Part.hpp"


using namespace std;

class Rotor: public Part {
public:
	Rotor(vector<int> inputs);

	virtual ~Rotor();
};

#endif /* ROTOR_HPP_ */
