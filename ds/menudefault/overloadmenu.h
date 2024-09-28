#ifndef OVERLOADMENU_H
#define OVERLOADMENU_H
#include <iostream>
#include<limits>
using namespace std;

class overload {
    public:

overload();
int validateHome (int choice);
bool pickedTask (int choice);
int validateOL (int choice);
void OLGameMenu ();
bool callOL (int choice);
void welcome ();
void home ();
void subMenuOL();
    
};
#endif