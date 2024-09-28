#include <iostream> // allows program to perform input and output
using namespace std;
int main()
{
	//integer
	int usern;
	int user1, user2, user3;
	int num1, num2, num3, num4, num5;
	int number1, number2, number3, number4, number5;
	int n1, n2, n3, n4;

	//input
	cout << "enter a five digit number " << endl;
	cin >> usern;

	//getting the five digit numbers
	num1 = usern / 10000;
	num2 = usern % 10000;
	num3 = num2 % 1000;
	num2 = num2 / 1000;
	num4 = num3 % 100;
	num3 = num3 / 100;
	num5 = num4 % 10;
	num4 = num4 / 10;

	//output
	cout << "first digit " << num1 << endl;
	cout << "second digit " << num2 << endl;
	cout << "third digit " << num3 << endl;
	cout << "fourth digit " << num4 << endl;
	cout << "fifth digit " << num5 << endl;

	// number 3 input

	cout << "enter a one digit number " << endl;
	cin >> user1;
	cout << "enter a one digit number " << endl;
	cin >> user2;
	cout << "enter a one digit number " << endl;
	cin >> user3;

	//combine the three numbers
	number1 = user1 * 100;
	number2 = user2 * 10;
	number3 = number1 + number2 + user3;

	cout << "Your numbers made " << number3<< endl;
	


	//number 1
	n1 = 24 / 5;
	n2 = 18 % 3;
	n3 = 13 % 9;
	n4 = 13 / 2 % 2;

	cout << "problem 1 " << n1 << endl;
	cout << "problem 2 " << n2 << endl;
	cout << "problem 3 " << n3 << endl;
	cout << "problem 4 " << n4 << endl;

	system("pause");
	return 0;
}
