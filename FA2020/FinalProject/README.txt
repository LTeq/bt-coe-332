Infectious Disease Simulation, Benjamin Tan, bt9967

Instead of using separate main functions for each experiment, I used multiple different constructors.
To use this program, compile main.cpp using a C++ compiler (i.e. g++ -o main.out main.cpp).
Header files person.hpp contains the Person class, while population.hpp contains the Population class.
The methods of each of these classes are listed below.

**Executing your program: 

	You will be prompted for a:
		Population size.
		A chance of infection upon interaction (decimal percent).
		Number of vaccinated people.
		Starting amount of infected.
		Length of infection.
		Number of interactions of infected people.

**Note About Interactions Versus Localized Spread
	It was unclear after I coded up the random interactions whether to remove contagion to neighbors.
	If I was supposed to remove it, the code is in Population::update() and can be commented.

population.hpp
Population Class Public Members
	bool random_infection() : 
		Infects a random person in the population. Returns true if they're successfully infected.
	int count_infected() :
		Returns the number of infected in the population.
	void update() :
		Simulates a time step for the population including contagion and infection time counters.
	void vaccinate(int nvaccinated) :
		Vaccinates nvaccinated number of people.
	void printPop() :
		Prints in the format:
			#sick (number infected) : (? if not infected) (+ if infected) (- if recovered)
		Change order of comments for formatting of:
			#sick (numberinfected) : (-2 if vaccinated) (-1 if recovered) (0 if susceptible) (>0 if infected)
	void interact(int currentPerson, int ninteractions) :
		Simulates ninteractions of a sick person.

person.hpp
Person Class Public Members
	std::string status_string() :
		Returns a string in the format:
			"sick (#InfectionDays to go)
		Or:
			"status"
	int getState() :
		Returns a person's state.
	void vaccinate() :
		Sets a person's status to vaccinated.
	bool infect(int n) :
		Infects someone for n days if they are susceptible. Returns true if successful.
	bool is_stable() :
		Returns true if someone is recovered.
	
