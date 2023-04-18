#ifndef CHARACTER_H
#define CHARACTER_H
#include <cstring>


using namespace std;

class Character		    // klase character									
{
public:	
	friend class Hero;	// lai vareetu dziiviibaam un mainiit taas
	friend class Boss;	// lai vareetu dziiviibaam un mainiit taas			
   	Character(string, int);	// kontruktora metode
  	bool Hit(int);			// Hit metode						
	int GetLife();			// Metode dzives atgrieshanai
	void Go(char);			// Metode Go
	void PrintCharacter();	// Izdrukat datus
	~Character();			// destruktors

protected:				// nepiecieshamie lauki										
	string name;
	int life;
	char path[10];
};

#endif
