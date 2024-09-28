#include <iostream>
//#pragma once
#include<iostream>
#include<limits>
#include "gamemenu.h"
using namespace std;
//parent quad

gamemenu::gamemenu(){

}

//validate Home
int gamemenu::validateHome (int choice) {
  while (((choice < 1) || (choice > 4)) || cin.fail ())
    {
        cin.clear ();
        cin.ignore (numeric_limits < streamsize >::max (), '\n');
        cout << "You have entered wrong input." << endl;
        cin >> choice;
    }
  return choice;
}

//lets you enter game menu or do it again
bool gamemenu::pickedGame (int choice) {
    bool AGAIN = true;

    enum Options { NQ = 1, KT, SHAPE, EXIT };

    switch (choice)
        {
        case NQ:
            cout << "Enter Queens." << endl;
            NQGameMenu ();
            break;

        case KT:
            cout << "Enter Knight Tour." << endl;
            KTGameMenu ();
            break;

        case SHAPE:
            cout << "Enter Shapes" << endl;
            shapeGameMenu ();
            break;

        case EXIT:
            cout << "Exiting game. Thank you for playing!" << endl << endl;
            AGAIN = false;

    }

  return AGAIN;
}
//end of home menu

//validate game knight and queen
int gamemenu::validateGameMenu (int choice) {
  while (((choice < 1) || (choice > 2)) || cin.fail ())
    {
        cin.clear ();
        cin.ignore (numeric_limits < streamsize >::max (), '\n');
        cout << "You have entered wrong input." << endl;
        cin >> choice;
    }
  return choice;
}

//knight tour game menu
void gamemenu::KTGameMenu () {
  bool AGAIN = true;
  int choice;
  cout << "Entering Knight tour" << endl;
  do
    {
      subMenuKQ ();
      cout << endl << "Make your choice: ";
      cin >> choice;
      choice = validateGameMenu (choice);
      AGAIN = callKT (choice);

    }
  while (AGAIN);

}

//queen game menu
void gamemenu::NQGameMenu () {
  bool AGAIN = true;
  int choice;
  cout << "Entering Queens" << endl;
  do
    {
      subMenuKQ ();
      cout << endl << "Make your choice: ";
      cin >> choice;
      choice = validateGameMenu (choice);
      AGAIN = callNQ (choice);

    }
  while (AGAIN);

}

//run knight tour or exit
bool gamemenu::callKT (int choice) {

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

//run queens or exit
bool gamemenu::callNQ (int choice) {

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

//validate game shapes
int gamemenu::validatemShapesMenu (int choice) {
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
void gamemenu::shapeGameMenu () {
  bool AGAIN = true;
  int choice;
  cout << "Entering Knight tour" << endl;
  do
    {
      subMenuShape ();
      cout << endl << "Make your choice: ";
      cin >> choice;
      choice = validatemShapesMenu (choice);
      AGAIN = callShape (choice);

    }
  while (AGAIN);

}

//run knight tour or exit
bool gamemenu::callShape (int choice) {
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

//print statements
//welcome message
void gamemenu::welcome () {
    cout << "Welcome to the games menu." << endl;
}

//show games menu
void gamemenu::home () {
    cout << "1. Queens" << endl;
    cout << "2. Knight Tour" << endl;
    cout << "3. Shape Game" << endl;
    cout << "4. Exit" << endl;
}

//submenu knight and queen
void gamemenu::subMenuKQ () {
    cout << endl;
    cout << "1. Run Game" << endl;
    cout << "2. Exit Game" << endl;
}

//submenu for shapes
void gamemenu::subMenuShape () {
    cout << endl;
    cout << "press 1: to find the area of quadrilateral" << endl << "press 2: to find the area of trapezoid" << endl;
    cout << "press 3: to find the area of rectangle" << endl << "press 4: to find the area of parallelogram" <<endl;
    cout << "press 5: to find the area of square" << endl <<"press 6: to exit math game" <<endl;
}
//end of print statements
    