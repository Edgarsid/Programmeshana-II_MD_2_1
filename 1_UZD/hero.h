#ifndef HERO_H
#define HERO_H
#include <cstring>

#include "character.h"
#include "monster.h"


using namespace std;

class Hero : public Character   // atvasinajums
{
public:
	Hero(string, int, int);
	void Kill(Monster &);   // & ir reference, lai var mainiit monstra dziiviibas
	void Print();
protected:				// nepiecieshamie lauki										
	int experience;
};





#endif
