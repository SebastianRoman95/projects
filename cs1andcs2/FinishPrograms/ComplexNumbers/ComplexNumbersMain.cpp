#include <iostream>
using namespace std;
#include "ComplexNumbers.cpp"

int main()
{

	//complex a, b, c and declare values sepe
	complex a(1, 7), b(9, 2), c = 0;

	a.printcomplex();
	cout << " + ";
	b.printcomplex();
	cout << " = ";
	c = a.add(b);
	c.printcomplex();
	cout << endl;

	a.setcomplexnumber(10, 1);
	b.setcomplexnumber(11, 5);

	a.printcomplex();
	cout << " - ";
	b.printcomplex();
	cout << " = ";
	c = a.subtract(b);
	c.printcomplex();
	cout << endl;
}
