#include<iostream>
#include<limits>
#include "overloadmenu.h"
using namespace std;

int main() {

   bool AGAIN = true;
   int choice = 0;
   overloadArray ol;
   ol.welcome ();
   do
      {
         ol.home ();
         cout << endl << "Make your choice: ";
         cin >> choice;
         choice = ol.validateHome (choice);
         AGAIN = ol.pickedTask (choice);

      }
   while (AGAIN);
   
   return 0;
}