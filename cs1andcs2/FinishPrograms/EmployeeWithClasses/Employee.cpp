#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;


employee::employee(string epfn, string epln, int eps)
{
	setepfn(epfn);
	setepln(epln);
	seteps(eps);
}
//first name
void employee::setepfn(string fname)
{
	epfn = fname;
}

string employee::getepfn()
{
	return epfn;
}

//last name
void employee::setepln(string lname)
{
	epln = lname;
}

string employee::getepln()
{
	return epln;
}

//Cash Money
void employee::seteps(int pay)
{
	eps = pay;
}

int employee::geteps()
{
	return eps;
}

//increase
void employee::increase()
{
	
	double bonus = eps * 0.1;
	eps = eps + bonus;
}

//display
void employee::displaymessage()
{
	cout << "employee:" << getepfn();
	cout << " " << getepln() << "," << endl;
	cout << "Yearly Salary:" << geteps() << endl;
}
