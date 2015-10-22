/*
 * Rotor.cpp
 *
 *  Created on: 15 Oct 2015
 *      Author: dsl114
 */

#include "Rotor.hpp"

Rotor::Rotor(istringstream* iss):Part(iss) {}

Rotor::~Rotor() {
	// TODO Auto-generated destructor stub
}

char Rotor::map(char x, bool direction){

	int mapIndex = mapToNumber(x);
	if(direction){
		return mapToAlphabet(mappings[mapIndex]);
	}else{
		return mapToAlphabet(mappings[NUMBER_OF_ALPHABETS-mapIndex]);
	}

}

