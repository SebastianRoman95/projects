#pragma once
#include <iostream>
#include <string>
using namespace std;

class employee
{
public:
	employee(string, string,int);

	//first name
	void setepfn(string);
	string getepfn();

	//last name
	void setepln(string);
	string getepln();

	//pay
	void seteps(int);
	int geteps();

	//increase pay and display all
	void increase();
	void displaymessage();


private:
	string epfn;
	string epln;
	int eps;


};
