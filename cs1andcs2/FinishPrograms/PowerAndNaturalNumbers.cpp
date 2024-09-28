#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

void natural(int numl)
{
	int sum=0, count=0;
	for (int i = 1; i <= numl; i++)
	{
		sum = sum + i;
		count = count + 1;
		if (count <= numl - 1)
		{
			cout << count << " + ";
		}
	}
		cout << numl << endl;
		cout << " your number " << count << " Natural number is " << sum << endl;
}

void display(int numb, int nume)
{
	int num;
	num = pow(numb, nume);
	cout << numb << " Raised to " << nume << " is " << num << endl;
}

void display2(int num1, int num2)
{
	if (num1 < num2)
	{
		cout << "Number one " << num1 << " is less than Number two " << num2 << endl;
	}
	else if (num2 < num1)
	{
		cout << "Number two " << num2 << " is less than Number one " << num1 << endl;
	}
	else
	{
		cout << "Number one " << num1 << " and Number two " << num2 << " are the same value" << endl;
	}
}
int main()
{
	int limit, b, e, usenum1, usenum2;
	cout << "Enter a number: ";
	cin >> limit;
	cout << "Enter a base number: " << endl;
	cin >> b;
	cout << "Enter a exponent: " << endl;
	cin >> e;
	cout << "Enter a number: ";
	cin >> usenum1;
	cout << "Enter a number: ";
	cin >> usenum2;

	natural(limit);
	display(b, e);
	display2(usenum1,usenum2);
	system("pause");
	return 0;
}
