#include<iostream>
#include<string>
using namespace std;
int main()
{
	int count = 1;
	long int side3, total, hype;
	int side1, side2;

	cout << "Side 1 \t Side 2 \t Side 3 " << endl;

	//side one
	for (int a = 0; a < 500; a++)
	{
		side1 = a;

		//side two	
		for (int b = a+1; b < 500; b++)
		{
			side2 = b;
			//side three
			for (int i = b + 1; i < 500; i++)
			{
				side3 = i;
				hype = side3 * side3;
				total = (side1 * side1) + (side2 * side2);
				count++;
				//total
				if (hype == total)
				{
					cout << side1 << '\t' << side2 << '\t' << side3 << endl;
					count++;
				}
			}
		}
	}
	cout << "Total of " << count << "triple were found " << endl;
	system("pause");
	return 0;
}

