#include <iostream>
#include <sstream>
#include <fstream>

#ifndef UTIL_HPP_
#define UTIL_HPP_

using namespace std;

//Constants
const int ALPHABET_BEGIN = 65;
const int NUMBER_OF_ALPHABETS = 26;
const int REFLECT_FORWARD = 13;
const bool FORWARD = true;
const bool BACKWARD = false;

//Shared Methods
char mapToAlphabet(int x);
int mapToNumber(char x);
int reflect(int x);
istringstream* readPart(const char* filepath);

#endif /* UTIL_HPP_ */
