#include<iostream>
#include<iomanip>
#include "FiveNumber.h"
using namespace std;

void fivenumber::numbers()
{
	int newnum, nnew=0;
	int num, num1, num2, num3, num4, num5;

	cout << "enter a number (-1 to end)";
	cin >> newnum;

	while (newnum != -1)
	{
		cout << "Enter a number with five digits";
		cin >> num;

		//single numbers
		num1 = num / 10000;
		num2 = num % 10000;
		num3 = num2 % 1000;
		num2 = num2 / 1000;
		num4 = num3 % 100;
		num3 = num3 / 100;
		num5 = num4 % 10;
		num4 = num4 / 10;

		//flip numbers
		num5 = num5 * 10000;
		num4 = num4 * 1000;
		num3 = num3 * 100;
		num2 = num2 * 10;
		nnew = num1 + num2 + num3 + num4 + num5;

		if (num == nnew)
		{
			cout << num << setprecision(5) << "Is a palindrome" << endl;
		}
		else
		{
			cout << num << setprecision(5) << " Is not a palindrome" << endl;
		}
		cout << "\n enter the Account Number (-1 to end)";
		cin >> newnum;

	}
}
