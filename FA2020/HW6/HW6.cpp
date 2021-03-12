#include "returnGoldbach.hpp"

int main() {
	// returnGoldbach Test Code
	int input, firstGoldbach = 0;
	std::cin >> input;
	for(int i = 4; i <= input; i += 2) {
		firstGoldbach = returnGoldbach(i);
		if(firstGoldbach)
			std::cout << "The number " << i << " is " << firstGoldbach << "+" << (i - firstGoldbach)<<"\n";
	}

	// primeGenerator.hpp Test Code
	/*int nprimes;
	std::cin >> nprimes;
	primeGenerator sequence;
	while (sequence.getPrimesFound() < nprimes) {
		int number = sequence.nextPrime();
		std::cout << "Number " << number << " is prime" << "\n";
	}
	*/

	return 0;
}