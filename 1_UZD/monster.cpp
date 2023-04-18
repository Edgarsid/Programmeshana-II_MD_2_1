#include <iostream>
#include <cstring>
#include "monster.h"
#include "character.h"

using namespace std;

Monster::Monster(string n, int l, int lev)  : Character(n, l)		// kontruktors							
{
	level = lev;
}

int Monster::Getlevel()
{
	return level;
}

void Monster::Print()
{
	PrintCharacter();
	cout << "Level: " << level << endl;
}
