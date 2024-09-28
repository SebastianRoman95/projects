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
	double dice[11], p1[11];
	int dietotal=0, die1 = 0, die2 = 0;
	int c1 =0, c2=0, c3=0, c4=0, c5=0, c6=0, c7=0, c8=0, c9=0, c10=0, c11=0;

	//rolls
	for (int i = 1; i<=rolls; i++)
	{
		die1 = rand() %  6 + 1;
		die2 = rand() % 6 + 1;
		dietotal = die1 + die2;
		
		if (dietotal == 2)
		{
			c1++;
			dice[0] = c1;
		}
		else if (dietotal == 3)
		{
			c2++;
			dice[1] = c2;
		}
		else if (dietotal == 4)
		{
			c3++;
			dice[2] = c3;
		}
		else if (dietotal == 5)
		{
			c4++;
			dice[3] = c4;
		}
		else if (dietotal == 6)
		{
			c5++;
			dice[4] = c5;
		}
		else if (dietotal == 7)
		{
			c6++;
			dice[5] = c6;
		}
		else if (dietotal == 8)
		{
			c7++;
			dice[6] = c7;
		}
		else if (dietotal == 9)
		{
			c8++;
			dice[7] = c8;
		}
		else if (dietotal == 10)
		{
			c9++;
			dice[8] = c9;
		}
		else if (dietotal == 11)
		{
			c10++;
			dice[9] = c10;
		}
		else if (dietotal == 12)
		{
			c11++;
			dice[10] = c11;
		}

	}

	double f=2;
	for (int d = 0; d <= 10; d++)
	{

	p1[d] = f / 36 * 100;
	f++;
	}
	
	cout << "Sum " << "Total " << "Expected " << "Actual " << endl;

	for (int c = 0; c <= 10; c++)
	{
		cout << c+2 << "   " << dice[c]  << " " << p1[c] << "  " <<dice[c] / 36 <<endl;
	}
	
	system("pause");
	return 0;
}
