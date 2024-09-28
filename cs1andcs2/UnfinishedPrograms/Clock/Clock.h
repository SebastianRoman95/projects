#pragma warning(disable :4996)
#include<iostream>
#include<ctime>
using namespace std;


#ifndef time_H
#define time_H
const time_t currenttime = time(0);
const tm* localtime = localtime(&currenttime);
settime(localtime->tm_hour, localtime->tm_min, localtime->tm_sec);

//const tm* localtime = localtime(&currenttime);
//settime(localtime->tm_hour, localtime->tm_min, localtime->tm_sec);

class time
{
public:
	time();
	void settime(int, int, int);
	void printuniversal();
	void printstandard();

	void sethours(int);
	void setminutes(int);
	void setseconds(int);

	int gethours();
	int getminutes();
	int getseconds();

	void nexthours(int, int, int);
	void nextminutes(int, int, int);
	void nextseconds(int, int, int);

private:
	int hours;
	int minutes;
	int seconds;

};

#endif
#ifndef date_H
#define date_H

class date
{

public:
	date(int = 1, int = 1, int = 2000);
	void print();
	void setdate(int, int, int);

	void setday(int);
	void setmonth(int);
	void setyear(int);

	int getmonth();
	int getday();
	int getyear();

	void nextday(int, int, int);
	void nextmonth(int, int, int);
	void nextyear(int, int, int);

private:
	int month;
	int days;
	int year;
	bool leapyear();
	int monthdays();

};

#endif
