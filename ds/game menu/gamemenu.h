#include <iostream>
//#pragma once
#include<iostream>
#include<limits>
#include "knight.cpp"
#include "queen.cpp"
#include "quadrilateral.h"
#include "square.h"
#include "parallelogram.h"
#include "rectangle.h"
#include "trapezoid.h"
using namespace std;
//parent quad
class gamemenu {
    public:
gamemenu ();
//validate Home
int validateHome (int choice);
//lets you enter game menu or do it again
bool pickedGame (int choice);
//end of home menu

//validate game knight and queen
int validateGameMenu (int choice);
//knight tour game menu
void KTGameMenu ();
//queen game menu
void NQGameMenu ();
//run knight tour or exit
bool callKT (int choice);
//run queens or exit
bool callNQ (int choice);
//validate game shapes
int validatemShapesMenu (int choice);
//shapes game menu
void shapeGameMenu ();
//run knight tour or exit
bool callShape (int choice);
//print statements
//welcome message
void welcome ();
//show games menu
void home ();
//submenu knight and queen
void subMenuKQ ();
void subMenuShape ();
    
};
