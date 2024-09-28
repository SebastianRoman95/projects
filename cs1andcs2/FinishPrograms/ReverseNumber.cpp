#include <iostream>
#include <iomanip>
using namespace std;
int  rev(int num)
{
	int reve = 0; 
	int divi = 1000; 
	int multi = 1; 
	
	while (num > 9)
	{
		if (num >= divi)
		{
			reve += num / divi * multi;
			num %= divi; 
			divi = divi / 10;
			multi = multi * 10;
		}
		else 
			divi /= 10;
	} 
	
	reve += num * multi;


	return reve; 
} 

int main()
{
	int number, reverse=0; 
	cout << "Enter a number between (1 and 9999) " << endl;
	cin >> number;
	

reverse =  rev(number);
	cout << "Reverse number is " << reverse << endl;

	system("pause");
	return 0;
} 
