#include<iostream>
using namespace std;
int main()
{
	//Integers 1
	int a1, b1;
	int flip1 = 0;

	//Integers 2
	int a2, b2, c;
	int flip2;

	//input 1
	cout << "enter number a number for A" << endl;
	cin >> a1;
	cout << "enter number a number for B" << endl;
	cin >> b1;

	flip1 = a1;
	a1 = b1;
	b1 = flip1;

	//output 1
	cout << endl << "A is" << a1 << endl;
	cout << "B is " << b1 << endl;

	//inputs 2
	cout << endl << "enter number a number for A" << endl;
	cin >> a2;
	cout << "enter number a number for B" << endl;
	cin >> b2;
	cout << "enter number a number for C" << endl;
	cin >> c;

	//what they input 2
	cout << "A is " << a2 << endl;
	cout << "B is " << b2 << endl;
	cout << "C is " << c << endl;

	//flipping the 3 numbers
	flip2 = c;
	c = a2;
	a2 = flip2;
	a2 = b2;
	b2 = flip2;

	//output 2
	cout << endl << "A is" << a2 << endl;
	cout << "B is " << b2 << endl;
	cout << "C is " << c << endl;

	system("pause");
}
