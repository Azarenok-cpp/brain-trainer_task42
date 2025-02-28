#include "logic.h"
/*		v.1.0
		Azarenok Rodion Maximovich, P13024, 15.02.2025	*/
using namespace std;


int main() {
	int amount;	
	int language_choose;

	system("cls");
	cout << "Choose language / Выберите язык (0-RUS, 1-ENG): ";
	
	cin >> language_choose;

	if (language_choose != 0 && language_choose != 1) {
		main();
	}

	const string INPUT_AMOUNT = language_choose ? "Input amount of problems to solve: " : "Введите количество примеров для решения: ";
	const string PLAY_AGAIN = language_choose ? "\nIf you want to play again input 1, or any other symbol to exit:\n" 
		: "Если хотите сыграть ещё раз, введите 1, или любой другой символ чтобы выйти: ";

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