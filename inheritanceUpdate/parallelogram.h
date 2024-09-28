#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H
#include "quadrilateral.h"
#include <iostream>
using namespace std;

//child para class
template<typename T=double>
class parallelogram: public quadrilateral<T>{
    template<typename U>
    friend ostream &operator<<(ostream&, const parallelogram<U>&);
    template<typename U>
    friend istream &operator>>(istream&, parallelogram<U>&);

    public:
    parallelogram(const T& numX=1, const T& numY=1,const T& numX2=2, const T& numY2=2,
    const T& numX3=3, const T& numY3=3,const T& numX4=4, const T& numY4=4);
    parallelogram(const parallelogram&);
    ~parallelogram();
    //width
    T getWidthP();
    //height
    T getHeightP();
    //area
    T areaP();
 };
 #endif