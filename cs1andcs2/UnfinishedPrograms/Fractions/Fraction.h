#include<cmath>
#include<iostream>
using namespace std;

#ifndef frac_H
#define frac_H

class frac
{
public:
	int div;
	float total;
	int setfrac(int, int);
	frac add(const frac& right);
	frac sub(const frac& right);
	frac mult(const frac& right);
	frac divi(const frac& right);
	frac tbmult(const frac& right);
	void printfrac();
	void printfractotal();

	frac(int = 0.0, int=0.0);
	

private:
	
	int top;
	int bot;
};

#endif
