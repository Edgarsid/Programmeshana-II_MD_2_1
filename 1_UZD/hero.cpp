#include <iostream>
#include <cstring>
#include "hero.h"
#include "character.h"
#include "monster.h"


using namespace std;

Hero::Hero(string n, int l, int e)   : Character(n, l)	// kontruktors							
{
	experience = e;
}

void Hero::Kill (Monster &k)   // objekts kaa parametrs, ar &, lai mainiitu monstra dziiviibas
{
	experience = k.Getlevel() * k.GetLife();   // piekljuust Monstra levelim un dziiviibai
	k.life =0;                                 // nomaina dziivibas uz 0 = nogalina
}

void Hero::Print()
{
	PrintCharacter();
	cout << "Experience: " << experience << endl;
}
