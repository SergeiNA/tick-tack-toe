#include <iostream>
#include <conio.h>
#include <random>
#include <time.h>
using namespace std;

char name1[30];
char name2[30];
char table[3][3];
bool step;

void instruction() {
	cout << "instruction\n";
	cout << "type of field:\n";
	int l = 0;
	for (int i(0); i<3; i++) {
		for (int j(0); j<3; j++) {
			cout << "| " << l + 1 << ' ';
			table[i][j] = char(49 + l);
			l++;
		}
		cout << '|' << endl;
	}
	cout << "Press any key to start ";
	_getch();
}

bool input() {
	for (int i(0); i < 3; i++) {
		for (int j(0); j<3; j++) {
			cout << "| " << table[i][j] << ' ';
		}
		cout << '|' << endl;
	}
	cout << endl;
	if (step)
		cout << name1 << " turn: ";
	else cout << name2 << " turn: ";

	int n;
	cin >> n;
	if (n < 1 || n>9)
		return false;
	int i, j;
	if (n % 3 == 0) {
		i = n / 3 - 1;
		j = 2;
	}
	else {
		j = n % 3 - 1;
		i = n / 3;
	}

	if (table[i][j] == 'O' || table[i][j] == 'X')
		return false;
	if (step) {
		table[i][j] = 'X';
		step = false;
	}
	else { table[i][j] = 'O'; step = true; }
	return true;

}

bool win() {
	for (int i(0); i<3; i++)
		if ((table[i][0] == table[i][1]) && (table[i][0] == table[i][2]))
			return true;
		else if ((table[0][i] == table[1][i]) && (table[0][i] == table[2][i]))
			return true;
		else if ((table[0][0] == table[1][1] && table[0][0] == table[2][2]) || (table[0][2] == table[1][1] && table[0][2] == table[2][0]))
			return true;
	return false;
}


void main() {
	setlocale(LC_ALL, "Russian");

	int cont = 0;
	bool dr = true;
	instruction();
	system("cls");

	cout << "Enter the 1st player name: ";
	cin.getline(name1, 30);
	cout << "Enter the 2nd player name: ";
	cin.getline(name2, 30);
	srand(time(NULL));
	if (rand() & 1)
		step = true;
	else step = false;
	while (!(win())&&dr) {
		system("cls");
		if (!input()) {
			cout << "Incorrect data! repeat!\n";
			_getch();
		}
		if (cont >= 8) {
			dr = false;
		}
		cont++;
	}
	system("cls");
	if (!dr) {
		cout << "Draw!\n";
		_getch;
	}
	else if (step)
			cout << name2 << " win!" << endl;
		else cout << name1<< " win!" << endl;

	system("pause");
}