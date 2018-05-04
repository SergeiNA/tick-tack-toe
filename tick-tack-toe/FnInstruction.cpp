#include"Sinfo.h"
#include "Fnttt.h"
#include <iostream>
#include <conio.h>
using namespace std;
void instruction(info* ginf) {
	cout << "instruction\n";
	cout << "type of field:\n";
	int l = 0;
	for (int i(0); i<sz; i++) {
		for (int j(0); j<sz; j++) {
			cout << "| " << l + 1 << ' ';
			ginf->table[i][j] = char(49 + l);
			l++;
		}
		cout << '|' << endl;
	}
	cout << "Press any key to start ";
	_getch();
}