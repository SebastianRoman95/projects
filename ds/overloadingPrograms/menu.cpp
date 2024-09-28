#include<iostream>
#include<limits>
#include "menu.h"
using namespace std;

menu::menu(){

}
/////////////////////////////////////////////////////////////////////home start/////////////////////////////////////////////////////////
int menu::validateHome (int choice) {
  while (((choice < 1) || (choice > 5)) || cin.fail ())
    {
        cin.clear ();
        cin.ignore (numeric_limits < streamsize >::max (), '\n');
        cout << "You have entered wrong input." << endl;
        cin >> choice;
    }
  return choice;
}

//lets you enter game menu or do it again
bool menu::picktask (int choice) {
    bool AGAIN = true;

    enum Options {classes = 1, templates, inheritance, overloading, EXIT };

    switch (choice) {
      case classes:
          cout << "Enter classes." << endl;
          classesMenu ();
          break;

      case templates:
          cout << "Enter templates." << endl;
          templatesMenu ();
          break;

      case inheritance:
          cout << "Enter inheritance" << endl;
          inheritanceMenu ();
          break;

      case overloading:
            cout << "Enter overloading" << endl;
            overloadingMenu ();
            break;

      case EXIT:
          cout << "Exiting main menu..." << endl << endl;
          AGAIN = false;
    }

  return AGAIN;
}
/////////////////////////////////////////////////////////////////////home end///////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////classes start/////////////////////////////////////////////////////////
int menu::validateClasses (int choice) {
  while (((choice < 1) || (choice > 4)) || cin.fail ())
    {
        cin.clear ();
        cin.ignore (numeric_limits < streamsize >::max (), '\n');
        cout << "You have entered wrong input." << endl;
        cin >> choice;
    }
  return choice;
}

bool menu::pickedTaskClasses (int choice) {
    bool AGAIN = true;

    enum Options { CMeaning = 1, CExample, EXIT};

    switch (choice)
        {
        case CMeaning:
            cout << "Enter Classes Sub Menu" << endl <<endl;
            cout << "The benefits of classes is reusability, protecting data." << endl <<endl;
            break;

        case CExample:
            cout << "Enter Classes Sub Menu" << endl <<endl;
            cout << "Real life example of Classes." << endl;
            cout << "PUT SOMETHING HERE" << endl<<endl;
            break;

        case EXIT:
            cout << "Exiting Classes..." << endl << endl;
            AGAIN = false;

    }

  return AGAIN;
}

void menu::classesMenu () {
  bool AGAIN = true;
  int choice;
  cout << "Entering classes" << endl;
  do
    {
      classesHome ();
      cout << endl << "Make your choice: ";
      cin >> choice;
      choice = validateClasses (choice);
      AGAIN = pickedTaskClasses (choice);

    }
  while (AGAIN);

}
//////////////////////////////////////////////////////////////////classes end////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////templates menu start////////////////////////////////////////////////////////
//validate temaplates menu
int menu::validateGames (int choice) {
  while (((choice < 1) || (choice > 5)) || cin.fail ())
    {
        cin.clear ();
        cin.ignore (numeric_limits < streamsize >::max (), '\n');
        cout << "You have entered wrong input." << endl;
        cin >> choice;
    }
  return choice;
}

//lets you enter templates menu or do it again
bool menu::pickedGame (int choice) {
    bool AGAIN = true;

    enum Options { TMeaning=1, TExample, NQ, KT, EXIT };

    switch (choice) {
      case TMeaning:
          cout << "Enter Templates Sub Menu" << endl <<endl;
          cout << "The benefits of classes is reusability, protecting data." << endl <<endl;
          break;

      case TExample:
          cout << "Enter Templates Sub Menu" << endl <<endl;
          cout << "Real life example of Templates." << endl;
          cout << "PUT SOMETHING HERE" << endl<<endl;
          break;
      
      case NQ:
          cout << "Enter Queens." << endl;
          NQmenu ();
          break;

      case KT:
          cout << "Enter Knight Tour." << endl;
          KTmenu ();
          break;

      case EXIT:
          cout << "Exiting game. Thank you for playing!" << endl << endl;
          AGAIN = false;
    }

  return AGAIN;
}

