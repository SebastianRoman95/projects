#include <iostream>
#include<string>
#include"Birthday.h"
using namespace std;

bday::bday(string pfn, string pln, int page, int pmonth)
{
	setpfn(pfn);
	setpln(pln);
	setpage(page);
	setpmonth(pmonth);
}

//first name
void bday::setpfn(string pfname)
{
	pfn = pfname;
}
	string bday::getpfn()
{
	return pfn;
}

//last name
void bday::setpln(string plname)
{
	pln = plname;
}
string bday::getpln()
{
	return pln;
}

//age
void bday::setpage(int age)
{
	page = age;
}
int bday::getpage()
{
	return page;
}
//month
void bday::setpmonth(int month)
{
	pmonth = month;
}
int bday::getpmonth()
{
	return pmonth;
}

void bday::displaymessage()
{
	cout << "Welcome" << getpfn();
	cout << "," << getpln()<<endl;
	cout << "age" << getpage() << endl;
	if (pmonth == 1)
		cout << "Happy birthday in January";
	else if(pmonth == 2)
		cout << "Happy birthday in February";
	else if(pmonth == 3)
	cout << "Happy birthday in March";
	else if (pmonth == 4)
		cout << "Happy birthday in April";
	else if (pmonth == 5)
		cout << "Happy birthday in May";
	else if (pmonth == 6)
		cout << "Happy birthday in June";
	else if (pmonth == 7)
		cout << "Happy birthday in July";
	else if (pmonth == 8)
		cout << "Happy birthday in August";
	else if (pmonth == 9)
		cout << "Happy birthday in September";
	else if (pmonth == 10)
		cout << "Happy birthday in October";
	else if (pmonth == 11)
		cout << "Happy birthday in November";
	else if (pmonth == 12)
		cout << "Happy birthday in December";
}
