#include "logic.h"
#define OPERAND_AMOUNT 3
#define ERROR_MSG "A mistake was made. Try again!"
int* generate_first_type_problem();

int get_random(int a, int b) {
	return rand() % (b - a + 1) + a;
}
int generate_brain_trainer(int amount) {
	return 0;
}

int* generate_first_type_problem() {

	int a, b, c;

	a = get_random(2, 9);

	do {
		b = get_random(1, a - 1);
	} while (b >= a);

	c = get_random(1, 9);
	

	int vector[]{ a,b,c };
	return vector;
}

bool is_not_unique(int* array, int length) {
	for (int i = 0; i < length; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if (array[i] == array[j]) {
				return true;
			}
		}
	}
	return false;
}