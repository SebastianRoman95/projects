#include<iostream>
using namespace std;
int main()
{
	//Integers
	int a, b,c;
	int x;

	//inputs
	cout << "enter number a number for A" << endl;
	cin >> a;
	cout << "enter number a number for B" << endl;
	cin >> b;
	cout << "enter number a number for C" << endl;
	cin >> c;
	cout << "these numbers will be used to find the value of X " << endl;

	x = (a*a) + (a*b*c) + (b*b);

	cout << endl << "X = " << x << endl;
	
	system("pause");

}
