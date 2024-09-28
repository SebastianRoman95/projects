#include <iostream>
#include <string>
#include "Employee.cpp"
using namespace std;


int main()
{
	
	employee Employee1("john","smith",1200);
	cout << Employee1.getepfn() << ' ' << Employee1.getepln() << ' ' << Employee1.geteps() * 12;
	cout << "\n increase the salary by 10%" << endl;
	Employee1.increase();
	cout << Employee1.getepfn() << ' ' << Employee1.getepln() << ' ' << Employee1.geteps() * 12<<endl;

	employee Employee2("Will", "smith", 100);
	cout<< Employee2.getepfn() << ' ' << Employee2.getepln() << ' ' << Employee2.geteps() * 12;
	cout << "\n increase the salary by 10%" << endl;
	Employee2.increase();
	cout << Employee2.getepfn() << ' ' << Employee2.getepln() << ' ' << Employee2.geteps() * 12<<endl;
	

	system("Pause");
	return 0;
}
