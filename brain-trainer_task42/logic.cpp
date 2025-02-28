#include "logic.h"
#define OPERAND_AMOUNT 3
#define ERROR_MSG "A mistake was made. Try again!"
int* generate_first_type_problem();

int get_random(int a, int b) {
	return rand() % (b - a + 1) + a;
}

int generate_brain_trainer(int amount) {
	int start_time = time(0);

	bool problem_type; // 0 or 1

	for (int i = 0; i < amount; i++)
	{
		problem_type = get_random(0, 1);
		if (problem_type) {
			
		}
	}

	return 0;
}

int* generate_first_type_problem() { //a-b+c

	int a, b, c;

	a = get_random(2, 9);

	do {
		b = get_random(1, a - 1);
	} while (b >= a);

	c = get_random(1, 9);


	int numbers[]{ a,b,c };
	return numbers;
}

int* generate_second_type_problem() { //a+b-c
	auto a = 0;
	auto b = 0;
	auto c = 0;
	

	a = get_random(1, 9);

	do {
		b = get_random(1, 9);
	} while (b == a);

	do {
		c = get_random(1, 9);
	} while (c >= (a + b) || c == a || c == b);



	int numbers[]{ a,b,c };
	return numbers;

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