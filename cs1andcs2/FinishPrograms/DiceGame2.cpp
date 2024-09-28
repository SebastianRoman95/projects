#include<iostream>
#include<iomanip>
#include<cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main()
{
	//var
	int rolls = 36000;
	int size = 6;
	int die2[11];
	int die3=0, rng = 0, rng2 = 0;
	int xc2=0, xc3=0, xc4=0, xc5=0, xc6=0, xc7=0, xc8=0, xc9=0, xc10=0, xc11=0, xc12=0;

	//rolls
	cout << "roll the dice" << endl;
	cin >> rolls;
	for (int i = 1; i<=rolls; i++)
	{
		rng = rand() %  size + 1;
		rng2 = rand() % size + 1;
		die3 = rng + rng2;
		
		if (die3 == 2)
		{
			xc2++;
			die2[0] = xc2;
		}
		else if (die3 == 3)
		{
			xc3++;
			die2[1] = xc3;
		}
		else if (die3 == 4)
		{
			xc4++;
			die2[2] = xc4;
		}
		else if (die3 == 5)
		{
			xc5++;
			die2[3] = xc5;
		}
		else if (die3 == 6)
		{
			xc6++;
			die2[4] = xc6;
		}
		else if (die3 == 7)
		{
			xc7++;
			die2[5] = xc7;
		}
		else if (die3 == 8)
		{
			xc8++;
			die2[6] = xc8;
		}
		else if (die3 == 9)
		{
			xc9++;
			die2[7] = xc9;
		}
		else if (die3 == 10)
		{
			xc10++;
			die2[8] = xc10;
		}
		else if (die3 == 11)
		{
			xc11++;
			die2[9] = xc11;
		}
		else if (die3 == 12)
		{
			xc12++;
			die2[10] = xc12;
		}

	}

	//a values need to be stored in an array
	double a1[11],a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12;

	a2 = 1 / 36;
	a3 = 2 / 36;
	a4 = 3 / 36;
	a5 = 4 / 36;
	a6 = 5 / 36;
	a7 = 6 / 36;
	a8 = 5 / 36;
	a9 = 4 / 36;
	a10 = 3 / 36;
	a11 = 2 / 36;
	a12 = 1 / 36;

	a1[0] = a2;
	a1[1] = a3;
	a1[2] = a4;
	a1[3] = a5;
	a1[4] = a6;
	a1[5] = a7;
	a1[6] = a8;
	a1[7] = a9;
	a1[8] = a10;
	a1[9] = a11;
	a1[10] = a12;
	
	double e[11];

	for (int j = 0; j <= rolls; j++)
	{
		e[j] = die2[j] * 100 / 36000;
	}
	//output
	cout << "Sum Total Expected Actual" << endl;
	for (int k = 0; k <= rolls; k++)
	{
		cout << k << " " << die2[k] << " " << e[k] << " " << a1[k] << endl;
	}
	system("pause");
	return 0;
}

