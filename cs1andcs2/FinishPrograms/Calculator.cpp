#include<iostream>
using namespace std;
int main()
{
	//Integers
	int num1, num2, num3;
	int sval, lval, sum, avg, mult;

	//inputs
	cout << "enter number one" << endl;
	cin >> num1;
	cout << "enter number two" << endl;
	cin >> num2;
	cout << "enter number three" << endl;
	cin >> num3;

	//sum, product, and average
	sum = num1 + num2 + num3;
	cout << "sum of " << num1 << " and " << num2 << " and " << num3 << " equals " << sum << endl;
	mult = num1 * num2 * num3;
	cout << "product of " << num1 << " and " << num2 << " and " << num3 << " equals " << mult << endl;
	avg = sum / 3;
	cout << "average of" << num1 << " and " << num2 << " and " << num3 << " equals " << avg << endl;

	//largest number
	if (num1 >= num2)
		lval = num1;
	else
		lval = num2;

	cout << " The largest number out of "<< num1 << " and " << num2 << " is " << lval << endl;
	
	//smallest number
	if (num3 <= num1)
		sval = num3;
	else
		sval = num1;

	cout << " The smallest number out of " << num1 << " and " << num3 << " is " << sval << endl;

	system("pause");
}
