#include "logic.h"

int generate_first_type_problem();
int generate_second_type_problem();
string get_feedback(int accuracy_percentage, double duration, char lang);

int get_random(int a, int b) {
	return rand() % (b - a + 1) + a;
}

string generate_brain_trainer(int amount, char lang) {
	srand(time(0));
	string MISTAKE_MSG;
	string YOUR_ACCURACY;
	string YOUR_TIME;
	string ITS_ABOUT;
	string SECONDS_PER_TASK;

	if (lang == 'E') {
		MISTAKE_MSG = "A mistake was made. Try again!\n";
		YOUR_ACCURACY = "Your accuracy is ";
		YOUR_TIME = "Your time: ";
		ITS_ABOUT = ".\nIt is about ";
		SECONDS_PER_TASK = " second per task.";
	}
	else {
		MISTAKE_MSG = "Ошибка! Попробуй ещё раз.\n";
		YOUR_ACCURACY = "Ваша точность составила ";
		YOUR_TIME = "Ваше время: ";
		ITS_ABOUT = ".\n Это порядка ";
		SECONDS_PER_TASK = " секунд на пример.";
	}

	if (amount <= 0) {
		return MISTAKE_MSG;
	}

	int start_time = time(0);
	double mistakes = 0;

	for (int i = 0; i < amount; i++)
	{
		system("cls");
		bool mistake_made_before = false;
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

		while (true) {
			cout << a << (problem_type ? " - " : " + ") << b
				<< (problem_type ? " + " : " - ") << c << endl;

			int right_answer = problem_type ? a - b + c : a + b - c;

			int user_input;
			cin >> user_input;

			if (user_input != right_answer) {
				mistakes += mistake_made_before ? 0 : 1;
				cout << MISTAKE_MSG;
				continue; 
			}

			break;
		}
	}

	system("cls");

	int duration = time(0) - start_time;

	int minutes = duration / 60;
	int seconds = duration % 60;

	string formatted_time = (minutes < 10 ? "0" + to_string(minutes) : to_string(minutes)) + ":" +
		(seconds < 10 ? "0" + to_string(seconds) : to_string(seconds));

	int accuracy_percentage = (1.0 - mistakes / amount) * 100;

	string msg = get_feedback(accuracy_percentage, duration / amount, lang);

	msg += YOUR_ACCURACY + to_string(accuracy_percentage) + "%.\n";
	msg += YOUR_TIME + formatted_time + ITS_ABOUT + to_string(duration / amount) + SECONDS_PER_TASK;

	return msg;
}

string get_feedback(int accuracy_percentage, double time_per_task, char lang) {
	string GENIUS, AMAZING, GR_JOB, WELL_DONE, NOT_BAD, OK, DOESNT_MEET_EXPECTATIONS, ERROR;
	string TIME_BEST, TIME_EXCELLENT, TIME_GOOD, TIME_NOT_BAD, TIME_NORMAL, TIME_POOR;

	if (lang == 'E') {
		GENIUS = "Genius! ";
		AMAZING = "Amazing! ";
		GR_JOB = "Great job! ";
		WELL_DONE = "Well-done! ";
		NOT_BAD = "Not bad ";
		OK = "OK. ";
		DOESNT_MEET_EXPECTATIONS = "The result doesn't meet our expectations. ";
		ERROR = "Failed to get feedback. ";
		TIME_BEST = "Best time! ";
		TIME_EXCELLENT = "Excellent time! ";
		TIME_GOOD = "Good time! ";
		TIME_NOT_BAD = "Not bad time! ";
		TIME_NORMAL = "Normal time. ";
		TIME_POOR = "Poor time. ";
	}
	else {
		GENIUS = "Гений! ";
		AMAZING = "Потрясающе! ";
		GR_JOB = "Отличная работа. ";
		WELL_DONE = "Очень хорошо. ";
		NOT_BAD = "Неплохо. ";
		OK = "Удовлетворительно. ";
		DOESNT_MEET_EXPECTATIONS = "Результаты не соответствуют ожиданиям. ";
		ERROR = "Ошибка при получении обратной связи. ";
		TIME_BEST = "Лучшее время! ";
		TIME_EXCELLENT = "Отличное время! ";
		TIME_GOOD = "Хорошее время! ";
		TIME_NOT_BAD = "Неплохое время! ";
		TIME_NORMAL = "Нормальное время. ";
		TIME_POOR = "Не очень. ";
	}

	string feedback;
	if (accuracy_percentage >= 95) {
		feedback = get_random(0, 1) ? GENIUS : AMAZING;
	}
	else if (accuracy_percentage >= 85) {
		feedback = get_random(0, 1) ? GR_JOB : WELL_DONE;
	}
	else if (accuracy_percentage >= 70) {
		feedback = NOT_BAD;
	}
	else if (accuracy_percentage >= 50) {
		feedback = OK;
	}
	else {
		feedback = DOESNT_MEET_EXPECTATIONS;
	}

	if (time_per_task <= 2.0) {
		feedback += TIME_BEST;
	}
	else if (time_per_task > 2.0 && time_per_task <= 2.3) {
		feedback += TIME_EXCELLENT;
	}
	else if (time_per_task > 2.3 && time_per_task <= 2.5) {
		feedback += TIME_GOOD;
	}
	else if (time_per_task > 2.5 && time_per_task <= 2.7) {
		feedback += TIME_NOT_BAD;
	}
	else if (time_per_task > 2.7 && time_per_task <= 3.0) {
		feedback += TIME_NORMAL;
	}
	else {
		feedback += TIME_POOR;
	}

	return feedback;
}

int generate_first_type_problem() { //a-b+c
	int a, b, c;

	do {
		a = get_random(2, 9);
		b = get_random(1, a - 1);
		c = get_random(1, 9);
	} while (b >= a || b == c);

	return a * 100 + b * 10 + c;
}

int generate_second_type_problem() { //a+b-c
	int a, b, c;

	do {
		a = get_random(1, 9);
		b = get_random(1, 9);
		c = get_random(1, 9);
	} while (c >= a + b || c == a || c == b);

	return a * 100 + b * 10 + c;
}
