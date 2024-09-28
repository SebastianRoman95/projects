#include <iostream>
#include<limits>
#include "overloadmenu.h"
#include "overloadarray.cpp"
using namespace std;

overload::overload(){
  
}
//validate Home
int overload::validateHome (int choice) {
  while (((choice < 1) || (choice > 4)) || cin.fail ())
    {
        cin.clear ();
        cin.ignore (numeric_limits < streamsize >::max (), '\n');
        cout << "You have entered wrong input." << endl;
        cin >> choice;
    }
  return choice;
}

//pick task
bool overload::pickedTask (int choice) {
    bool AGAIN = true;

    enum Options { OLMeaning = 1, OLExample, AOD, EXIT};

    switch (choice)
        {
        case OLMeaning:
            cout << "Enter Overload Sub Menu" << endl <<endl;
            cout << "The benefits of overloading is reusability, protecting data." << endl <<endl;
            break;

        case OLExample:
            cout << "Enter Overload Sub Menu" << endl <<endl;
            cout << "Real life example of Overloading." << endl;
            cout << "A family shares a last name. However if you want a certain person from the family" << endl;
            cout << "you need their first name as well as the last name." <<endl;
            cout << "Furthermore, a person can also have a middle name or nickname." <<endl <<endl;
            break;

        case AOD:
            cout << "One Dimensional Array." << endl;
            OLGameMenu ();
            break;

        case EXIT:
            cout << "Exiting game. Thank you for playing!" << endl << endl;
            AGAIN = false;

    }

  return AGAIN;
}
//end of home menu

//validate overload
int overload::validateOL (int choice) {
  while (((choice < 1) || (choice > 10)) || cin.fail ())
    {
        cin.clear ();
        cin.ignore (numeric_limits < streamsize >::max (), '\n');
        cout << "You have entered wrong input." << endl;
        cin >> choice;
    }
  return choice;
}

//one dime. array menu
void overload::OLGameMenu () {
  bool AGAIN = true;
  int choice;
  cout << "Entering One Dimensional Array" << endl;
  do
    {
      subMenuOL ();
      cout << endl << "Make your choice: ";
      cin >> choice;
      choice = validateOL (choice);
      AGAIN = callOL (choice);

    }
  while (AGAIN);

}

//run array one or exit
bool overload::callOL (int choice) {
    overloadArray integers1(7);
    overloadArray integers2;
    overloadArray integers3(integers1);
    bool AGAIN = true;

  enum OPTIONS {printArr = 1, userInput, inequality, copy, equal, equality, rvalue, lvalue, outrange, EXIT};

  switch (choice)
    {        
    case printArr:
        cout << "Enter Overload Sub Menu" << endl <<endl;
        cout << "size of array integers1 is " << integers1.getSize()<< "\narray after initialization:\n" << integers1;
        cout << "size of array integers2 is " << integers2.getSize()<< "\narray after initialization:\n" << integers2;
        break;

    case userInput:
        cout << "Enter Overload Sub Menu" << endl <<endl;
        cout << "\nenter 17 integers:" <<endl;
        cin >> integers1 >> integers2;
        // << op
        cout << "\nafter input, the array contain:\n" << "integers1:\n" << integers1 << "integers2:\n" << integers2;
        break;

    case inequality:
        cout << "Enter Overload Sub Menu" << endl <<endl;
        cout << "\nevaluating: integers1 != integers2"<<endl;
        if(integers1!=integers2){
            cout << "integers1 and integers2 are not equal" <<endl;
        }
        break;
        
    case copy:
        cout << "Enter Overload Sub Menu" << endl <<endl;
        cout << "\nsize of array integers3 is " << integers3.getSize()<<"\narray initialization:\n"<< integers3; 
        break;

    case equal:
        cout << "Enter Overload Sub Menu" << endl <<endl;
        cout <<"\nassigning integers2 to integers1:" <<endl;
        integers1 = integers2;
        cout << "integers1:\n" << integers1 << "integers2:\n" << integers2;
        break;

    case equality:
        cout << "Enter Overload Sub Menu" << endl <<endl;
        cout << "\nevaluating: integers1 == integers2" <<endl;
        if(integers1==integers2){
            cout << "integers1 and integers2 are equal" <<endl;
        }
        break;

    case rvalue:
        cout << "Enter Overload Sub Menu" << endl <<endl;
        cout << "\nintegers1[5] is "<<integers1[5];
        break;

    case lvalue:
        cout << "Enter Overload Sub Menu" << endl <<endl;
        cout << "\n\nassigning 1000 to integers1[5]"<<endl;
        integers1[5]=1000;
        cout << "integers1:\n"<<integers1;
        break;

    case outrange:
        cout << "Enter Overload Sub Menu" << endl <<endl;
        cout <<"\nattempt to assign 1000 to integers1[15]"<<endl<<endl;
        integers1[15]=1000;
        break;

    case EXIT:
        cout << "Exiting... Overload Sub Menu" << endl << endl;
        AGAIN = false;
    }
  return AGAIN;
}

//print statements
//welcome message
void overload::welcome () {
    cout << "Welcome to the comparing characters menu." << endl;
}

//show task menu
void overload::home () {
    cout << "1. Overload benefits" << endl;
    cout << "2. Overload example" << endl;
    cout << "3. Overload array" << endl;
    cout << "4. Exit" << endl;
}

//submenu overloading one dime. array
void overload::subMenuOL() {
    cout << endl;
    cout << "1. print array 1 and 2" << endl;
    cout << "2. input your own values" << endl;
    cout << "3. print inequality" << endl;
    cout << "4. print copy" << endl;
    cout << "5. print equal" << endl;
    cout << "6. print equality" << endl;
    cout << "7. print rvalue" << endl;
    cout << "8. print lvalue" << endl;
    cout << "9. print out of range" << endl;
    cout << "10. Exit Game" << endl;
}

//end of print statements