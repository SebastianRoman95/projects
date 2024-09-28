#ifndef SQUARE_H
#define SQUARE_H
#include "quadrilateral.h"
#include <iostream>
using namespace std;

//child square class
template<typename T=double>
class square: public quadrilateral<T>{
    template<typename U>
    friend ostream &operator<<(ostream&, const square<U>&);
    template<typename U>
    friend istream &operator>>(istream&, square<U>&);

    public:
    square(const T& numX=1, const T& numY=1,const T& numX2=2, const T& numY2=2,
    const T& numX3=3, const T& numY3=3,const T& numX4=4, const T& numY4=4);
    square(const square&);
    ~square();
    
    //sides
    T getSide();
    //area
    T areaS();
 };
  #endif