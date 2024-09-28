#include<iostream>
#include<iomanip>
#include "Bank.h"
using namespace std;

void bank::totalbalance()
{
	int account;
	double balance, charges, credit, creditlimit, total;
	cout << "enter accout number (-1 to end)";
	cin >> account;

	while (account != -1)
	{
		//balance
		cout << "enter beginning balance: ";
		cin >> balance;

		//charges
		cout << "enter total charges: ";
		cin >> charges;

		//credit
		cout << "enter total credit: ";
		cin >> credit;


		//limit
		cout << "enter total credit limit: ";
		cin >> creditlimit;

		//total
		total = balance + charges - credit;

		cout << "New Balance:" << total << endl;
		cout << "Account: " << account << endl;
		cout << "Credit Limit: " << setprecision(10) << creditlimit << endl;
		cout << "Charges: " << setprecision(5) << charges << endl;

		if (total <= creditlimit) {
			cout << "New Balance: " << setprecision(6) << total;
		}
		else  {
			cout << "Your credit over exceeds the limit: " << endl;
		}
		cout << "\n enter the Account Number (-1 to end)";
			cin >> account;

	}
}
