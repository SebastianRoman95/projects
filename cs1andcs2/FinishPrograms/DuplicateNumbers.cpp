#include<iostream>
#include<iomanip>
#include<cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main()
{
	int num1[20], user, count=0, dup=20;
	while (count <= 19)
	{
        cout << "enter 20 numbers from 10-100 " << endl;
        cin >> user;	
		//invalid
		if (user >= 101)
		{
			count--;
			cout << "invalid number" << endl;
			cout << "enter 20 numbers from 10-100 " << endl;
			cin >> user;
		}
		else if (user <= 9)
		{
			count--;
			cout << "invalid number" << endl;
			cout << "enter 20 numbers from 10-100 " << endl;
			cin >> user;
		}

		//duplicate
		for (int i = 0; i < dup; i++)
		{
			if (num1[i] == user)
			{
				cout << "Duplicate number" << endl;
				count--;
				cout << "enter 20 numbers from 10-100 " << endl;
				cin >> user;
			}
		}
        num1[count] = user;
        count++;
	}

	//output
	cout << "The nonduplicate values are: " << endl;
	for (int k = 0; k <= 19; k++)
	{
		cout << num1[k] << endl;
	}


	system("pause");
	return 0;
}
