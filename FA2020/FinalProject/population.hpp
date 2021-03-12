#include "person.hpp"
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <set>

class Population {
	std::vector<Person> pop;
	float contagion;
	int infectTime;
	int interactCount;
	void interact(int currentPerson, int ninteractions);
	public :
	
		// Constructors include:
		// 	1. Population of npeople, 0% contagion, 0% vaccinated.
		// 	2. Population of npeople, input contagion, 0% vaccinated.
		// 	3. Population of npeople, input contagion, input vaccinated.
		// 	4. Population of npeople, input contagion, input vaccinated, input original infected #.
		// 	5. Population of npeople, input contagion, input vaccinated, input original infected #, input infection length.
		// 	6. Population of npeople, input contagion, input vaccinated, input original infected #, input infection length, input interactcion count of sick people.
		
		Population(int npeople);
		Population(int npeople, float contagionPercent);
		Population(int npeople, float contagionPercent, int nvaccinated);
		Population(int npeople, float contagionPercent, int nvaccinated, int ninfected);
		Population(int npeople, float contagionPercent, int nvaccinated, int ninfected, int ninfectTime);
		Population(int npeople, float contagionPercent, int nvaccinated, int ninfected, int ninfectTime, int ninteractionsCount);
		
		bool random_infection();
		int count_infected();
		void update();
		void vaccinate(int nvaccinated);
		void printPop();
};

// Constructors 

Population::Population(int npeople) {
	
	// Pushes into the vector pop the number of people specified by npeople.
	
	for(int i = 0; i < npeople; i++) {
		pop.push_back(Person());
	}
	
	// Sets the default contagion rate to 0.
	contagion = 0;
	
	// Sets the length of time an infection lasts for.
	infectTime = 5;
	
	// Sets the number of individuals a sick person interacts with.
	interactCount = 6;
	
	// Infects one person;
	int r;
	r = rand() % pop.size();
	pop.at(r).infect(infectTime);
}

Population::Population(int npeople, float contagionPercent) {
	
	// Sets the length of time an infection lasts for to a default of 5 steps.
	infectTime = 5;
	
	// Pushes into the vector pop the number of people specified by npeople.
	for(int i = 0; i < npeople; i++) {
		pop.push_back(Person());
	}
	
	// Sets the contagion rate to contagionPercent
	contagion = contagionPercent * 100;
	
	// Infects one person.
	int r;
	r = rand() % pop.size();
	pop.at(r).infect(infectTime);
	
	// Sets the number of individuals a sick person interacts with.
	interactCount = 6;
}

Population::Population(int npeople, float contagionPercent, int nvaccinated) {
	
	// Sets the length of time an infection lasts for to a default of 5 steps.
	infectTime = 5;
	
	// Pushes into the vector pop the number of people specified by npeople.
	for(int i = 0; i < npeople; i++) {
		pop.push_back(Person());
	}
	
	// Sets the contagion rate to contagionPercent
	contagion = contagionPercent * 100;
	
	int r;
	r = rand() % pop.size();
	pop.at(r).infect(infectTime);
	
	// Sets random people in the population to vaccinated until nvaccinated is reached.
	// Gets a random integer r, then sets the person at that location to vaccinated if susceptible.
	// Otherwise, increments again.
	int i = 0;
	while (i < nvaccinated) {
		r = rand() % pop.size();
		if (pop.at(r).getState() == 0) {
			pop.at(r).vaccinate();
			i++;
		}
	}
	
	// Sets the number of individuals a sick person interacts with.
	interactCount = 6;
}

Population::Population(int npeople, float contagionPercent, int nvaccinated, int ninfected) {
	
	// Sets the length of time an infection lasts for to a default of 5 steps.
	infectTime = 5;
	
	// Pushes into the vector pop the number of people specified by npeople.
	for(int i = 0; i < npeople; i++) {
		pop.push_back(Person());
	}
	
	// Sets the contagion rate to contagionPercent
	contagion = contagionPercent * 100;
	
	for (int i = 0; i < ninfected; ) {
		int r;
		r = rand() % pop.size();
		if (pop.at(r).getState() == 0) {
			pop.at(r).infect(infectTime);
			i++;
		}
	}
	
	// Sets random people in the population to vaccinated until nvaccinated is reached.
	// Gets a random integer r, then sets the person at that location to vaccinated if susceptible.
	// Otherwise, increments again.
	for(int i = 0; i < nvaccinated; ) {
		int r;
		r = rand() % pop.size();
		if (pop.at(r).getState() == 0) {
			pop.at(r).vaccinate();
			i++;
		}
	}
	
	// Sets the number of individuals a sick person interacts with.
	interactCount = 6;
}

Population::Population(int npeople, float contagionPercent, int nvaccinated, int ninfected, int ninfectTime) {
	// Sets the length of time an infection lasts for to ninfectTime.
	infectTime = ninfectTime;
	
	// Pushes into the vector pop the number of people specified by npeople.
	for(int i = 0; i < npeople; i++) {
		pop.push_back(Person());
	}
	
	// Sets the contagion rate to contagionPercent
	contagion = contagionPercent * 100;
	
	for (int i = 0; i < ninfected; i++) {
		int r;
		r = rand() % pop.size();
		if (pop.at(r).getState() == 0) {
			pop.at(r).infect(infectTime);
		}
	}
	
	// Sets random people in the population to vaccinated until nvaccinated is reached.
	// Gets a random integer r, then sets the person at that location to vaccinated if susceptible.
	// Otherwise, increments again.
	for(int i = 0; i < nvaccinated; ) {
		int r;
		r = rand() % pop.size();
		if (pop.at(r).getState() == 0) {
			pop.at(r).vaccinate();
			i++;
		}
	}
	
	// Sets the number of individuals a sick person interacts with.
	interactCount = 6;
}

