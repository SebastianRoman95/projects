#ifndef OVERLOADARRAY_H
#define OVERLOADARRAY_H
#include <iostream>
using namespace std;
class overloadArray{

    public:
    //validate Home
    int validateHome (int choice) {
    while (((choice < 1) || (choice > 2)) || cin.fail ())
        {
            cin.clear ();
            cin.ignore (numeric_limits < streamsize >::max (), '\n');
            cout << "You have entered wrong input." << endl;
            cin >> choice;
        }
    return choice;
    }

    //lets you enter overload menu or do it again
    bool pickedTask (int choice) {
        bool AGAIN = true;

        enum Options { OL = 1, EXIT};

        switch (choice)
            {
            case OL:
                cout << "Enter Overloading..." << endl;
                OLGameMenu ();
                break;

            case EXIT:
                cout << "Exiting overload..." << endl << endl;
                AGAIN = false;

        }

    return AGAIN;
    }
    //end of home menu

    //validate overload
    int validateOL (int choice) {
    while (((choice < 1) || (choice > 4)) || cin.fail ())
        {
            cin.clear ();
            cin.ignore (numeric_limits < streamsize >::max (), '\n');
            cout << "You have entered wrong input." << endl;
            cin >> choice;
        }
    return choice;
    }

    //overload menu
    void OLGameMenu () {
    bool AGAIN = true;
    int choice;
    cout << "Entering overloading" << endl;
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

    //run overload or exit
    bool callOL (int choice) {

    bool AGAIN = true;

    enum OPTIONS {OLMeaning = 1, OLExample, RunOL, EXIT};

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

        case RunOL:
            cout << "Enter Overload Sub Menu" << endl <<endl;
            cout << "Run program here" << endl <<endl;
            break;

        case EXIT:
            cout << "Exiting... Overload Sub Menu" << endl << endl;
            AGAIN = false;
        }
    return AGAIN;
    }

    //print statements
    //welcome message
    void welcome () {
        cout << "Welcome to the comparing characters menu." << endl;
    }

    //show overload menu
    void home () {
        cout << "1. Overload" << endl;
        cout << "2. Exit " << endl;
    }

    //submenu overload
    void subMenuOL() {
        cout << endl;
        cout << "1. Run Overload Benefits" << endl;
        cout << "2. Run Overload Real Life Example" << endl;
        cout << "3. Run Overload" << endl;
        cout << "4. Exit Overload" << endl;
    }

    //end of print statements
};

#endif