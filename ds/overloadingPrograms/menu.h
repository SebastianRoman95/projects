#include <iostream>
#include<limits>
#include "knight.cpp"
#include "queen.cpp"
#include "quadrilateral.h"
#include "square.h"
#include "parallelogram.h"
#include "rectangle.h"
#include "trapezoid.h"
#include "OneDimensional.cpp"
#include "TwoDimensional.cpp"
using namespace std;

class menu {
    public:
menu ();

//validate Home
int validateHome (int choice);
bool picktask(int choice);

//classes
int validateClasses (int choice);
bool pickedTaskClasses (int choice);
void classesMenu ();

//templates menu
int validateGames (int choice);
bool pickedGame (int choice);
void templatesMenu ();

//validate game knight and queen
int validatemenu (int choice);
//knight tour 
bool callKT (int choice);
void KTmenu ();
//queen 
void NQmenu ();
bool callNQ (int choice);

//Inheritance menu
int validateInheritance (int choice);
bool pickedTaskInheritance (int choice);
void inheritanceMenu ();

//shapes
void shapemenu ();
bool callShape (int choice);
int validateShapesMenu (int choice);

//overload menu
int validateOverloading (int choice);
bool pickedTaskOverloading (int choice);
void overloadingMenu ();

//print statements
//welcome message
void welcome ();
//show games menu
void home ();
//classes
void classesHome ();
//templates
void gameHome ();
void subMenuKQ ();
//inheritance
void inheritanceHome ();
void subMenuShape ();
//overloading
void overloadingHome ();
void subMenuODA();
void subMenuTDA();
    
};
