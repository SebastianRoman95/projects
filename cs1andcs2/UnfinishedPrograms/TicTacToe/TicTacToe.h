#include<iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;

#ifndef ttt_H
#define ttt_H

class ttt
{
public:
	static const int size = 3;
	enum status {Win, Draw, Continue};

	ttt();
	void makemove();
	void printboard();
	bool validmove(int, int);
	bool xomove(int);
	status gamestatus();
private:
	int board[size][size];
    char symbol;
};

#endif
