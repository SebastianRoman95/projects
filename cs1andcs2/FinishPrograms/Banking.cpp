#include<iostream>
#include<string>
using namespace std;

class accountinfo
{
public:

	void userccountw(int accountbalance, int wdrawal)
	{
		if (wdrawal <= accountbalance)
		{
			accountbalance = accountbalance - wdrawal;
			cout << "account balance" << accountbalance;
		}
		else { cout << "withdrawal not possible"; }

	}

	void userccountd(int accountbalance2, int deposit)
	{
		if (deposit >= accountbalance2)
		{
			accountbalance2 = accountbalance2 + deposit;
			cout << "account balance" << accountbalance2;
		}
	}

};

int main()
{
	int ad, aw;
	int accountw, ab1 = 0, wd1 = 0;
	int accountd, ad1 = 0, d1 = 0;
	accountinfo a1, a2, a3, a4;

	cout << "welcome please enter 1 to withdrawal or enter 2 to deposit?" << endl;
	cin >> ad;
	if (ad = 1)
	{
		cin >> aw;
		cout << "Please enter how much money you have in your bank account" << endl;
		cin >> accountw;
		cout << "Please enter how much money you want from your bank account" << endl;
		cin >> accountw;

	}
	else if (ad = 2)
	{
		cin >> ad;
		cout << "Please enter how much money you have in your bank account" << endl;
		cin >> accountd;
		cout << "Please enter how much money you want to put inyour bank account" << endl;
		cin >> accountd;
	}

	a1.userccountw(accountw, ab1);
	a2.userccountw(accountw, wd1);
	a3.userccountd(accountd, ad1);
	a4.userccountd(accountd, d1);

	system("pause");
	return 0;
}
