#include <iostream>
#include "logic.h"
using namespace std;
/*		v.1.0
		Azarenok Rodion Maximovich, P13024, 15.02.2025	*/

int main() {
	int amount;
	cout << "Input amount of problems: ";
	cin >> amount;

	generate_brain_trainer(amount);

	

	return 0;
}