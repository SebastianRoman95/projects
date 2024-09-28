#include<iostream>
#include<limits>
#include "menu.cpp"
using namespace std;

int main() {

   bool AGAIN = true;
   int choice = 0;
   menu gm;
   gm.welcome ();
   do
      {
         gm.home ();
         cout << endl << "Make your choice: ";
         cin >> choice;
         choice = gm.validateHome (choice);
         AGAIN = gm.picktask (choice);

      }
   while (AGAIN);
   
}
