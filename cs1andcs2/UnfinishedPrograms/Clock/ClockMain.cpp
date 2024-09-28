#include<iostream>
using namespace std;

#include "Date.cpp"
#include "Time.cpp"

int main()
{

	time t(10, 30, 24);

	cout << "the initial universal time is";
	t.printuniversal();
	cout << "the initial standard time is";
	t.printstandard();
	t.settime(12, 24, 50);
	cout << "the initial universal time is";
	t.printuniversal();
	cout << "the initial standard time is";
	t.printstandard();

	const int maxdays = 16;
	date d(12, 24, 2018);

	for (int loop = 1; loop <= maxdays; ++loop)
	{
		d.print();
		d.nextday(12, 25, 2018);
		d.nextmonth(1, 25, 2019);
		d.nextyear(12, 24, 2019);
	}


}
