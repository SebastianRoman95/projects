#include <iostream>
#include <iomanip>
#include "knight.h"
#define boardSize 8
using namespace std;

//template<class piece> 
int sol[boardSize][boardSize];

template<typename piece, typename check = bool>
check valid(piece row, piece col, piece sol[boardSize][boardSize]) {     
   return ( row >= 0 && row < boardSize && col >= 0 && col < boardSize && sol[row][col] == -1);
}

//print board
template<typename piece=int> 
void print() {
   for (piece row = 0; row < boardSize; row++) {
      for (piece col = 0; col < boardSize; col++){
         cout << setw(3) << sol[row][col] << " ";
      }
      cout << endl;
   }
}

//playing game
template<typename piece> 
piece knightTour(piece row, piece col, piece move, piece sol[boardSize][boardSize], piece rowMove[boardSize], piece colMove[boardSize]) {
   piece xNext, yNext;
   if (move == boardSize*boardSize) {
      return true;
   }

   for (int k = 0; k < 8; k++) {
      xNext = row + rowMove[k];
      yNext = col + colMove[k];
      if (valid(xNext, yNext, sol)) {
         sol[xNext][yNext] = move;
         if (knightTour(xNext, yNext, move+1, sol, rowMove, colMove) == true) {
            return true;
         }
         else {
            sol[xNext][yNext] = -1;
         }
      }
   }
   return false;
}

//solution
template<typename check = bool>
check solution() {
   for (int row = 0; row < boardSize; row++) {     
      for (int col = 0; col < boardSize; col++) {
         sol[row][col] = -1;
      }
   }

   //moves knight and start
   int rowMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
   int colMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
   sol[0][0]  = 0;     

   if (knightTour(0, 0, 1, sol, rowMove, colMove) == false) {
      cout << "Solution does not exist";
      return false;
   }
   else {
      print();
   }
   return true;
}