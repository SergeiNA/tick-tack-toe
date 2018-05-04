#include <iostream>
#include <conio.h>
#include <random>
#include <time.h>
#include "Sinfo.h"
#include "Fnttt.h"
using namespace std;
void main() {
	setlocale(LC_ALL, "Russian");

	info* ginf = new info;
	instruction(ginf);

	system("cls");

	int cont = 0;
	bool dr = true;

	cout << "Enter the 1st player name: ";
	cin.getline(ginf->name1, 30);
	cout << "Enter the 2nd player name: ";
	cin.getline(ginf->name2, 30);

	srand(time(NULL));
	if (rand() & 1)
		ginf->step = true;
	else ginf->step = false;



	while (!(win(ginf)) && dr) {
		system("cls");
		if (!input(ginf)) {
			cout << "Incorrect data? repeat!\n";
			_getch();
		}
		if (cont >= 8) {
			dr = false;
		}
	}

	system("cls");
	if (!dr) {
		cout << "Draw!\n";
		_getch;
	}
	else if (ginf->step)
		cout << ginf->name2 << " win!" << endl;
	else cout << ginf->name1 << " win!" << endl;
	delete ginf;
	system("pause");
}