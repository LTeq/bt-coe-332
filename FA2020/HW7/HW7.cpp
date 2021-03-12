#include <iostream>

class Pascal{
    private:
		// a stores the # of rows of Pascal's triangle upon construction.
        int a;
		// array stores exactly the number of coefficients needed upon construction.
		// It's a two-dimensional array with rows n and columns j where j increments from 1 to n.
        int **array;
    public:
		// Constructor where n is number of rows.
        Pascal(int n);
        ~Pascal(); 
		float get(int i, int j);
		void print();
		void print(int m);
};

Pascal::Pascal(int n){
	// To make n rows, we need to go to n + 1.
	a = n+1;
    array = new int*[n+1];
    for (int i = 0; i<=n; i++) {
        array[i] = new int[i];
		array[i][0] = 1;
		for (int j = 1; j < i; j++) {
				array[i][j] = array[i-1][j-1] +  array[i-1][j];
		}
		array[i][i-1] = 1;
    }
}

void Pascal::print() {
	for (int i = 0; i < a; i++) {
		for (int k = 0; k < a - i; k++) {
			std::cout << "\t";
		}			
		for (int j = 0; j < i; j++) {
			std::cout<<array[i][j] << "\t\t";
		}
		std::cout << "\n";
	}
}

void Pascal::print(int m) {
	for (int i = 0; i < a; i++) {
		for (int k = 0; k < a - i; k++) {
			std::cout << " ";
		}
		for (int j = 0; j < i; j++) {
			if(array[i][j] % m != 0) {
				// Uses *_ to always create an even number of characters.
				std::cout << "* ";
			}
			else
				std::cout << "  ";
		}
		std::cout<<"\n";
	}
}

Pascal::~Pascal(){
    delete[] array;
}

float Pascal::get(int i, int j) {
	return array[i][j];
}

int main() {
	int rows = 0, mod = 0;
	std::cin >> rows;
	Pascal triangle1(rows);
	do {
		std::cin >> mod;
		triangle1.print(mod);
	}
	while(mod != 0);
	return 0;
}