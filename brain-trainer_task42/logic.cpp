#include "logic.h"

#define ERROR_MSG "A mistake was made. Try again!"
int generate_first_type_problem();

int generate_brain_trainer(int amount) {
	srand(time(0));
	for (int i = 0; i < amount; i++)
	{
		cout<< generate_first_type_problem();
	}
	return 0;
}

int generate_first_type_problem() {
	generation: 
	int a = rand() % 9 + 1;
	int b = rand() % a + 1;
	int c = rand() % 9;
	if (a == b || a == c || a == 0 || b == 0 || c == 0) {
		goto generation;
	}
	return a, b, c;
}