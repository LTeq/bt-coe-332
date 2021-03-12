#include <iostream>
#include <string>
#include <sstream>

class Person {
	int state;
	public :
		Person();
		std::string status_string();
		int getState();
		void update();
		void vaccinate();
		bool infect(int n);
		bool is_stable();
};


// Constructor

Person::Person() {
	state = 0;
}

std::string Person::status_string() {
	
	// Uses stringstream to convert int state to string.
	
	std::stringstream ss;
	ss << state;
	
	// Returns the status of the person where:
	// -1 =  recovered.
	// -2 = vaccinated.
	// 0 = susceptible.
	// >0 = sick for n days.
	
	if (state > 0) {
		return "sick (" + ss.str() + " to go)"; // Inputs status into the given string.;
	}
	else if (state == -1) {
		return "recovered";
	}
	else if (state == -2) {
		return "vaccinated";
	}
	else
		return "susceptible";
}

int Person::getState() {
	return state;
}

void Person::update() {
	
	// Reduces someone's count of days infected by one.
	// If they're at one day left of infection, then make them recovered.
	
	if(state > 1) {
		state--;
	}
	else if(state == 1) {
		state = -1;
	}
}

void Person::vaccinate() {
	state = -2;
}

bool Person::infect(int n) {
	
	// Sets susceptible individuals to a state of n days of infection.
	// If the person is successfully infected, returns true.
	
	if(state == 0) {
		state = n;
		return true;
	}
	return false;
}

bool Person::is_stable() {
	
	// Returns true if the person has recovered.
	
	if(state == -1) {
		return true;
	}
	else
		return false;
}
