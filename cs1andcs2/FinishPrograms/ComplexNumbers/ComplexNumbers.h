#include<iostream>
using namespace std;

#ifndef complex_H
#define complex_H

class complex {
public:
	complex add(const complex& right);
	complex subtract(const complex& right);
	void printcomplex();
	void setcomplexnumber(double, double);

	complex(double = 0.0, double = 0.0);

private:
	double real;
	double imaginary;
};

#endif
