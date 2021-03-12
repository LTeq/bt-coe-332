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