#include "logic.h"
/*		v.1.0
		Azarenok Rodion Maximovich, P13024, 15.02.2025	*/
using namespace std;


int main() {
	int amount;	
	int language_choose;
	setlocale(LC_ALL, "RU-ru");

	system("cls");
	cout << "Choose language / Выберите язык (0-RUS, 1-ENG): ";
	
	cin >> language_choose;

	if (language_choose != 0 && language_choose != 1) {
		main();
	}

	string INPUT_AMOUNT;
	string PLAY_AGAIN;

	if (language_choose) {
		INPUT_AMOUNT = "Input amount of problems to solve: ";
		PLAY_AGAIN = "\nIf you want to play again input 1, or any other symbol to exit:\n";
	}
	else {
		INPUT_AMOUNT = "Введите количество примеров для решения: ";
		PLAY_AGAIN = "Если хотите сыграть ещё раз, введите 1, или любой другой символ чтобы выйти: ";
	}


	cout << INPUT_AMOUNT;
	cin >> amount;

	system("pause");

	system("cls");

	cout << generate_brain_trainer(amount, language_choose ? 'E' : 'R');

	cout << PLAY_AGAIN;

	int choice;
	cin >> choice;

	if (choice == 1) {
		main();
	}

	return 0;
}