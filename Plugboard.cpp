/*
 * Plugboard.cpp
 *
 *  Created on: 15 Oct 2015
 *      Author: dsl114
 */

#include "Plugboard.hpp"

Plugboard::Plugboard(tr1::shared_ptr<istringstream> iss):Part(iss) {}

Plugboard::~Plugboard() {}

char Plugboard::map(char x){
	//Assuming that the plugboard contains an even number of numbers
	int searchValue = mapToNumber(x);
	for (int i = 0; i < mappings.size(); i++) {
		if (searchValue == mappings[i]){
			if(i%2 == 0){
				//if index is even, return the next element
				return mapToAlphabet(mappings[i+1]);
			}else{
				//else, return the previous element
				return mapToAlphabet(mappings[i-1]);
			}
		}
	}
	return x;
}

