#ifndef TRAPEZOID_H
#define TRAPEZOID_H
#include "quadrilateral.h"
#include <iostream>
using namespace std;

//child trap class
template<typename T=double>
class trapezoid: public quadrilateral<T>{
    template<typename U>
    friend ostream &operator<<(ostream&, const square<U>&);
    template<typename U>
    friend istream &operator>>(istream&, square<U>&);

    public:
    trapezoid(const T& numX=1, const T& numY=1,const T& numX2=2, const T& numY2=2,
    const T& numX3=3, const T& numY3=3,const T& numX4=4, const T& numY4=4);
    trapezoid(const trapezoid&);
    ~trapezoid();

    //width 
    T getWidthT();
    //height
    T getHeightT();
    //area 
    T areaT();
};
  #endif