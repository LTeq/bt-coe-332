#include "primeGenerator.hpp"
#include <iostream>

int returnGoldbach(int input);

// Returns the lower of the two Goldbach numbers of the input.
// Returns 0 if the number is odd or less than 4.

int returnGoldbach(int input) {
	if(input % 2 != 0 && input < 4) {
		return 0;
	}
	primeGenerator sequence;
	int i = 2;
	while(!test_If_Prime(input - i)) {
		i = sequence.nextPrime();
	}
	return i;
}
		
	