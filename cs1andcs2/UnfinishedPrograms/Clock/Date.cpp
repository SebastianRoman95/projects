#include <iostream>
using namespace std;

#include "Clock.h"

date::date(int m, int d, int y)
{
	setdate(m, d, y);
}

void date::setdate(int mo, int dy, int yr)
{
	setmonth(mo);
	setday(dy);
	setyear(yr);
}

void date::setday(int d)
{
	if (month == 2 && leapyear())
	{
		days = (d <= 29 && d >= 1) ? d : 1;
	}
	else
	{
		days = (d <= monthdays() && d >= 1) ? d : 1;
	}

}

void date::setmonth(int m)
{
	month = m <= 12 && m >= 1 ? m : 1;
}

void date::setyear(int y)
{
	year = y >= 1900 ? y : 1900;
}

int date::getday()
{
	return days;
}

int date::getmonth()
{
	return month;
}

int date::getyear()
{
	return year;
}

void date::print()
{
	cout << month << '-' << days << '-' << year << endl;
}

bool date::leapyear()
{
	if (getyear() % 400 == 0 || (getyear() % 4 == 0 && getyear() % 100 != 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int date::monthdays()
{
	const int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	return getmonth() == 2 && leapyear() ? 29 : days[getmonth() - 1];
}

void date::nextday(int days, int month, int year)
{
	int newday;
	int newmonth;
	newday = days + 1;

	if (newday == days)
	{
		newmonth = month + 1;
		newday = 1;
	}
	
	cout << newmonth << newday << year <<endl; 
}

void date::nextmonth(int days, int month, int year)
{
	int newday = days;
	int newmonth;
	newmonth = month + 1;

	if (newday == days)
	{
		newday = 1;
	}
	if (newmonth==13)
	{
		newmonth = 1;
	}
	
	cout << newmonth << newday << year << endl;

}

void date::nextyear(int days, int month, int year)
{
	int newyear;
	newyear = year + 1;

	cout << month << days << newyear << endl;
}
