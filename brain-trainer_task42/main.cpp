#include <iostream>
#include "logic.h"
using namespace std;
/*		v.1.0
		Azarenok Rodion Maximovich, P13024, 15.02.2025	*/
int* generate_first_type_problem();

int main() {
	srand(time(0));
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << generate_first_type_problem()[j] << " ";
		}
		cout << "\n";
	}
	return 0;
}