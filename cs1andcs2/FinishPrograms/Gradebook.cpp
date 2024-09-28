#include<iostream>
#include<string>
using namespace std;

class studentinfo
{
public:
	//class with var.
	studentinfo(int id, string fname, string lname, int marks1, int marks2)
	{
		sid = id;
		sfname = fname;
		slname = lname;
		smarks1 = marks1;
		smarks2 = marks2;
	}

	//adding marks for studentinfo
	int calculatetotal()
	{
		return	smarks1 + smarks2;
	}

	//output for studentinfo
	void display()
	{
		cout << "Student id: " << sid << endl;
		cout << "Student first name: " << sfname << endl;;
		cout << "Student last name: " << slname << endl;;
		cout << "Student Marks: " << smarks1 << endl;
		cout << "Student Marks: " << smarks2 << endl;
		cout << "Student Marks: " << calculatetotal() << endl;
	}

	//var. for studentinfo
private:
	int sid, smarks1, smarks2;
	string sfname, slname;


};

//class gradebook 
class gradebook
{
public:
	int score;

//
	void coursename(string inputg)
	{
		inputcg = inputg;
		cout << "The grade book's course name is: " << inputcg << endl;
	}
	void grade()
	{
		

		cout << "What is your grade: " << endl;
		cin >> score;

		cout << "";
		
		if (score >= 90)
			cout << "A" << endl;
		else if (score >= 80)
			cout << "B" << endl;
		else if (score >= 70)
			cout << "c" << endl;
		else if (score >= 60)
			cout << "d" << endl;
		else if (score >= 50)
			cout << "f" << endl;
		else if (score <= 40)
		cout << "failing" << endl;

	}
	private:
		string inputcg;

};

int main()
{
	//var. 
	int stuid, m1, m2;
	string fn, ln, ig;

	//inputs for studentinfo
	cout << "Student id " << endl;
	cin >> stuid;
	cout << "Student first name " << endl;;
	cin >> fn;
	cout << "Student last name " << endl;;
	cin >> ln;
	cout << "Student Marks " << endl;
	cin >> m1;
	cout << "Student Marks " << endl;
	cin >> m2;

	//coursename
	cout << "Please enter the course name: " << endl;
	getline(cin, ig);
	cin >> ig;



	//outputs
	studentinfo s1(1, "sebastian", "cs", 89, 90);
	s1.display();

	gradebook g2;
	g2.coursename(ig);

	gradebook g1;
	g1.grade();
	
	system("Pause");
	return 0;
}
