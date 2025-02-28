#include "logic.h"
#define OPERAND_AMOUNT 3
#define MISTAKE_MSG "A mistake was made. Try again!\n"
int generate_first_type_problem();
int generate_second_type_problem();


int get_random(int a, int b) {
	return rand() % (b - a + 1) + a;
}

string generate_brain_trainer(int amount) {
	if (amount <= 0) {
		return MISTAKE_MSG;
	}

		int start_time = time(0);
	double mistakes = 0;


	for (int i = 0; i < amount; i++)
	{
		system("cls");
		int problem;
		bool problem_type = get_random(0, 1);

		if (problem_type) {
			problem = generate_first_type_problem();
		}
		else {
			problem = generate_second_type_problem();
		}

		int a = problem / 100;
		int b = (problem / 10) % 10;
		int c = problem % 10;

	mistake:
		cout << a << (problem_type ? " - " : " + ") << b
			<< (problem_type ? " + " : " - ") << c << endl;

		int right_answer = problem_type ? a - b + c
			: a + b - c;

		int user_input;

		cin >> user_input;

		if (user_input != right_answer) {
			mistakes++;
			cout << MISTAKE_MSG;
			goto mistake;
		}
	}

	int duration = time(0) - start_time;



	int accuracy_percentage = (1.0 - mistakes / amount) * 100;


	string msg;
	if (accuracy_percentage >= 95) {
		msg = get_random(0, 1) ? "Genius! " : "Amazing!!! ";
	}

	if (accuracy_percentage >= 85 && accuracy_percentage < 95) {
		msg = get_random(0, 1) ? "Great job!" : "Well-done! ";
	}

	if (accuracy_percentage >= 70 && accuracy_percentage < 85) {
		msg = "Not bad. ";
	}

	if (accuracy_percentage >= 50 && accuracy_percentage < 70) {
		msg = "OK, but could be better. ";
	}

	if (accuracy_percentage < 50) {
		msg = "The result does not meet expectations.";
	}

	msg += "Your accuracy is " + to_string(accuracy_percentage) + "%.\n";

	msg += "Your time: " + to_string(duration / 60) + ":" + to_string(duration % 60) + ".\nIt is about " + to_string(duration / amount) + " second per task.";



	return msg;
}

int generate_first_type_problem() { //a-b+c

	int a, b, c;

	a = get_random(2, 9);

	do {
		b = get_random(1, a - 1);
	} while (b >= a);

	c = get_random(1, 9);


	int numbers = a * 100 + b * 10 + c;
	return numbers;
}

int generate_second_type_problem() { //a+b-c
	int a, b, c;


	a = get_random(1, 9);

	do {
		b = get_random(1, 9);
	} while (b == a);

	do {
		c = get_random(1, 9);
	} while (c >= (a + b) || c == a || c == b);



	int numbers = a * 100 + b * 10 + c;
	return numbers;

}
