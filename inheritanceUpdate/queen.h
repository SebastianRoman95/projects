#include<iostream>
using namespace std;
#define queenBoardSize 8

template<typename pieceQueen, typename checkQueen = bool>
class queen{
    public:
    void printBoard(pieceQueen board[queenBoardSize][queenBoardSize]);
    checkQueen queenValid(pieceQueen board[queenBoardSize][queenBoardSize], pieceQueen row, pieceQueen col);
    checkQueen queenSolve(pieceQueen board[queenBoardSize][queenBoardSize], pieceQueen col); 
    checkQueen queenSolution();
};