//templates menu
void menu::templatesMenu () {
  bool AGAIN = true;
  int choice;
  cout << "Entering templates menu" << endl;
  do
    {
      gameHome ();
      cout << endl << "Make your choice: ";
      cin >> choice;
      choice = validateGames (choice);
      AGAIN = pickedGame (choice);

    }
  while (AGAIN);

}
/////////////////////////////////////////////////////////////////templates menu end////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////templates game menu start////////////////////////////////////////////////////////
//validate game knight and queen
int menu::validatemenu (int choice) {
  while (((choice < 1) || (choice > 2)) || cin.fail ())
    {
        cin.clear ();
        cin.ignore (numeric_limits < streamsize >::max (), '\n');
        cout << "You have entered wrong input." << endl;
        cin >> choice;
    }
  return choice;
}

//run knight tour or exit
bool menu::callKT (int choice) {

  bool AGAIN = true;

  enum OPTIONS {RunGame = 1, EXIT};

  switch (choice)
    {
    case RunGame:
        cout << "Enter Knight Tour's SM." << endl <<endl;
        solution ();
        break;

    case EXIT:
        cout << "Exiting... Knight Tour's SM!" << endl << endl;
        AGAIN = false;
    }
  return AGAIN;
}

//knight tour game menu
void menu::KTmenu () {
  bool AGAIN = true;
  int choice;
  cout << "Entering Knight tour" << endl;
  do
    {
      subMenuKQ ();
      cout << endl << "Make your choice: ";
      cin >> choice;
      choice = validatemenu (choice);
      AGAIN = callKT (choice);

    }
  while (AGAIN);

}

//run queens or exit
bool menu::callNQ (int choice) {

  bool AGAIN = true;

  enum OPTIONS {RunGame = 1, EXIT};

  switch (choice)
    {
    case RunGame:
        cout << "Enter Queen's SM" << endl <<endl;
        queenSolution();
        break;

    case EXIT:
        cout << "Exiting... Queen's SM" << endl << endl;
        AGAIN = false;
    }
  return AGAIN;
}

//queen game menu
void menu::NQmenu () {
  bool AGAIN = true;
  int choice;
  cout << "Entering Queens" << endl;
  do
    {
      subMenuKQ ();
      cout << endl << "Make your choice: ";
      cin >> choice;
      choice = validatemenu (choice);
      AGAIN = callNQ (choice);

    }
  while (AGAIN);

}
/////////////////////////////////////////////////////////////templates game menu end//////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////inheritance menu start///////////////////////////////////////////////////////////
//validate inheritance menu
int menu::validateInheritance (int choice) {
  while (((choice < 1) || (choice > 4)) || cin.fail ())
    {
        cin.clear ();
        cin.ignore (numeric_limits < streamsize >::max (), '\n');
        cout << "You have entered wrong input." << endl;
        cin >> choice;
    }
  return choice;
}

//lets you enter inheritance menu or do it again
bool menu::pickedTaskInheritance (int choice) {
    bool AGAIN = true;

    enum Options { IMeaning=1, IExample, SHAPE, EXIT };

    switch (choice) {
      case IMeaning:
          cout << "Enter Inheritance Sub Menu" << endl <<endl;
          cout << "The benefits of classes is reusability, protecting data." << endl <<endl;
          break;

      case IExample:
          cout << "Enter Inheritance Sub Menu" << endl <<endl;
          cout << "Real life example of Inheritance." << endl;
          cout << "PUT SOMETHING HERE" << endl<<endl;
          break;

      case SHAPE:
          cout << "Enter Shapes" << endl;
          shapemenu ();
          break;

      case EXIT:
          cout << "Exiting Inheritance." << endl << endl;
          AGAIN = false;
    }

  return AGAIN;
}

