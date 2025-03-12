#include "logic.h"
/*		v.2.2
		Azarenok Rodion Maximovich, P13024, 15.02.2025 — 09.03.2025*/
using namespace std;


int main() {
	int amount;	
	int language_choose;
	int max_mistakes;
	setlocale(LC_ALL, "RU-ru");

	while (true) {
		system("cls");
		cout << "Choose language / Выберите язык (0-RUS, 1-ENG): ";

		cin >> language_choose;

		if (language_choose != 0 && language_choose != 1) {
			cout << "User unput invalid!";
		}

		string input_amount;
		string play_again;
		string maximum_mistakes_allowed;

		if (language_choose) {
			input_amount = "Input amount of problems to solve: ";
			play_again = "\nIf you want to play again input 1, or any other number to exit:\n";
			maximum_mistakes_allowed = "Maximal amount of incorrect answers per one task: ";
		}
		else {
			input_amount = "Введите количество примеров для решения: ";
			play_again = "Если хотите сыграть ещё раз, введите 1, или любое другое число чтобы выйти: ";
			maximum_mistakes_allowed = "Максимальное количество неправильных ответов на один пример: ";
		}

		cout << input_amount;
		cin >> amount;
		cout << maximum_mistakes_allowed;
		cin >> max_mistakes;

		system("pause");

		system("cls");

		cout << generate_brain_trainer(amount, language_choose ? 'E' : 'R', max_mistakes);

		cout << play_again;

		int choice;
		cin >> choice;

		if (choice != 1) {
			break;
		}

		
	}
	return 0;
}