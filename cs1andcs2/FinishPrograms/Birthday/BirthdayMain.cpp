#include <iostream>
#include<string>
#include"Birthday.cpp"
using namespace std;
int main()
{
	
	bday birthd("James", "Mill", 10, 3);
	cout << birthd.getpfn() << birthd.getpln() << birthd.getpage();
	birthd.displaymessage();

	system("pause");
	return 0;
}