//Inheritance menu
void menu::inheritanceMenu () {
  bool AGAIN = true;
  int choice;
  cout << "Entering templates menu" << endl;
  do
    {
      inheritanceHome ();
      cout << endl << "Make your choice: ";
      cin >> choice;
      choice = validateInheritance (choice);
      AGAIN = pickedTaskInheritance (choice);

    }
  while (AGAIN);

}
/////////////////////////////////////////////////////////////inheritance menu end/////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////shapes menu start///////////////////////////////////////////////////////////

//validate game shapes
int menu::validateShapesMenu (int choice) {
  while (((choice < 1) || (choice > 6)) || cin.fail ())
    {
        cin.clear ();
        cin.ignore (numeric_limits < streamsize >::max (), '\n');
        cout << "You have entered wrong input." << endl;
        cin >> choice;
    }
  return choice;
}

//shapes game menu
void menu::shapemenu () {
  bool AGAIN = true;
  int choice;
  cout << "Entering Knight tour" << endl;
  do
    {
      subMenuShape ();
      cout << endl << "Make your choice: ";
      cin >> choice;
      choice = validateShapesMenu (choice);
      AGAIN = callShape (choice);

    }
  while (AGAIN);

}

//run knight tour or exit
bool menu::callShape (int choice) {
    quadrilateral quad;
    rectangle Rec;
    square squar;
    parallelogram para;
    trapezoid trap;
    bool AGAIN = true;

  enum OPTIONS {RunQuadrilateral = 1, RunTrapezoid, RunRectangle, RunParallelogram, RunSquare, EXIT};

  switch (choice)
    {
    case RunQuadrilateral:
        cout << "Enter Quadrilateral's SM." << endl <<endl;
        quad.setNumY(5, 6, 9, 2);
        quad.setNumX(4, 1, 9, 10);
        cout << "Coordinates of Quadrilateral are:" <<endl;
        quad.print();
        break;

    case RunTrapezoid:
        cout << "Enter Trapezoid's SM." << endl <<endl;
        trap.setNumY(0, 0, 5, 5);
        trap.setNumX(0, 10, 8, 3.3);
        cout << "Coordinates of Trapezoid are:" <<endl;
        trap.print();
        cout <<  "Height is: " <<  trap.getHeightT() << endl;
        cout << "Width is: " << trap.getWidthT() << endl;
        cout << "Area is: " << trap.areaT() << endl;
        break;

    case RunRectangle:
        cout << "Enter Rectangle's SM." << endl <<endl;
        Rec.setNumY(14, 14, 28, 28);
        Rec.setNumX(17, 17, 30, 30);
        cout << "Coordinates of Rectangle are:" <<endl;
        Rec.print();
        cout <<  "Height is: " <<  Rec.setHeightRec() << endl;
        cout << "Width is: " << Rec.setWidthRec() << endl;
        cout << "Area is: " << Rec.getAreaR() << endl;
        break;

    case RunParallelogram:
        cout << "Enter Parallelogram's SM." << endl <<endl;
        para.setNumY(5, 5, 20, 20);
        para.setNumX(5, 11, 12, 6);
        cout << "Coordinates of Parallelogram are:" <<endl;
        para.print();
        cout <<  "Height is: " <<  para.getHeightP() << endl;
        cout << "Width is: " << para.getWidthP() << endl;
        cout << "Area is: " << para.areaP() << endl;
        break;

    case RunSquare:
        cout << "Enter Square's SM." << endl <<endl;
        squar.setNumY(0, 0, 4, 4);
        squar.setNumX(4,8,8,4);
        cout << "Coordinates of Square are:" <<endl;
        squar.print();
        cout << "Side is: " << squar.getSide() <<endl;
        cout << "Area is: " << squar.areaS() <<endl;
        break;

    case EXIT:
        cout << "Exiting... Shape's SM!" << endl << endl;
        AGAIN = false;
    }
  return AGAIN;
}

///////////////////////////////////////////////////////////////////shapes menu end/////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////overloading menu start///////////////////////////////////////////////////////////
//overloading menu
int menu::validateOverloading (int choice) {
  while (((choice < 1) || (choice > 5)) || cin.fail ())
    {
        cin.clear ();
        cin.ignore (numeric_limits < streamsize >::max (), '\n');
        cout << "You have entered wrong input." << endl;
        cin >> choice;
    }
  return choice;
}

