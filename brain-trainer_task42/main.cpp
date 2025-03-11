#include "logic.h"
/*		v.2.2
		Azarenok Rodion Maximovich, P13024, 15.02.2025 — 09.03.2025*/
using namespace std;


int main() {
	int amount;	
	int language_choose;
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

		if (language_choose) {
			input_amount = "Input amount of problems to solve: ";
			play_again = "\nIf you want to play again input 1, or any other number to exit:\n";
		}
		else {
			input_amount = "Введите количество примеров для решения: ";
			play_again = "Если хотите сыграть ещё раз, введите 1, или любое другое число чтобы выйти: ";
		}

		cout << input_amount;
		cin >> amount;

		system("pause");

		system("cls");

		cout << generate_brain_trainer(amount, language_choose ? 'E' : 'R');

		cout << play_again;

		int choice;
		cin >> choice;

		if (choice != 1) {
			break;
		}

		
	}
	return 0;
}