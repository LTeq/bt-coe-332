#include "test_If_Prime.hpp"

class primeGenerator {
	private:
		int primesFound;
		int lastNumberTested;
	public:
		primeGenerator();
		primeGenerator(int input);
		int nextPrime();
		int getPrimesFound();
		int getLastNumberTested();
};

// Default Constructor
primeGenerator::primeGenerator() {
	primesFound = 0;
	lastNumberTested = 1;
}

// Increments last_number_tested until it reaches the next prime.
int primeGenerator::nextPrime() {
	do {
		lastNumberTested++;
	}
	while(!test_If_Prime(lastNumberTested));
	primesFound++;
	return lastNumberTested;
}

// Access Functions
int primeGenerator::getPrimesFound() {
	return primesFound;
}
int primeGenerator::getLastNumberTested() {
	return lastNumberTested;
}		
			