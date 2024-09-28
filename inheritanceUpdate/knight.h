#include <iostream>
#include <iomanip>
#define boardSize 8

template<typename piece, typename check = bool>
class knight{
   public:
   check valid(piece row, piece col, piece sol[boardSize][boardSize]);
   void print();
   piece knightTour(piece row, piece col, piece move, piece sol[boardSize][boardSize], piece rowMove[boardSize], piece colMove[boardSize]);
   check solution();
};
