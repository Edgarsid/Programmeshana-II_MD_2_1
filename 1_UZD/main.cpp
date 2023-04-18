#include <iostream>
#include <string>
#include "character.h"
#include "hero.h"
#include "monster.h"
#include "boss.h"

using namespace std;

int main()
{
	// 3 charakteri
	Hero A ("Anakin", 5, 0);
	Monster B ("Boba", 3, 5);
	Boss D ("Darth", 3, 4, 5);
	
	// printeeshana pirms kautinja
	A.Print();
	B.Print();
	D.Print();
	
	cout << endl << endl;
	
	A.Kill(B);  // Hero nogalina monstru
	D.Eat(A);	// Boss apeed hero
	
	
	// printeeshana peec kautinja
	A.Print();
	B.Print();
	D.Print();
	
	system("pause");
	return 0;
}
