#include <iostream>
#include "Sinfo.h"
#include "Fnttt.h"
using namespace std;

bool input(info* ginf) {
	for (int i(0); i < sz;i++) {
		for(int j(0);j<sz;j++){
			cout << "| " << ginf->table[i][j] << ' ';
		}
		cout << '|' << endl;
	}
	cout << endl;
	if (ginf->step)
		cout << ginf->name1 << " turn: ";
	else cout << ginf->name2 << " turn: ";

	int n;
	cin >> n;
	if (n < 1 || n>9)
		return false;
	int i, j;
	if (n % sz == 0) {
		i = n / sz - 1;
			j = 2;
	}
	else {
		j = n % 3 - 1;
		i = n / 3;
	}

	if (ginf->table[i][j] == 'O' || ginf->table[i][j] == 'X')
		return false;
	if (ginf->step) {
		ginf->table[i][j] = 'X';
		ginf->step = false;
	}
	else { ginf->table[i][j] = 'O'; ginf->step = true; }
	return true;

}

