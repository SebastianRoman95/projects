#include<iostream>
#include<iomanip>
#include<cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main()
{
	int e[10] , employee, c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0, c7 = 0, c8 = 0, c9 = 0, c10 = 0;
	double emp;

	cout << "Enter employee gross sales (-1 to end): " << endl;
	cin >> employee;

	while (employee != -1)
	{
		if (employee >= 100)
		{
			c1++;
			e[0] = c1;
		}
		else if (employee >= 200)
		{
			c2++;
			e[1] = c2;
		}
		else if (employee >= 300)
		{
			c3++;
			e[2] = c3;
		}
		else if (employee >= 400)
		{
			c4++;
			e[3] = c4;
		}
		else if (employee >= 500)
		{
			c5++;
			e[4] = c5;
		}
		else if (employee >= 600)
		{
			c6++;
			e[5] = c6;
		}
		else if (employee >= 700)
		{
			c7++;
			e[6] = c7;
		}
		else if (employee >= 800)
		{
			c8++;
			e[7] = c8;
		}
		else if (employee >= 900)
		{
			c9++;
			e[8] = c9;
		}
		else if (employee <=900)
		{
			c10++;
			e[9] = c10;
		}

		emp = employee * 0.09;
		cout << "emploee commission is " << emp + employee << endl;
		cout << "Enter employee gross sales (-1 to end): " << endl;
		cin >> employee;
	}

	//output
	cout << "Employess in the range: " << endl;
	cout << "0-100: " << e[0] << endl;
	cout << "100-200: " << e[1] << endl;
	cout << "300-400: " << e[2] << endl;
	cout << "400-500: " << e[3] << endl;
	cout << "500-600: " << e[4] << endl;
	cout << "600-700: " << e[5] << endl;
	cout << "700-800: " << e[6] << endl;
	cout << "800-900: " << e[7] << endl;
	cout << "900-1000: " << e[8] << endl;
	cout << "1000 and over: " << e[9] << endl;

	system("pause");
	return 0;
}
