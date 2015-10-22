/*
 * Rotor.cpp
 *
 *  Created on: 15 Oct 2015
 *      Author: dsl114
 */

#include "Rotor.hpp"

Rotor::Rotor(istringstream* iss) :
		Part(iss) {
	rotation = 0;
}

Rotor::~Rotor() {
	// TODO Auto-generated destructor stub
}

char Rotor::map(char x, bool direction) {
	//cout << "Rotation: " << rotation << endl;

	//cout << "CHAR: " << x << endl;
	int mapIndex = mapToNumber(x);
	if (direction) {
//		cout << "rotation: " << rotation << endl;
//		cout << "mapIndex: " << mapIndex << endl;
//		cout << "rotation+mapindex: " << mapIndex + rotation << endl;
//		cout << "I: " << (mapIndex + rotation) % NUMBER_OF_ALPHABETS << endl;
//		cout << "RETURNING: " <<
//				(mappings[(mapIndex + rotation) % NUMBER_OF_ALPHABETS]) << endl;
		return mapToAlphabet(
				(mappings[(mapIndex + rotation) % NUMBER_OF_ALPHABETS]));
	} else {
		//handles negative numbers as well
		for (int i = 0; i < mappings.size(); i++) {
			if (mappings[i] == mapIndex) {
				return mapToAlphabet(
						(i - rotation + NUMBER_OF_ALPHABETS)
								% NUMBER_OF_ALPHABETS);
			}
		}
	}

}

bool Rotor::rotate() {
	//return true after 26 rotations
	if ((++rotation) % NUMBER_OF_ALPHABETS == 0) {
		rotation = 0;
		return true;
	}
	return false;

}

int Rotor::getRotation() {
	return rotation;
}

