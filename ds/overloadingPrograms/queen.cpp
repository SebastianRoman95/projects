#include<iostream>
#include"queen.h"
using namespace std;
#define queenBoardSize 8

//board
template<typename pieceQueen=int>
void printBoard(pieceQueen queenBoard[queenBoardSize][queenBoardSize]) {
   for (pieceQueen i = 0; i < queenBoardSize; i++) {
      for (pieceQueen j = 0; j < queenBoardSize; j++) {
         cout << queenBoard[i][j] << " ";
      }
      cout << endl;
   }
}

//valid spot
template<typename pieceQueen, typename checkQueen = bool>
checkQueen queenValid(pieceQueen queenBoard[queenBoardSize][queenBoardSize], pieceQueen row, pieceQueen col) {
   //check col
   for (pieceQueen i = 0; i < col; i++) {
      if (queenBoard[row][i]) {
         return false;
      }
    }

   //check cross 
   for (pieceQueen i=row, j=col; i>=0 && j>=0; i--, j--) {
      if (queenBoard[i][j]) {
         return false;
      }
   }

   //check row 
   for (pieceQueen i=row, j=col; j>=0 && i<queenBoardSize; i++, j--) {
      if (queenBoard[i][j]) {
         return false;
      }
   }
   return true;
}

//how many solve
template<typename pieceQueen, typename checkQueen = bool>
checkQueen queenSolve(pieceQueen queenBoard[queenBoardSize][queenBoardSize], pieceQueen col) {
   if (col >= queenBoardSize) {
      return true;
   }

   for (pieceQueen i = 0; i < queenBoardSize; i++) { 
      if (queenValid(queenBoard, i, col) ) {
         queenBoard[i][col] = 1; 
         if ( queenSolve(queenBoard, col + 1)) {
            return true;
         }
         queenBoard[i][col] = 0; 
      }
   }
   return false; 
}

//print winning board
template<typename checkQueen = bool>
checkQueen queenSolution() {
   int queenBoard[queenBoardSize][queenBoardSize];
   for(int i = 0; i<queenBoardSize; i++){
        for(int j = 0; j<queenBoardSize; j++){
            queenBoard[i][j] = 0; 
        }
   }

   if (queenSolve(queenBoard, 0) == false ) { 
        cout << "Solution does not exist";
        return false;
    }
    printBoard(queenBoard);
    return true;
}
