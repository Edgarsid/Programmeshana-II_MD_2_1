#include <iostream>
#include <cstring>
#include "time.h"

using namespace std;


Time::Time() // noklusejuma vertibas							
{
	second = 0;
	minute = 0;
	hour = 0;
}

ostream &operator<<(ostream &izvade, const Time &i)   // << parslogoshana
{
   izvade << "Laiks ir: "                          // ja ir tikai viens cipars, tad pirmais izvadas kaa 0
   << (i.hour < 10 ? "0" : "") << i.hour << ":" 
   << (i.minute < 10 ? "0" : "") << i.minute << ":" 
   << (i.second < 10 ? "0" : "") << i.second << endl;
   return izvade;
}

istream &operator>>(istream &ievade, Time &i) // >> parslogoshana
{
   	ievade >> i.hour >> i.minute >> i.second; // ja ievada nekorektu laiku, tad tas ir 0
	if(i.hour<=0 || i.hour >=24)
		i.hour = 0;  
  	if(i.minute<=0 || i.minute>=60)
	  	i.minute = 0;
  	if(i.second<=0 || i.second>=60)
		i.second = 0;
   return ievade;
}

Time &Time::operator=(const Time &vienads)  // laika pieshkirshana citam laikam
{
	second = vienads.second;
	minute = vienads.minute;
	hour = vienads.hour;
   	return *this;  // atgriezh shiis funkcijas vertibu
}

Time Time::operator++()  // prefiksa parslogoshana
{
    second++;
    if(second == 60)   // nomaina vertibas, ja sekundes ir 60
    	{
    		second = 0;
    		minute++;
		}
	if(minute == 60)   // nomaina vertibas, ja minutes ir 60
		{
			minute = 0;
			hour++;			
		}
	if(hour == 24)  // nomaina vertibas, ja stundas ir 24
		{
			second = 0;
			minute = 0;
			hour = 0;
		}
    
    return *this;  // atgriezh shis funkcijas vertibu
}

Time Time::operator++(int)  // postfiksa parslogoshana
{
    Time temp = *this;   // pagaidu mainigais vienads ar shis funkcijas vertibu
    minute++;
    	if(minute == 60)  // nomaina vertibas
		{
			minute = 0;
			hour++;			
		}
	if(hour == 24)   // nomaina vertibas
		{
			minute = 0;
			hour = 0;
		}
    return temp;  // atgriezh pagaidu mainigo
}

Time Time::operator--()  // -- prefiksa parslogoshana. Tas pats, kas ar ++ tikai atnjemshana
{
    second--;
    if(second == -1)
    	{
    		second = 59;
    		minute--;
		}
	if(minute == -1)
		{
			minute = 59;
			hour--;			
		}
	if(hour == -1)
		{
			second = 59;
			minute = 59;
			hour = 23;
		}
    
    return *this;
}

Time Time::operator--(int) // -- postfiksa parslogoshana. Tas pats, kas ar ++ tikai atnjemshana
{
    Time temp = *this;
    minute--;
    	if(minute == -1)
		{
			minute = 0;
			hour--;			
		}
	if(hour == -1)
		{
			minute = 59;
			hour = 23;
		}
    return temp;
}

bool Time::operator==(const Time &ir) const // == salidzinashana
{
	if(second == ir.second && minute == ir.minute && hour == ir.hour) // ja visi vienadi, tad
		return true;
	else
		return false;
}

bool Time::operator!=(const Time &ir) const  // != salidzinashana
{
	if(second == ir.second && minute == ir.minute && hour == ir.hour) // ja visi vienadi, tad:
		return false;
	else
		return true;
}

bool Time::operator>(const Time &ir) const  // > salidzinashana
{
	if(hour > ir.hour)  // ja stundas ir lielakas, tad
		return true;
	else if(hour == ir.hour && minute > ir.minute) // ja stundas vienadas un minutes lielakas, tad
		return true;
	else if(hour == ir.hour && minute == ir.minute && second > ir.second) // ja stundas un minutes vienadas un sekundes lielakas, tad:
		return true;
	else
		return false;
}

bool Time::operator<(const Time &ir) const // < salidzinashana. Tas pats, kas ar > tikai preteji
{
	if(hour < ir.hour)
		return true;
	else if(hour == ir.hour && minute < ir.minute)
		return true;
	else if(hour == ir.hour && minute == ir.minute && second < ir.second)
		return true;
	else
		return false;
}

bool Time::operator>=(const Time &ir) const // >= salidzinashana
{
	if(hour > ir.hour)   // ja stundas ir lielakas, tad
		return true;
	else if(hour == ir.hour && minute > ir.minute) // ja stundas vienadas un minutes lielakas, tad
		return true;
	else if(hour == ir.hour && minute == ir.minute && second >= ir.second)  // ja stundas un minutes vienadas un sekundes vienadas vai lielakas, tad:
		return true;
	else
		return false;
}

bool Time::operator<=(const Time &ir) const  // <= salidzinashana. Tas pats, kas ar >= tikai preteji
{
	if(hour < ir.hour)
		return true;
	else if(hour == ir.hour && minute < ir.minute)
		return true;
	else if(hour == ir.hour && minute == ir.minute && second <= ir.second)
		return true;
	else
		return false;
}




