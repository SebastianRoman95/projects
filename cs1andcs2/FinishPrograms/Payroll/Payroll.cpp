#include<iostream>
#include<iomanip>
#include "Payroll.h"
using namespace std;

void payroll::pay()
{
	int employee;
	double time, addtime, total, increase;
	cout << "enter accout number (-1 to end)";
	cin >> employee;

	while (employee != -1)
	{
		//balance
		cout << "Eneter how many hours you worked: ";
		cin >> time;

		//total

		if (time <= 40)
		{
			total = time * 10;
		}
		else if (time >= 75)
		{
			addtime = time - 40;
			increase = addtime * 5;
			total = time * 10;
			total = total + increase + 1000;
		}
		else if (time >= 55)
		{
			addtime = time - 40;
			increase = addtime * 5;
			total = time * 10;
			total = total + increase + 100;
		}
		else if (time >= 40)
	{
		addtime = time - 40;
		increase = addtime * 5;
		total = time * 10;
		total = total + increase;
	}

		

		cout << "employee: " << employee << endl;
		cout << "How many hours you work: " << fixed << time << endl;
		cout << "Salary: " << fixed << total << endl;

	}
}
