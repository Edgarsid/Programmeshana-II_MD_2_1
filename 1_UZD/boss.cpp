#include <iostream>
#include <cstring>
#include "boss.h"
#include "hero.h"


using namespace std;

Boss::Boss(string n, int l, int lev, int h)  : Monster(n, l, lev)		// kontruktors							
{
	heads = h;
}

int Boss::GetHeads()
{
	return heads;
}

void Boss::Eat (Hero &e)    // & lai piekljuutu Hero mainiigajiem
{
	heads +=1;              // + viena galva
	life += e.GetLife();    // dziivibas palielinaas par Hero dziiviibamm
	e.life = 0;            // Hero nomirst
} 

void Boss::Print()
{
	PrintCharacter();
	cout << "Heads: " << heads << endl;
}
