#include <iostream>
#include <string>
#include "time.h"

using namespace std;

int main()
{
	
	Time t, t2; 
	
	cout << "Noklusejuma laiks " << endl << t << endl;
	
	cout << "Ievadiet laiku, stundas, minutes, sekundes:" << endl;
   	cin >> t;   // laika ievade
   	t2 = t;     // laika pieshkjirshana
   	cout << t << endl;     // izvade
   	cout << t2 << endl;
   	
   	//  metozhu demonstracija:
	++t;
	cout << t << endl;
	t++;
	cout << t << endl;
	t--;
	cout << t << endl;
	--t;
	cout << t << endl;
	
	cout << (t == t2) << endl;
	cout << (t != t2) << endl;
	cout << (t > t2) << endl;
	cout << (t < t2) << endl;
	cout << (t >= t2) << endl;
	cout << (t <= t2) << endl;
	
	system("pause");
	return 0;
}
