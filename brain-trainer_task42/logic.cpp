#include "logic.h"
#define OPERAND_AMOUNT 3
#define ERROR_MSG "A mistake was made. Try again!"
int* generate_first_type_problem();


int generate_brain_trainer(int amount) {

	for (int i = 0; i < 3; i++)
	{
		cout << generate_first_type_problem()[i] << (i == 2 ? "\n" : " ");
	}
	return 0;
}

int* generate_first_type_problem() {
	int numbers[OPERAND_AMOUNT];

	numbers[0] = rand() % 9 + 1;
	numbers[1] = rand() % numbers[0] + 1;
	numbers[2] = rand() % 9;

	if (is_not_unique(numbers, OPERAND_AMOUNT)) {
		generate_first_type_problem();
	}

	return numbers;
}

bool is_not_unique(int* array, int length) {
	for (int i = 0; i < length; i++)
	{
		for (int j = i+1; j < length; j++)
		{
			if (array[i] == array[j]) {
				return true;
			}
		}
	}
	return false;
}