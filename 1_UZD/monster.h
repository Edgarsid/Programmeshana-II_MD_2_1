#ifndef MONSTER_H
#define MONSTER_H
#include <cstring>

#include "character.h"


using namespace std;

class Monster : public Character	// atvasinajums
{
public:
	friend class Hero;   // lai Hero vareetu piekljuut monstra mainigajiem
	Monster(string, int, int);
	int Getlevel();
	void Print();
protected:				// nepiecieshamie lauki										
	int level;
};





#endif
