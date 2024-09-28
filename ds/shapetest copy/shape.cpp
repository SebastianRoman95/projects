#include <iostream>
#include "rectangle.h"
#include "square.h"
#include "parallelogram.h"
#include "trapezoid.h"
#ifndef _QUADRILATERAL_H
#define _QUADRILATERAL_H

using namespace std;

int main() {
   quadrilateral quad;
   rectangle Rec;
   square squar;
   parallelogram para;
   trapezoid trap;

   //quad
   quad.setNumY(5, 6, 9, 2);
   quad.setNumX(4, 1, 9, 10);
   cout << "Coordinates of Quadrilateral are:" <<endl;
   quad.print();

   //trap
   trap.setNumY(0, 0, 5, 5);
   trap.setNumX(0, 10, 8, 3.3);
   cout << "Coordinates of Trapezoid are:" <<endl;
   trap.print();
   cout <<  "Height is: " <<  trap.getHeightT() << endl;
   cout << "Width is: " << trap.getWidthT() << endl;
   cout << "Area is: " << trap.areaT() << endl;

   //Rec
   Rec.setNumY(14, 14, 28, 28);
   Rec.setNumX(17, 17, 30, 30);
   cout << "Coordinates of Rectangle are:" <<endl;
   Rec.print();
   cout <<  "Height is: " <<  Rec.setHeightRec() << endl;
   cout << "Width is: " << Rec.setWidthRec() << endl;
   cout << "Area is: " << Rec.getAreaR() << endl;

   //para
   para.setNumY(5, 5, 20, 20);
   para.setNumX(5, 11, 12, 6);
   cout << "Coordinates of Parallelogram are:" <<endl;
   para.print();
   cout <<  "Height is: " <<  para.getHeightP() << endl;
   cout << "Width is: " << para.getWidthP() << endl;
   cout << "Area is: " << para.areaP() << endl;

   //square
   squar.setNumY(0, 0, 4, 4);
   squar.setNumX(4,8,8,4);
   cout << "Coordinates of Square are:" <<endl;
   cout << "Side is: " << squar.getSide() <<endl;
   cout << "Area is: " << squar.areaS() <<endl;

}

#endif