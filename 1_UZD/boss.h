#ifndef BOSS_H
#define BOSS_H
#include <cstring>
# include "hero.h"
#include "monster.h"


using namespace std;

class Boss : public Monster   // atvasinaajums
{
public:
	Boss(string, int, int, int);
	int GetHeads();
	void Eat(Hero &);    // & lai piekljuutu Hero mainiigajiem
	void Print();
protected:				// nepiecieshamie lauki										
	int heads;
};





#endif
