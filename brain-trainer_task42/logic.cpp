#include "logic.h"

int generate_first_type_problem();
int generate_second_type_problem();

int get_random(int a, int b) {
	return rand() % (b - a + 1) + a;
}
string get_feedback_from_accuracy(int accuracy_percentage, char lang);

string generate_brain_trainer(int amount, char lang) {
	const string MISTAKE_MSG = lang == 'E' ? "A mistake was made. Try again!\n" : "Ошибка! Попробуй ещё раз.\n";
	const string YOUR_ACCURACY = lang == 'E' ? "Your accuracy is " : "Ваша точность составила ";
	const string YOUR_TIME = lang == 'E' ? "Your time: " : "Ваше время: ";
	const string ITS_ABOUT = lang == 'E' ? ".\nIt is about " : ".\n Это порядка ";
	const string SECONDS_P_TASK = lang == 'E' ? " second per task." : " секунд на пример.";


	srand(time(0));

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
	system("cls");

	int duration = time(0) - start_time;

	int minutes = duration / 60;
	int seconds = duration % 60;

	string time = (minutes < 10 ? "0" + to_string(minutes) : to_string(minutes)) + ":" +
		(seconds < 10 ? "0" + to_string(seconds) : to_string(seconds));

	int accuracy_percentage = (1.0 - mistakes / amount) * 100;

	string msg = get_feedback_from_accuracy(accuracy_percentage, lang);

	msg += YOUR_ACCURACY + to_string(accuracy_percentage) + "%.\n";
	msg += YOUR_TIME + time + ITS_ABOUT + to_string(duration / amount) + SECONDS_P_TASK;



	return msg;
}

string get_feedback_from_accuracy(int accuracy_percentage, char lang) {
	const string GENIUS = lang == 'E' ? "Genius! " : "Гений! ";
	const string AMAZING = lang == 'E' ? "Amazing! " : "Потрясающе! ";
	const string GR_JOB = lang == 'E' ? "Great job! " : "Отличная работа. ";
	const string WELL_DONE = lang == 'E' ? "Well-done! " : "Очень хорошо. ";
	const string NOT_BAD = lang == 'E' ? "Not bad " : "Неплохо. ";
	const string OK = lang == 'E' ? "OK. " : "Удовлитворительно. ";
	const string DOESNT_MEET_EXPECTATIONS = lang == 'E' ? "The result doesn't meet our expectations. " : "Результаты не соответствуют ожиданиям. ";
	const string ERROR = lang == 'E' ? "Failed to get feedback. " : "Ошибка при получении обратной связи. ";

	if (accuracy_percentage >= 95) {
		return get_random(0, 1) ? GENIUS : AMAZING;
	}
	if (accuracy_percentage >= 85 && accuracy_percentage < 95) {
		return get_random(0, 1) ? GR_JOB : WELL_DONE;
	}
	if (accuracy_percentage >= 70 && accuracy_percentage < 85) {
		return NOT_BAD;
	}
	if (accuracy_percentage >= 50 && accuracy_percentage < 70) {
		return OK;
	}
	if (accuracy_percentage < 50) {
		return DOESNT_MEET_EXPECTATIONS;
	}
	return ERROR;
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
