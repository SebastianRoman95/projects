#include"Fraction.h"
using namespace std;

frac::frac(int top, int bot)
{
	setfrac(top, bot);
}

int frac::setfrac(int to, int bo)
{
	top = to;
	bot = bo;
}

frac frac::tbmult(const frac& right)
{
	div = 0;

	while (div % right.bot !=0)
	{
		div = div + bot;
	}
	return (div);
}

frac frac::add(const frac& right)
{
	int gcf1, gcf2;
	tbmult(div);

	gcf1 = bot / div;
	gcf2 = right.bot / div;

	
	frac newnum(0, 0);
	newnum.frac((top * gcf1) + (right.top* gcf2), (bot * gcf1) && (right.bot* gcf2));
}

frac frac::sub(const frac& right)
{
	int gfc1, gfc2;
	tbmult(div);

	gfc1 = bot / div;
	gfc2 = right.bot / div;

	frac newnum(0, 0);
	newnum.frac((top * gfc1) - (right.top * gfc2), (bot * gfc1) && (right.bot * gfc2));
	
}

frac frac::mult(const frac& right)
{
	frac newnum(0, 0);
	newnum.frac(top * right.top, bot * right.bot);
}

frac frac::divi(const frac& right)
{
	frac newnum(0, 0);
	newnum.frac(top * right.bot, bot * right.top);

}

void frac::printfrac()
{
	cout << top << "/" << bot;
}

void frac::printfractotal()
{
	frac newnum(top, bot);
	frac total(0);
	total.frac(top / bot);
	cout << total;
}
