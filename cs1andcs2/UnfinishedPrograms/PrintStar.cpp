#include<iostream>
#include<string>
using namespace std;

int main()
{
	//var
	int stars, stars2;
	int column=1;
	int row=1;

	//user input
	cout << "Enter length of side: ";
	cin >> stars;

	row = stars;


	//limit
	if (stars < 1)
	{
		stars = 1;
		cout << "Invalid Input\nUsing default value 1\n";
	}
	else if (stars > 10)
	{
		stars = 10;
		cout << "Invalid Input\nUsing default value 10\n";
	}

	//rows output b
	//need something to - row to make it a triangle
	while (row >= 0)
	{
		column = stars;
		while (column >= 0)
		{
			if (row == stars)
				cout << "*";
			else if (column == stars)
				cout << "*";
			else if (row == stars2)
				cout << "*";
			
			
			column--;
			stars2 = column;
			
		}
		cout << endl;
		row--;
	}

	system("Pause");
	return 0;
}
