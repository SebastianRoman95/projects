#include <iostream>
#include<limits>
#include "overloadmenu.h"
using namespace std;

overload::overload(){
  
}
//validate Home
int overload::validateHome (int choice) {
  while (((choice < 1) || (choice > 2)) || cin.fail ())
    {
        cin.clear ();
        cin.ignore (numeric_limits < streamsize >::max (), '\n');
        cout << "You have entered wrong input." << endl;
        cin >> choice;
    }
  return choice;
}

//lets you enter game menu or do it again
bool overload::pickedTask (int choice) {
    bool AGAIN = true;

    enum Options { NQ = 1, EXIT};

    switch (choice)
        {
        case NQ:
            cout << "Enter Queens." << endl;
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
  while (((choice < 1) || (choice > 3)) || cin.fail ())
    {
        cin.clear ();
        cin.ignore (numeric_limits < streamsize >::max (), '\n');
        cout << "You have entered wrong input." << endl;
        cin >> choice;
    }
  return choice;
}

//queen game menu
void overload::OLGameMenu () {
  bool AGAIN = true;
  int choice;
  cout << "Entering Queens" << endl;
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

//run queens or exit
bool overload::callOL (int choice) {

  bool AGAIN = true;

  enum OPTIONS {RunOL = 1, EXIT};

  switch (choice)
    {
    case RunOL:
        cout << "Enter Overload Sub Menu" << endl <<endl;
        //program for overload here
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

//show games menu
void overload::home () {
    cout << "1. Overload" << endl;
    cout << "2. Exit" << endl;
}

//submenu knight and queen
void overload::subMenuOL() {
    cout << endl;
    cout << "1. Run Game" << endl;
    cout << "2. Exit Game" << endl;
}

//end of print statements