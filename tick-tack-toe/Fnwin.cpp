#include"Sinfo.h"
#include "Fnttt.h"
bool win(info* ginf) {
	for (int i(0); i<sz; i++)
		if ((ginf->table[i][0] == ginf->table[i][1]) && (ginf->table[i][0] == ginf->table[i][2]))
			return true;
		else if ((ginf->table[0][i] == ginf->table[1][i]) && (ginf->table[0][i] == ginf->table[2][i]))
			return true;
		else if ((ginf->table[0][0] == ginf->table[1][1] && ginf->table[0][0] == ginf->table[2][2]) || 
			(ginf->table[0][2] == ginf->table[1][1] && ginf->table[0][2] == ginf->table[2][0]))
			return true;
	return false;
}