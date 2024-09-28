#include<iostream>
using namespace std;
int main()
{
	//Integers
	int num1, num2;
	int ans, rem;

	//inputs
	cout << "enter number to be divided" << endl;
	cin >> num1;
	cout << "enter number to divide your number by" << endl;
	cin >> num2;

	//quotient
	ans = num1 / num2;
	cout << "Answer is " << ans;

	//remainder
	rem = num1 - (num2 * ans);
	cout << " remainder is " << rem << endl;

	system("pause");
}
