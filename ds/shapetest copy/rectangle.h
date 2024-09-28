//#ifndef RECTANGLE_H
//#define RECTANGLE_H
#include <iostream>
//#pragma once
#include "quadrilateral.h"
using namespace std;

class rectangle: public quadrilateral {
    public:

    //width
    double setWidthRec();
    //height
    double setHeightRec();
    //area
    double getAreaR();

};
//#endif