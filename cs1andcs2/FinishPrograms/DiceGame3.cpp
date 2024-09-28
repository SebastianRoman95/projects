#include<iostream>
#include<iomanip>
#include<cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main()
{
	//var
	double t;
	int win, lose, rolls, winc= 0, losec= 0, total;
	int w1=0, w2= 0, w3= 0, w4= 0, w5= 0, w6= 0, w7= 0, w8= 0, w9= 0, w10= 0, w11= 0, w12= 0, w13= 0, w14= 0, w15= 0, w16= 0, w17= 0, w18= 0, w19= 0, w20= 0, w21= 0;
	int l1= 0, l2= 0, l3= 0, l4= 0, l5= 0, l6= 0, l7= 0, l8= 0, l9= 0, l10= 0, l11= 0, l12= 0, l13= 0, l14= 0, l15= 0, l16= 0, l17= 0, l18= 0, l19= 0, l20= 0, l21= 0;

	//rolls
	cout << "Enter how many rolls" << endl;
	cin >> rolls;
	for (int i = 1; i <= rolls; i++)
	{

		win = rand() % 21 + 1;
		lose = rand() % 21 + 1;

	//win count
		if (win = lose)
		{
			if (win == 1)
			{
				w1++;
			}
			else if (win == 2)
			{
				w2++;
			}
			else if (win == 3)
			{
				w3++;
			}
			else if (win == 4)
			{
				w4++;
			}
			else if (win == 5)
			{
				w5++;
			}
			else if (win == 6)
			{
				w6++;
			}
			else if (win == 7)
			{
				w7++;
			}
			else if (win == 8)
			{
				w8++;
			}
			else if (win == 9)
			{
				w9++;
			}
			else if (win == 10)
			{
				w10++;
			}
			else if (win == 11)
			{
				w11++;
			}
			else if (win == 12)
			{
				w12++;
			}
			else if (win == 13)
			{
				w13++;
			}
			else if (win == 14)
			{
				w14++;
			}
			else if (win == 15)
			{
				w15++;
			}
			else if (win == 16)
			{
				w16++;
			}
			else if (win == 17)
			{
				w17++;
			}
			else if (win == 18)
			{
				w18++;
			}
			else if (win == 19)
			{
				w19++;
			}
			else if (win == 20)
			{
				w20++;
			}
			else if (win == 21)
			{
				w21++;
			}
			winc++;
		}
	//lose count
		else if (win != lose)
		{
			if (lose == 1)
			{
				l1++;
			}
			else if (lose == 2)
			{
				l2++;
			}
			else if (lose == 3)
			{
				l3++;
			}
			else if (lose == 4)
			{
				l4++;
			}
			else if (lose == 5)
			{
				l5++;
			}
			else if (lose == 6)
			{
				l6++;
			}
			else if (lose == 7)
			{
				l7++;
			}
			else if (lose == 8)
			{
				l8++;
			}
			else if (lose == 9)
			{
				l2++;
			}
			else if (lose == 10)
			{
				l10++;
			}
			else if (lose == 11)
			{
				l11++;
			}
			else if (lose == 12)
			{
				l12++;
			}
			else if (lose == 13)
			{
				l13++;
			}
			else if (lose == 14)
			{
				l14++;
			}
			else if (lose == 15)
			{
				l15++;
			}
			else if (lose == 16)
			{
				l16++;
			}
			else if (lose == 17)
			{
				l17++;
			}
			else if (lose == 18)
			{
				l18++;
			}
			else if (lose == 19)
			{
				l19++;
			}
			else if (lose == 20)
			{
				l20++;
			}
			else if (lose == 21)
			{
				l21++;
			}
			losec++;
		}
	}

	total = winc + losec;
	t = winc / total;

	cout << w1 << " Won " << l1 << " lost on roll 1" << endl;
	cout << w2 << " Won " << l2 << " lost on roll 2" << endl;
	cout << w3 << " Won " << l3 << " lost on roll 3" << endl;
	cout << w4 << " Won " << l4 << " lost on roll 4" << endl;
	cout << w5 << " Won " << l5 << " lost on roll 5" << endl;
	cout << w6 << " Won " << l6 << " lost on roll 6" << endl;
	cout << w7 << " Won " << l7 << " lost on roll 7" << endl;
	cout << w8 << " Won " << l8 << " lost on roll 8" << endl;
	cout << w9 << " Won " << l9 << " lost on roll 9" << endl;
	cout << w10 << " Won " << l10 << " lost on roll 10" << endl;
	cout << w11 << " Won " << l11 << " lost on roll 11" << endl;
	cout << w12 << " Won " << l12 << " lost on roll 12" << endl;
	cout << w13 << " Won " << l13 << " lost on roll 13" << endl;
	cout << w14 << " Won " << l14 << " lost on roll 14" << endl;
	cout << w15 << " Won " << l15 << " lost on roll 15" << endl;
	cout << w16 << " Won " << l16 << " lost on roll 16" << endl;
	cout << w17 << " Won " << l17 << " lost on roll 17" << endl;
	cout << w18 << " Won " << l18 << " lost on roll 18" << endl;
	cout << w19 << " Won " << l19 << " lost on roll 19" << endl;
	cout << w20 << " Won " << l20 << " lost on roll 20" << endl;
	cout << w21 << " Won " << l21 << " lost on roll 21" << endl;

	cout << "The chances of winning are " << t << "%" << endl;
	cout << "average game length is " << total / 21 << endl;


	int num[10] = {309, 893, 72, 270, 109, 830, 338, 487, 240, 505};

	if (num[0] <= num[1]&&num[2]&&num[3]&&num[4] && num[5] && num[6]&&num[7] && num[8] && num[9])
	{
		cout << num[0] << " smallest value" << endl;
	}
	else if (num[1] <= num[0] && num[2] && num[3] && num[4] && num[5] && num[6] && num[7] && num[8] && num[9])
	{
		cout << num[1] << " smallest value" << endl;
	}
	else if (num[2] <= num[1] && num[0] && num[3] && num[4] && num[5] && num[6] && num[7] && num[8] && num[9])
	{
		cout << num[2] << " smallest value" << endl;
	}
	else if (num[3] <= num[1] && num[2] && num[0] && num[4] && num[5] && num[6] && num[7] && num[8] && num[9])
	{
		cout << num[3] << " smallest value" << endl;
	}
	else if (num[4] <= num[1] && num[2] && num[3] && num[0] && num[5] && num[6] && num[7] && num[8] && num[9])
	{
		cout << num[4] << " smallest value" << endl;
	}
	else if (num[5] <= num[1] && num[2] && num[3] && num[4] && num[0] && num[6] && num[7] && num[8] && num[9])
	{
		cout << num[5] << " smallest value" << endl;
	}
	else if (num[6] <= num[1] && num[2] && num[3] && num[4] && num[5] && num[0] && num[7] && num[8] && num[9])
	{
		cout << num[6] << " smallest value" << endl;
	}
	else if (num[7] <= num[1] && num[2] && num[3] && num[4] && num[5] && num[6] && num[0] && num[8] && num[9])
	{
		cout << num[7] << " smallest value" << endl;
	}
	else if (num[8] <= num[1] && num[2] && num[3] && num[4] && num[5] && num[6] && num[7] && num[0] && num[9])
	{
		cout << num[8] << " smallest value" << endl;
	}
	else if (num[9] <= num[1] && num[2] && num[3] && num[4] && num[5] && num[6] && num[7] && num[8] && num[0])
	{
		cout << num[9] << " smallest value" << endl;
	}

	system("pause");
	return 0;
}
