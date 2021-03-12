#include "population.hpp"

// Instead of writing numerous main functions for each exercise, I condensed it into a single main function.
// I did this by specifying each variable changed in each exercises with its own separate argument in the population constructor.

int main() {
	
	// Initialize random seed.
	
	srand (time(NULL));
	int npeople, nvaccinated, ninfected, ninfectTime, ninteractionCount;
	float contagionPercent;

	// User Inputs
	
	std::cout << "Size of population >> ";
	std::cin >> npeople;
	
	std::cout << "Chance of contagion (Decimal Percent) >> ";
	std::cin >> contagionPercent;
	
	std::cout << "Starting number of vaccinations >> ";
	std::cin >> nvaccinated;
	
	std::cout << "Starting number of infected >> ";
	std::cin >> ninfected;
	
	std::cout << "Length of infection >> ";
	std::cin >> ninfectTime;
	
	std::cout << "Number of interactions for infected individuals >> ";
	std::cin >> ninteractionCount;
	
	// To alter necessary inputs, remove arguments from right to left.
	
	Population sample(npeople, contagionPercent, nvaccinated, ninfected, ninfectTime, ninteractionCount);
	
	int i;
	for (i = 1; sample.count_infected() != 0; i++) {
		std::cout << "In step " << i << "\t";
		sample.printPop();
		sample.update();
	}
	std::cout << "In step " << i << "\t";
	sample.printPop();

	// Exercise 51.1
	
	/*
	Person joe;
	
	std::cout << RAND_MAX << "\n";
	std::cout << (float) rand() << "\n";
	
	int step = 1;
	for ( ; ; step++) {
			
		joe.update();
		float bad_luck = (float) rand()/(float)RAND_MAX;
		if (bad_luck > 0.95)
			joe.infect(5);
		
		std::cout << "On day " << step << ", Joe is " << joe.status_string() << "\n";
		if (joe.is_stable())
			break;
	}
	*/
}