#include "logic.h"

void create_problem(int& a, int& b, int& c, int type);
string get_feedback_by_accuracy(int accuracy_percentage, char lang);
string get_feedback_by_time(double time_per_task, char lang);

int get_random(int a, int b) {
	return rand() % (b - a + 1) + a;
}

string generate_brain_trainer(int amount, char lang, int max_mistakes) {
	srand(time(0));
	string mistake_msg;
	string your_accuracy;
	string your_time;
	string its_about;
	string seconds_per_task;
	string tasks_amount;
	string skip_task;

	if (lang == 'E') {
		mistake_msg = "A mistake was made. Try again!\n";
		your_accuracy = "Your accuracy is ";
		your_time = "Your time: ";
		its_about = ".\nIt is about ";
		seconds_per_task = " second per task.";
		tasks_amount = " Total amount: ";
		skip_task = "Skip!";

	}
	else {
		mistake_msg = "Ошибка! Попробуй ещё раз.\n";
		your_accuracy = "Ваша точность составила ";
		your_time = "Ваше время: ";
		its_about = ".\nЭто порядка ";
		seconds_per_task = " секунд на пример.";
		tasks_amount = " Всего примеров: ";
		skip_task = "Пропустим.";
	}

	if (amount <= 0) {
		return mistake_msg;
	}

	int start_time = time(0);
	double mistakes = 0;

	for (int i = 0; i < amount; i++)
	{
		bool mistake_made_before = false;
		int mistakes_in_one_task = 0;
		int problem_type = get_random(1, 2);

		int a, b, c;
		create_problem(a, b, c, problem_type);

		while (true) {
			cout << "\n" << a << (problem_type ? " - " : " + ") << b
				<< (problem_type ? " + " : " - ") << c << " = ";

			int right_answer = problem_type ? a - b + c : a + b - c;

			int user_input;
			cin >> user_input;

			if (user_input == right_answer) {
				break;
			}

			mistakes_in_one_task++;

			if (mistakes_in_one_task > max_mistakes) {
				cout << skip_task;
				break;
			}

			if (!mistake_made_before) {
				mistake_made_before = true;
				mistakes += 1;
			}

			cout << mistake_msg;
		}
	}

	int duration = time(0) - start_time;

	system("cls");

	int minutes = duration / 60;
	int seconds = duration % 60;

	string formatted_time = (minutes < 10 ? "0" + to_string(minutes) : to_string(minutes)) + ":" +
		(seconds < 10 ? "0" + to_string(seconds) : to_string(seconds));


	int accuracy_percentage = (1.0 - mistakes / amount) * 100;

	string msg = get_feedback_by_accuracy(accuracy_percentage, lang);
	msg += get_feedback_by_time(duration / amount, lang);

	msg += your_accuracy + to_string(accuracy_percentage) + "%.\n";
	msg += your_time + formatted_time + its_about + to_string(duration / amount) + seconds_per_task;
	msg += tasks_amount + to_string(amount) + "\n";

	return msg;
}

string get_feedback_by_accuracy(int accuracy_percentage, char lang) {
	string feedbacks[8];
	if (lang == 'E') {
		feedbacks[0] = "Genius! ";
		feedbacks[1] = "Amazing! ";
		feedbacks[2] = "Great job! ";
		feedbacks[3] = "Well-done! ";
		feedbacks[4] = "Not bad ";
		feedbacks[5] = "OK. ";
		feedbacks[6] = "The result doesn't meet our expectations. ";
		feedbacks[7] = "Failed to get feedback. ";
	}
	else {
		feedbacks[0] = "Гений! ";
		feedbacks[1] = "Потрясающе! ";
		feedbacks[2] = "Отличная работа. ";
		feedbacks[3] = "Очень хорошо. ";
		feedbacks[4] = "Неплохо. ";
		feedbacks[5] = "Удовлетворительно. ";
		feedbacks[6] = "Результаты не соответствуют ожиданиям. ";
		feedbacks[6] = "Результаты не соответствуют ожиданиям. ";
		feedbacks[7] = "Ошибка при получении обратной связи. ";
	}

	string output;
	if (accuracy_percentage >= 95) {
		output = get_random(0, 1) ? feedbacks[0] : feedbacks[1];
	}
	else if (accuracy_percentage >= 85) {
		output = get_random(0, 1) ? feedbacks[2] : feedbacks[3];
	}
	else if (accuracy_percentage >= 70) {
		output = feedbacks[4];
	}
	else if (accuracy_percentage >= 50) {
		output = feedbacks[5];
	}
	else if (accuracy_percentage >= 0) {
		output = feedbacks[6];
	}

	else {
		output = feedbacks[7];
	}

	return output;
}

string get_feedback_by_time(double time_per_task, char lang) {
	string feedbacks[6];
	string output;
	if (lang == 'E') {
		feedbacks[0] = "Best time! ";
		feedbacks[1] = "Excellent time! ";
		feedbacks[2] = "Good time! ";
		feedbacks[3] = "Not bad time! ";
		feedbacks[4] = "Normal time. ";
		feedbacks[5] = "Poor time. ";
	}
	else {
		feedbacks[0] = "Лучшее время! ";
		feedbacks[1] = "Отличное время! ";
		feedbacks[2] = "Хорошее время! ";
		feedbacks[3] = "Неплохое время! ";
		feedbacks[4] = "Нормальное время. ";
		feedbacks[5] = "Не очень. ";
	}

	if (time_per_task <= 2.0) {
		output = feedbacks[0];
	}
	else if (time_per_task > 2.0 && time_per_task <= 2.3) {
		output = feedbacks[1];
	}
	else if (time_per_task > 2.3 && time_per_task <= 2.5) {
		output = feedbacks[2];
	}
	else if (time_per_task > 2.5 && time_per_task <= 2.7) {
		output = feedbacks[3];
	}
	else if (time_per_task > 2.7 && time_per_task <= 3.0) {
		output = feedbacks[4];
	}
	else {
		output = feedbacks[5];
	}

	return output;
}

void create_problem(int& a, int& b, int& c, int type) {
	if (type == 1) {
		do {
			a = get_random(2, 9);
			b = get_random(1, a - 1);
			c = get_random(1, 9);
		} while (b >= a || b == c);
	}
	else {
		do {
			a = get_random(1, 9);
			b = get_random(1, 9);
			c = get_random(1, 9);
		} while (c >= a + b || c == a || c == b);
	}
}

