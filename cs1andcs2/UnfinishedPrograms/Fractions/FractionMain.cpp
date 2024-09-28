#include "Fraction.cpp"

int main()
{
	frac topnum(1,3), botnum(7,8), newnum(0,0), total=0;

	//add
	topnum.printfrac();
	cout << " + ";
	botnum.printfrac();
	cout << " = ";
	newnum = topnum.add(botnum);
	newnum.printfrac();
	total.printfractotal();
	cout << endl;

	//sub
	topnum.printfrac();
	cout << " - ";
	botnum.printfrac();
	cout << " = ";
	newnum = topnum.sub(botnum);
	newnum.printfrac();
	total.printfractotal();
	cout << endl;

	//mult
	topnum.printfrac();
	cout << " * ";
	botnum.printfrac();
	cout << " = ";
	newnum = topnum.mult(botnum);
	newnum.printfrac();
	total.printfractotal();
	cout << endl;

	//divi
	topnum.printfrac();
	cout << " / ";
	botnum.printfrac();
	cout << " = ";
	newnum = topnum.divi(botnum);
	newnum.printfrac();
	total.printfractotal();
	cout << endl;
}
