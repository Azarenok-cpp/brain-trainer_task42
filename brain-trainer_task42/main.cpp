#include <iostream>
#include "logic.h"
using namespace std;
/*		v.1.0
		Azarenok Rodion Maximovich, P13024, 15.02.2025	*/
int generate_first_type_problem();
int generate_second_type_problem();


int main() {
	srand(time(0));
	/*for (int i = 0; i < 10; i++)
	{
		int result = generate_first_type_problem();
		cout << result / 100 << " - " << (result / 10) % 10 << " + " << result % 10 << endl;
	}
	cout << "\n\n";

	for (int i = 0; i < 10; i++)
	{
		int result = generate_second_type_problem();
		cout << result / 100 << " + " << (result / 10) % 10 << " - " << result % 10 << endl;
	}*/
	int amount;
	cout << "Wanna keep your mind sharp? Input amount of problems to solve: ";
	cin >> amount;
	cout << "When you are ready ";

	system("pause");
	system("cls");

	cout << generate_brain_trainer(amount);

	return 0;
}