#include<iostream>
#include<string>
using namespace std;
int main()
{
	int user, salary, hours, overpay;
	double overtime;

	cout << "Enter paycode (-1 to end)" << endl;
	cin >> user;

	while (user!=-1)
	{
		switch (user)
		{
		case 1:
			cout << "Manager: " << endl;
			cout << "Enter weekly salary: " << endl;
			cin >> salary;
			cout << "Commission Worker's pay is: " << salary << endl;
			break;
		case 2:
			cout << "Worker: " << endl;
			cout << "Enter weekly hourly salary: " << endl;
			cin >> salary;
			cout << "Enter the total hours worked: " << endl;
			cin >> hours;
			if (hours <= 40)
			{
				cout << "Worker's pay is: " << salary * hours << endl;
			}
			else
			{
				overpay = salary * hours;
				overtime = overpay * 1.5;
				cout << "Worker's pay is: " << overtime+overpay << endl;
			}
			break;
		case 3:
			cout << "Commission: " << endl;
			cout << "Enter gross weekly salary: " << endl;
			cin >> salary;
			if (salary <= 250)
			{
				cout << "Commission Worker's total pay is: " << salary << endl;
			}
			else
			{
				overtime = salary * 5.7;
				cout << "Commission Worker's total pay is: " << salary+overtime << endl;
			}
			break;
		case 4:
			cout << "Pieceworker: " << endl;
			cout << "Enter number of pieces: " << endl;
			cin >> hours;
			cout << "Enter wage per piece: " << endl;
			cin >> salary;
			cout << "Commission Worker's pay is: " << salary*hours << endl;
			break;
		}
		cout << "Enter paycode (-1 to end)" << endl;
		cin >> user;
	}
	system("Pause");
	return 0;
}
