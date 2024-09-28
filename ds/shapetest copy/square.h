//#ifndef SQUARE_H
//#define SQUARE_H
#include <iostream>
//#pragma once
#include "quadrilateral.h"
using namespace std;

class square: public quadrilateral{
    public:

    //sides
    double getSide();
    //area
    double areaS();

 };
 //#endif