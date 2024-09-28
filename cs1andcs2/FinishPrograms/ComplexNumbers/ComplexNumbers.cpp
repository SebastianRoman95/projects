#include <iostream>
#include "ComplexNumbers.h"
using namespace std;

complex::complex(double real, double imaginary)
{
	setcomplexnumber(real, imaginary);
}

complex complex::add(const complex& right)
{
	complex c(0.0, 0.0);
	c.setcomplexnumber(real + right.real, imaginary+ right.imaginary);
	return c;
}

complex complex::subtract(const complex& right)
{
	complex c(0.0, 0.0);
	c.setcomplexnumber(real - right.real, imaginary - right.imaginary);
	return c;
}

void complex::printcomplex()
{
	cout << '(' << real << ", " << imaginary << ')';
}

void complex::setcomplexnumber(double rp, double ip)
{
	real = rp;
	imaginary = ip;
}
