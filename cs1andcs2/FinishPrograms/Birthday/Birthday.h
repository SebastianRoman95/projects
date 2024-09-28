#pragma once
#include <iostream>
#include<string>
using namespace std;

class bday
{
public:
	
	bday(string, string, int, int);

	//first name
	void setpfn(string);
	string getpfn();
	
	//last name
	void setpln(string);
	string getpln();

	//person age
	void setpage(int);
	int getpage();
	
	//person month
	void setpmonth(int);
	int getpmonth();
	
	//display
	void displaymessage();
private:

	//var
	string pfn;
	string pln;
	int page;
	int pmonth;

};