//lets you enter overloading menu or do it again
bool menu::pickedTaskOverloading (int choice) {
    bool AGAIN = true;

    enum Options { OMeaning=1, OExample, OneDimeArr, TwoDimeArr, EXIT };

    switch (choice) {
      case OMeaning:
          cout << "Enter Overloading Sub Menu" << endl <<endl;
          cout << "The benefits of classes is reusability, protecting data." << endl <<endl;
          break;

      case OExample:
          cout << "Enter Overload Sub Menu" << endl <<endl;
          cout << "Real life example of Overloading." << endl;
          cout << "A family shares a last name. However if you want a certain person from the family" << endl;
          cout << "you need their first name as well as the last name." <<endl;
          cout << "Furthermore, a person can also have a middle name or nickname." <<endl <<endl;
          break;

      case OneDimeArr:
          cout << "Enter One Dimensional Arrays" << endl;
          subMenuODA ();
          break;

      case TwoDimeArr:
          cout << "Enter Two Dimensional Arrays" << endl;
          subMenuTDA ();
          break;
          
      case EXIT:
          cout << "Exiting Overloading." << endl << endl;
          AGAIN = false;
    }

  return AGAIN;
}

//overloading menu
void menu::overloadingMenu () {
  bool AGAIN = true;
  int choice;
  cout << "Entering overloading menu" << endl;
  do
    {
      overloadingHome ();
      cout << endl << "Make your choice: ";
      cin >> choice;
      choice = validateOverloading (choice);
      AGAIN = pickedTaskOverloading (choice);

    }
  while (AGAIN);

}
/////////////////////////////////////////////////////////////overloading menu start///////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////print statements start///////////////////////////////////////////////////////////
//welcome message
void menu::welcome () {
    cout << "Welcome to the games menu." << endl;
}

//show home menu statements
void menu::home () {
    cout << "1. Classes" << endl;
    cout << "2. Templates" << endl;
    cout << "3. Inheritance" << endl;
    cout << "4. Overloading" << endl;
    cout << "5. Exit" << endl;
}

//classes menu statements
void menu::classesHome () {
    cout << endl;
    cout << "1. Benefits of Overloading" << endl;
    cout << "2. Real life example of Overloading." << endl;
    cout << "3. Exit clases" << endl;
}

//show games/templates menu statements
void menu::gameHome () {
    cout << "1. Benefits of Templates" << endl;
    cout << "2. Real life example of Templates." << endl;
    cout << "3. Queens" << endl;
    cout << "4. Knight Tour" << endl;
    cout << "5. Exit" << endl;
}

//submenu knight and queen statements
void menu::subMenuKQ () {
    cout << endl;
    cout << "1. Run Game" << endl;
    cout << "2. Exit Game" << endl;
}

//show inheritance menu statements
void menu::inheritanceHome () {
    cout << "1. Benefits of Inheritance" << endl;
    cout << "2. Real life example of Inheritance." << endl;
    cout << "3. Shapes" << endl;
    cout << "4. Exit" << endl;
}

//submenu for shapes statements
void menu::subMenuShape () {
    cout << endl;
    cout << "press 1: to find the area of quadrilateral" << endl << "press 2: to find the area of trapezoid" << endl;
    cout << "press 3: to find the area of rectangle" << endl << "press 4: to find the area of parallelogram" <<endl;
    cout << "press 5: to find the area of square" << endl <<"press 6: to exit math game" <<endl;
}

//show Overloading menu statements
void menu::overloadingHome () {
    cout << "1. Benefits of Overloading" << endl;
    cout << "2. Real life example of Overloading." << endl;
    cout << "3. One Dimensional Arrays" << endl;
    cout << "4. Two Dimensional Arrays" << endl;
    cout << "5. Exit" << endl;
}

