#include <iostream>
using namespace std;

//Structs
struct primesequence {int number_of_primes_found; int prime;};

//Functions
/* I used pointers because the code in the supplied main function 
   seems to be asking me to update the struct with my function nextPrime.
*/
int nextPrime(primesequence *input);
bool test_If_Prime(int input);

int main() {
	//Initialization
	int nprimes;
	cin>>nprimes;
	struct primesequence sequence;
	sequence.number_of_primes_found = 0;
	sequence.prime = 1;

	while (sequence.number_of_primes_found < nprimes) {
		int number = nextPrime(&sequence);
		cout<<"Number "<<number<<" is prime"<<endl;
	}
	return 1;
}

int nextPrime(primesequence *input) {
	for( ; ; ) {
		input->prime = input->prime + 1;
		if(test_If_Prime(input->prime))
			break;
	}
	input->number_of_primes_found = input->number_of_primes_found + 1;
	return input->prime;
}

//Generic prime tester from last homework.
bool test_If_Prime(int input) {
	//Checks evens, 1, and 3.
	if (input == 1 || input == 2 || input == 3) {
		return true;
	}
	else if (input % 2 == 0) {
		return false;
	}

	//Checks odds until half input
	int i = 3;
	while (i <= input / 2) {
		if (input % i == 0) {
			return false;
		}
		i += 2;
	}
	return true;
}
