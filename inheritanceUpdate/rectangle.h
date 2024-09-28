#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "quadrilateral.h"
#include <iostream>
using namespace std;

//child rec class
template<typename T=double>
class rectangle: public quadrilateral<T> {
    template<typename U>
    friend ostream &operator<<(ostream&, const rectangle<U>&);
    template<typename U>
    friend istream &operator>>(istream&, rectangle<U>&);
    
    public:
    rectangle(const T& numX=1, const T& numY=1,const T& numX2=2, const T& numY2=2,
    const T& numX3=3, const T& numY3=3,const T& numX4=4, const T& numY4=4);
    rectangle(const rectangle&);
    ~rectangle();
    //width
    T setWidthRec();
    //height
    T setHeightRec();
    //area
    T getAreaR();
};
  #endif