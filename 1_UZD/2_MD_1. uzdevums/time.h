#ifndef TIME_H
#define TIME_H
#include <cstring>


using namespace std;

class Time		    // klase time								
{
	friend ostream &operator<<(ostream &, const Time &); // laika izvade
   	friend istream &operator>>(istream &, Time &);   // laika ievade
public:							
   	Time();
	Time &operator=(const Time &);		
   	Time operator++(); //prefiksa (++x) sekunde
   	Time operator++(int); //postfiksa (x++) minute
   	Time operator--(); //prefiksa (--x) sekunde
   	Time operator--(int); //postfiksa (x--) minute
	bool operator==(const Time &) const;	
	bool operator!=(const Time &) const;	
	bool operator>(const Time &) const;	
	bool operator<(const Time &) const;
	bool operator>=(const Time &) const;	
	bool operator<=(const Time &) const;		

private:												
	int second;
	int minute;
	int hour;
};

#endif
