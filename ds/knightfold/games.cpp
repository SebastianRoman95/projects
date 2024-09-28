#include<iostream>
#include "knight.cpp"
#include "queen.cpp"
#include "quadrilateral.h"
#include "square.h"
#include "parallelogram.h"
#include "rectangle.h"
#include "trapezoid.h"
using namespace std;

int main() {
   //var 
   int pickgame=0, gameback=0;
   while(pickgame!=4){
      //var reset
      pickgame=0, gameback=0;
      //statement
      cout << "pick a game you want to play." << endl << "1 for knights tour:" << endl << "2 for N queens:" << endl;
      cout << "3 for Math Game: "<< endl << "4 for exit games:" << endl;
      cin >> pickgame;

      if(pickgame==1){//knight
         while(gameback!=2){
            gameback=0;
            //statement
            cout << "to play knights tour press 1 or press 2 to exit knights tour." << endl;
            cin >> gameback;
            if(gameback==1){
               solution();
            }
         } 
      }
      else if(pickgame==2){//queen
         while(gameback!=2){
            //var reset
            gameback=0;
            //statement
            cout << "to play queen press 1 or press 2 to exit queen." << endl;
            cin >> gameback;
            if(gameback==1){
               queenSolution();
            }
         } 
      }
      else if (pickgame==3){
         //objects
         quadrilateral quad;
         rectangle Rec;
         square squar;
         parallelogram para;
         trapezoid trap;

         while(gameback!=6){
            //var reset
            gameback=0;
            //statement
            cout << "press 1: to find the area of quadrilateral" << endl << "press 2: to find the area of trapezoid" << endl;
            cout << "press 3: to find the area of rectangle" << endl << "press 4: to find the area of parallelogram" <<endl;
            cout << "press 5: to find the area of square" << endl <<"press 6: to exit math game" <<endl;
            cin >> gameback;

            if(gameback==1){
               //quad
               quad.setNumY(5, 6, 9, 2);
               quad.setNumX(4, 1, 9, 10);
               cout << "Coordinates of Quadrilateral are:" <<endl;
               quad.print();
            }
            else if (gameback==2){
               //trap
               trap.setNumY(0, 0, 5, 5);
               trap.setNumX(0, 10, 8, 3.3);
               cout << "Coordinates of Trapezoid are:" <<endl;
               trap.print();
               cout <<  "Height is: " <<  trap.getHeightT() << endl;
               cout << "Width is: " << trap.getWidthT() << endl;
               cout << "Area is: " << trap.areaT() << endl;
            }
            else if(gameback==3){
               //Rec
               Rec.setNumY(14, 14, 28, 28);
               Rec.setNumX(17, 17, 30, 30);
               cout << "Coordinates of Rectangle are:" <<endl;
               Rec.print();
               cout <<  "Height is: " <<  Rec.setHeightRec() << endl;
               cout << "Width is: " << Rec.setWidthRec() << endl;
               cout << "Area is: " << Rec.getAreaR() << endl;
            }
            else if (gameback==4){
               //para
               para.setNumY(5, 5, 20, 20);
               para.setNumX(5, 11, 12, 6);
               cout << "Coordinates of Parallelogram are:" <<endl;
               para.print();
               cout <<  "Height is: " <<  para.getHeightP() << endl;
               cout << "Width is: " << para.getWidthP() << endl;
               cout << "Area is: " << para.areaP() << endl;
            }
            else if (gameback==5){
               //square
               squar.setNumY(0, 0, 4, 4);
               squar.setNumX(4,8,8,4);
               cout << "Coordinates of Square are:" <<endl;
               squar.print();
               cout << "Side is: " << squar.getSide() <<endl;
               cout << "Area is: " << squar.areaS() <<endl;
            }
         }//end math game       
      }//end math game select       
   }//end of game select  
}