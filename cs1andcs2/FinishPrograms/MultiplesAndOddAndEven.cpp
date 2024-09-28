#include <iostream> // allows program to perform input and output
using namespace std;
int main()
{
	//integer
	int num1, num2, num3;
	int mult1, mult2, mult3;

	//input
	cout << "enter number one" << endl;
	cin >> num1;
	cout << "enter number two" << endl;
	cin >> num2;

	//if else statements
	if (num1 % num2 != 0)
	{
		cout << num2;
		cout << " is a multiple of ";
		cout << num1 << endl;
	}
	else{
        cout << num2;
        cout << " is not a multiple of ";
        cout << num1 << endl;
    }	

	//if else statement flipped
	if (num2 % num1 != 0)
	{
		cout << num1;
		cout << " is a multiple of ";
		cout << num2 << endl;
	}
	else
    {
        cout << num1;
	    cout << " is not a multiple of ";
	    cout << num2 << endl;
    }
		

	//even and odd statements
	cout << "enter number one" << endl;
	cin >> num3;
	mult1 = num1 % 2;
	mult2 = num2 % 2;
	mult3 = num3 % 2;

	//number 1 even or odd if
	if (mult1 == 0)
	{
		cout << num1 << " is an even number " << endl;
	}
	else
		cout << num1 << " is an odd number " << endl;

	//number 2 even or odd if
	if (mult2 == 0)
	{
		cout << num2 << " is an even number " << endl;
	}
	else
		cout << num2 << " is an odd number " << endl;
	
	//number 3
	if (mult3 == 0)
	{
		cout << num3 << " is an even number " << endl;
	}
	else
		cout << num3 << " is an odd number " << endl;

	system("pause");
	return 0;
}
