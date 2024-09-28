#include <iostream>
#include <iomanip>
using namespace std;

#include "Clock.h"

time::time()
{
	hours = minutes = seconds = 0;
}

void time::settime(int h, int m, int s)
{
	sethours(h);
	setminutes(m);
	setseconds(s);

}

void time::sethours(int h)
{
	hours = (h >= 0 && h < 24) ? h : 0;
}

void time::setminutes(int m)
{
	minutes = (m >= 0 && m < 60) ? m : 0;
}

void time::setseconds(int s)
{
	seconds = (s >= 0 && s < 60) ? s : 0;
}

int time::gethours()
{
	return hours;
}

int time::getminutes()
{
	return minutes;
}

int time::getseconds()
{
	return seconds;
}

void time::nexthours(int hours, int minuntes, int seconds)
{
	int newhours;
	newhours = hours + 1;
	if (newhours = 24)
	{
		newhours = 1;
	}
	cout << newhours << minutes << seconds;
}
void time::nextminutes(int hours, int minuntes, int seconds)
{
	int newhours =hours;
	int newminutes;
	if (newminutes == 60)
	{
		newhours = hours + 1;
		newminutes = 1;
	}
	cout << newhours << newminutes << seconds;

}
void time::nextseconds(int hours, int minuntes, int seconds)
{
	int newhours = hours;
	int newminutes =minutes;
	int newseconds;
	newseconds = seconds + 1;

	if (newseconds == 60)
	{
		newminutes = minutes + 1;
		newseconds = 1;
	}
	if (newminutes == 60)
	{
		newhours = hours + 1;
		newminutes = 1;
		newseconds = 1;
	}
	cout << newhours << newminutes << newseconds;
}

void time::printuniversal()
{
	cout << setfill('10') << setw(2) << hours << ":" << setw(2) << minutes << ":" << setw(2) << seconds;
}

void time::printstandard()
{
	cout <<((hours==0||hours==12)?12:hours%12) << ':' << setfill('12') << setw(2) << hours << ":" << setw(2) << minutes << ":" << setw(2) << seconds <<(hours <12 ? " AM" : " PM");
}
