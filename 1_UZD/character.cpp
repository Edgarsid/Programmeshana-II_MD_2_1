#include <iostream>
#include <cstring>
#include "character.h"

int s = 0;   // globalais solju skaitiitais. Globals, lai solju skaitiishana nesakas pa jauno, katru reizi palaizhot metodi Go

using namespace std;


Character::Character(string n, int l) 	// kontruktors							
{
	if(l < 1)   // var izveidot tikai dziivu. Ja izveido "mirushu", tad pieshkjir vienu dziivi
	{
		cout << "Character can be made only alive / lives set to 1" << endl;
		life = 1;
	}
		
	else  // ja viss kaartiibaa un izveido character dziivu
	{
		name = n;
		life = l;
	}
}

bool Character::Hit (int h)			// metode dziives samazinaashanai	
{
	if(life > 0)   // ja character dziivs
	{
		life -= h;   // samazina dziivi par ierakstiitu veertiibu
		if(life > 0)
			return true;  // atgriezh true, ja personazhs dziivs
		else
			return false;	// atgriez false, ja miris
	}	
	else
	{
		return false;    // atgriezh false, ja jau miris
	}		
}

int Character::GetLife()    // fmetode atgriezh dziivi
{
	return life;
}

void Character::Go(char p)   // metode go
{
	if(life > 0)   // strada, ja personazhs dziivs
	{
		if(p == 'l' || p == 'r' || p == 't' || p == 'b')  // paarbaude uz korektumu
		{
			if(s < 10)   // ja solju skaits ir zem 10
			{
				path[s] = p;   // pieshkjir soli
				s++;   // pieskaita soli
			}
			else   // ja solju skaits vairak par 10
			{
				for(int i = 1; i < 10; i++)  // cikls pabiidiitu solja vertiibu uz atpakalju, 10 kljust 9 / 1 pazud
				{
					path[i- 1] = path[i];
				}
				path[9] = p;  // pieliek 10 soli.  it [9], jo masiivs saakas ar 0
			}
		}
	}
}

void Character::PrintCharacter()  // metode drukaashanai
{
	if(life > 0)   // ja character ir dziivs
	{
		cout << name << " Alive, " << "lives left: "<< life << endl;
		cout << "Last 10 steps: ";   // izdrukas dati
		for(int i = 0; i < 10; i++)   // cikls lai izdrukatu pedejos 10 soljus.
			if(path[i] == 'l' || path[i] == 'r' || path[i] == 't' || path[i] == 'b')
				cout << path[i] << " ";
			else
				cout << "-" << " ";   // ja 10 solji netiek aizpilditi, tie tiek izdrukati kaa " - "
	}		
	else   // ja character ir miris
	{
		cout << name << " Dead " << endl;
		cout << "Last 10 steps: ";   // informacija izdrukai
		for(int i = 0; i < 10; i++)   // cikls lai izdrukatu pedejos 10 soljus.
			if(path[i] == 'l' || path[i] == 'r' || path[i] == 't' || path[i] == 'b')
				cout << path[i] << " ";
			else
				cout << "-" << " ";
	}	
	cout << endl;
}

Character::~Character()   // destruktors.  
{
	if(life < 0)   // Ja personazhs ir miris, tad tam izdrukaa Game over
	cout << "Game over for " << name << endl;
}
