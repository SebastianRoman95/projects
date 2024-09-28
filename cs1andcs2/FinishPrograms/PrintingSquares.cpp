#include<iostream>
#include<string>
using namespace std;

int main()
{
	//var
	int stars; 
	int column; 
	int row = 1; 

	//user input
	cout << "Enter length of side: ";
	cin >> stars;

	//col output
	if (stars < 1)
	{
		stars = 1;
		cout << "Invalid Input\nUsing default value 1\n";
	} 
	else if (stars > 20)
	{
		stars = 20;
		cout << "Invalid Input\nUsing default value 20\n";
	} 

	//rows output
	while (row <= stars)
	{
		column = 1;
		while (column <= stars)
		{
			if (row == 1)
				cout << "*";
			else if (row == stars)
				cout << "*";
			else if (column == 1)
				cout << "*";
			else if (column == stars)
				cout << "*";
			else
				cout << " ";
			column++;
		} 
		cout << endl;
		row++;
	} 

	system("Pause");
	return 0;
}
