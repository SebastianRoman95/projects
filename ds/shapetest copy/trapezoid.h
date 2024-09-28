//#ifndef TRAPEZOID_H
//#define TRAPEZOID_H
#include <iostream>
//#pragma once
#include "quadrilateral.h"
using namespace std;

class trapezoid: public quadrilateral{
    public:

    //width 
    double getWidthT();
    //height
    double getHeightT();
    //area 
    double areaT();
};
//#endif