Population::Population(int npeople, float contagionPercent, int nvaccinated, int ninfected, int ninfectTime, int ninteractionsCount) {
	// Sets the length of time an infection lasts for to ninfectTime.
	infectTime = ninfectTime;
	
	// Pushes into the vector pop the number of people specified by npeople.
	for(int i = 0; i < npeople; i++) {
		pop.push_back(Person());
	}
	
	// Sets the contagion rate to contagionPercent
	contagion = contagionPercent * 100;
	
	for (int i = 0; i < ninfected; i++) {
		int r;
		r = rand() % pop.size();
		if (pop.at(r).getState() == 0) {
			pop.at(r).infect(infectTime);
		}
	}
	
	// Sets random people in the population to vaccinated until nvaccinated is reached.
	// Gets a random integer r, then sets the person at that location to vaccinated if susceptible.
	// Otherwise, increments again.
	for(int i = 0; i < nvaccinated; ) {
		int r;
		r = rand() % pop.size();
		if (pop.at(r).getState() == 0) {
			pop.at(r).vaccinate();
			i++;
		}
	}
	
	// Sets the number of individuals a sick person interacts with.
	interactCount = ninteractionsCount;
}

// Functions

bool Population::random_infection() {
	
	// Generates a random number from 0 to the population size.
	int i = rand() % pop.size();
	
	// Sets the person at location i to an infection time of 5 days.
	// Returns true if they are successfully infected.
	return pop.at(i).infect(infectTime);
}

int Population::count_infected() {
	
	// Increments over the population and increases count's value for each sick person.
	int count = 0;
	for (int i = 0; i < pop.size(); i++) {
		if (pop.at(i).getState() > 0) {
			count++;
		}
	}
	return count;
}

void Population::update() {
	for (int i = 0; i < pop.size(); i++) {
		pop.at(i).update();
	}
	
	for (int i = 0; i < pop.size(); i++) {
		if (pop.at(i).getState() > 0) {
			
			// Exercise 51.5
			// Interactions
			interact(i, interactCount);
			
			// RNG placeholder.
			int r = 0;
			

			// Exercise 51.3 - Lines 264 - 278
			// Infects neighbors.
			
			// If RNG is less than contagion, left person gets infected.
			r = rand() % 100;
			if (i != 0 && r <= contagion) {
				pop.at(i-1).infect(infectTime);
			}

			// If RNG is less than contagion, right person gets infected.
			// If the person is successfully infected, then skip over them for this iteration.
			// This limits spread of disease to only adjacent individuals.
			r = rand() % 100;
			if (i < pop.size() - 1 && r <= contagion) {
				if (pop.at(i+1).infect(infectTime)) {
					i++;
				}
			}
		}
	}
}

void Population::vaccinate(int nvaccinated) {
	
	// Ensures no infinite loop by manually lowering nvaccinated until it fits in the population with infected people.
	if(pop.size() - nvaccinated < count_infected()) {
		nvaccinated = pop.size() - count_infected();
	}
		
	// Vaccinates random people until nvaccinated is reached.
	for (int i = 0; i < nvaccinated; ) {
		int r;
		r = rand() % pop.size();
		if (pop.at(r).getState() == 0) {
			pop.at(r).vaccinate();
			i++;
		}
	}
	
}

void Population::printPop() {
	
	std::cout << "#sick " << count_infected() << " :";
	for(int i = 0; i < pop.size(); i++) {
		
		// Prints the state
		// std::cout << " " << pop.at(i).getState();
		
		// Prints #sick (number infected) : (? if not infected) (+ if infected) (- if recovered)
		if (pop.at(i).getState() > 0) {
			std::cout << " +";
		}
		else if (pop.at(i).getState() == -1) {
			std::cout << " -";
		}
		else {
			std::cout << " ?";
		}
		
	}
	std::cout << "\n";
}

void Population::interact(int currentPerson, int ninteractions) {
	
	// Creates a set that can only have unique numbers inside.
	std::set<int> interactions;
	std::set<int>::iterator it;
	
	
	// RNG placeholder.
	int r;
	
	// Ensures that there isn't an infinite loop if ninteractions < pop.size().
	if (ninteractions < pop.size()) {
		while (interactions.size() < ninteractions) {
			
			// Adds locations in pop to interact with until ninteractions is reached.
			r = rand() % pop.size();
			
			// Prevents interaction with self.
			if(r != currentPerson) {
				interactions.insert(r);
			}
		}
	}
	else {
		for (int i = 0; i < pop.size(); i++) {
			
			// If ninteractions is greater than pop.size(), interact with the entire population.
			interactions.insert(i);
		}
	}
	for (it = interactions.begin(); it != interactions.end(); it++) {
		r = rand() % 100;
		if (r <= contagion) {
			pop.at(*it).infect(infectTime);
		}
	}
}