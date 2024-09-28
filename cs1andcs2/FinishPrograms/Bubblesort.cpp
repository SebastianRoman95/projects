#include<iostream>
#include <ctime>
#include <string>
using namespace std;

//random number pair
int rngnum(int pairnum)
{
	int rng1, rng2;
	for (int t = 0; t <= 10000; t++)
	{
		rng1 = rand() % 100 + 1;
		rng2 = rand() % 100 + 1;
		if (rng1 == rng2)
		{
			pairnum = rng1;
			t = 10000;
		}
	}
    //cout << "test" << pairnum <<endl;
	return pairnum;
}


//storing random number
void rngstoring(int tennum[])
{
	for (int b = 0; b <= 9; b++)
	{
        int pairnum = rngnum(pairnum);
		tennum[b] = pairnum;
	}
}

//flipping values around in the array
void flip(int* num1, int* num2)
{
	int flipper = *num1;
	*num1 = *num2;
	*num2 = flipper;
}

//function for sorting
void swapper(int tennum[], int s)
{
	//picks the element that is in that line of code
	for (int n = 0; n < s-1; n++)
	{
		//flips the element
		for (int i = 0; i < s - n - 1; i++) {
			if (tennum[i] > tennum[i + 1])
				flip(&tennum[i], &tennum[i + 1]);
		}
	}
}

//output
void print(int tennum[], int s1)
{
	for (int m = 0; m < s1; m++)
		cout << tennum[m] << ",";
 }


int main()
{
	int tennum[10];
	int s = sizeof(tennum) / sizeof(tennum[0]);
	rngstoring(tennum);
    swapper(tennum, s);
	print(tennum, s);
	
	system("pause");
	return 0;
}