//show one dime arr statement
void menu::subMenuODA() {
    cout << endl;
    OneDimensional integers1(7);
    OneDimensional integers2;

    cout << "size of array integers1 is " << integers1.getSize()<< "\narray after initialization:\n" << integers1;
    cout << "size of array integers2 is " << integers2.getSize()<< "\narray after initialization:\n" << integers2;

    //add random number or user input
    // >> op
    cout << "\nenter 17 integers:" <<endl;
    cin >> integers1 >> integers2;

    // << op
    cout << "\nafter input, the array contain:\n" << "integers1:\n" << integers1 << "integers2:\n" << integers2;
    cout << "\nevaluating: integers1 != integers2"<<endl;

    if(integers1!=integers2){
        cout << "integers1 and integers2 are not equal" <<endl;
    }

    OneDimensional integers3(integers1);
    cout << "\nsize of array integers3 is " << integers3.getSize()<<"\narray initialization:\n"<< integers3;
    
    cout <<"\nassigning integers2 to integers1:" <<endl;
    cout << "integers1:\n" << integers1 << "integers2:\n" << integers2;

    cout << "\nevaluating: integers1 = integers2" <<endl;

    if(integers1==integers2){
        cout << "integers1 and integers2 are equal" <<endl;
    }

    cout << "\nintegers1[5] is "<<integers1[5];
    cout << "\n\nassigning 1000 to integers1[5]"<<endl;
    integers1[5]=1000;
    cout << "integers1:\n"<<integers1;

    cout <<"\nattempt to assign 1000 to integers1[15]"<<endl;
    integers1[15]=1000;
}

//show two dime arr statement
void menu::subMenuTDA() {
    int row, col, row2, col2;

    //int 1
    cout << "Enter the size for the row and col integers1's matrix. Must be lower than 10x10" << endl;
    cin >> row >>  col;
    while(row>=10&&col>=10){
      cout << "Enter the size for the row and col integers1's matrix. Must be lower than 10x10" << endl;
      cin >> row >>  col;
    }
    TwoDimensional integers1(row, col);
    
    // int2
    cout << "Enter the size for the row and col integers2's matrix. Must be lower than 10x10" << endl;
    cin >> row2 >>  col2;
    while(row2>=10&&col2>=10){
      cout << "Enter the size for the row and col integers2's matrix. Must be lower than 10x10" << endl;
      cin >> row2 >>  col2;
    }
    TwoDimensional integers2(row2, col2);
    
    cout << "size of array integers1 is " << integers1.getRowSize()<< "col " << integers1.getColSize() << "\narray after initialization:\n" << integers1;
    cout << "size of array integers2 is " << integers2.getRowSize()<< "col " << integers2.getColSize()<< "\narray after initialization:\n" << integers2;

    //add random number or user input
    // >> op
    //cout << "\nenter 17 integers:" <<endl;
    cin >> integers1 >> integers2;

    // << op
    cout << "\nafter input, the array contain:\n" << "integers1:\n" << integers1 << "integers2:\n" << integers2;
    cout << "\nevaluating: integers1 != integers2"<<endl;

    if(integers1!=integers2){
        cout << "integers1 and integers2 are not equal" <<endl;
    }

    TwoDimensional integers3(row, col);
    cout << "\nsize of array integers3 is " << integers3.getRowSize()<< "col " << integers3.getColSize()<<"\narray initialization:\n"<< integers3;
    
    cout <<"\nassigning integers2 to integers1:" <<endl;
    cout << "integers1:\n" << integers1 << "integers2:\n" << integers2;

    cout << "\nevaluating: integers1 = integers2" <<endl;

    if(integers1==integers2){
        cout << "integers1 and integers2 are equal" <<endl;
    }

    cout << "\nintegers1[5] is "<<integers1[5];
    cout << "\n\nassigning 1000 to integers1[5]"<<endl;
    integers1[5]=1000;
    cout << "integers1:\n"<<integers1;

    cout <<"\nattempt to assign 1000 to integers1[15]"<<endl;
    integers1[15]=1000;
}
/////////////////////////////////////////////////////////////print statements end///////////////////////////////////////////////////////////
    