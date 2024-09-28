#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
int main()
{
	int user = 0, rng = 0;
	int counth, countt, lw=0;


	cout << "Enter how many coin flips (-1 to end)" << endl;
	cin >> user;

	while (user != -1)
	{
		counth = 0;
		countt = 0;

		for (int i = 0; i < user; i++)
		{
			rng = rand() % 2 + 1;

			if (rng == 2)
			{
				cout << "heads" << endl;
				counth++;
			}
			else if (rng == 1)
			{
				cout << "tails" << endl;
				countt++;
			}
		}

		cout << "Tails: "<< countt << endl;
		cout << "Heads: "<< counth << endl;
		cout << "Winnings: $" << counth - countt << endl;

		cout << "Enter how many coin flips (-1 to end)" << endl;
		cin >> user;
	}

	int user2=0;
	int car1=0, car2=0, car3=0, charge = 2, total = 0;
	int charget = 0, chargetotal = 0;
	int charget2 = 0, chargetotal2 = 0;
	int charget3 = 0, chargetotal3 = 0;

	while (user2 != -2)
	{
	
		cout << "Enter the hours parked for three cars (to end -2)" << endl;
		cin >> car1;
		cin >> car2;
		cin >> car3;

		//car 1
		if (car1 <= 3)
		{
			chargetotal = chargetotal + charge;
			cout << "car 1 " << car1 << " charge is " << chargetotal << endl;
		}
		else if (car1 <= 23)
		{
			charget = car1 - 3;
			chargetotal = charget * 0.5;
			chargetotal = chargetotal + charge;
			cout << "car 1 " << car1 << " charge is " << chargetotal << endl;
		}
		else if (car1 >=24)
		{
			chargetotal = chargetotal + charge + 8;
			cout << "car 1 " << car1 << " charge is " << chargetotal << endl;
		}

		//car 2
		if (car2 <= 3)
		{
			chargetotal2 = chargetotal2 + charge;
			cout << "car 2 " << car2 << " charge is "<< chargetotal2 << endl;
		}
		else if (car2 <= 23)
		{
			charget2 = car2 - 3;
			chargetotal2 = charget2 * 0.5;
			chargetotal2 = chargetotal2 + charge;
			cout << "car 2 " << car2 << " charge is " << chargetotal2 << endl;
		}
		else if (car2 >= 24)
		{
			chargetotal2 = chargetotal2 + charge + 8;
			cout << "car 2 " << car2 << " charge is " << chargetotal2 << endl;
		}
		//car 3
		if (car3 <= 3)
		{
			chargetotal3 = chargetotal3 + charge;
			cout << "car 3 " << car3 << " charge is " << chargetotal3 << endl;
		}
		else if (car3 <= 23)
		{
			charget3 = car3 - 3;
			chargetotal3 = charget3 * 0.5;
			chargetotal3 = chargetotal3 + charge;
			cout << "car 3 " << car2 << " charge is " << chargetotal3 << endl;
		}
		else if (car3 >= 24)
		{
			chargetotal3 = chargetotal3 + charge + 8;
			cout << "car 3 " << car2 << " charge is " << chargetotal3 << endl;
		}
		
			total = chargetotal3 + chargetotal2 + chargetotal;
			cout << "Total hours: " << car1 + car2 +car3 << "Total Cost: " << total << endl;

			cout << "Enter the hours parked for three cars (to end -2) " << endl;
			cin >> car1;
			cin >> car2;
			cin >> car3;
	}

}
