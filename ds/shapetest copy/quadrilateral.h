//#ifndef QUADRILATERAL_H
//#define QUADRILATERAL_H
#pragma once
#include <iostream>
using namespace std;

class quadrilateral {
    public:

    //set var
    double setNumY(int snumY, int snumY2, int snumY3, int snumY4);
    double setNumX(int snumX, int snumX2, int snumX3, int snumX4);

    //pair 1
    double getNumX();
    double getNumY();
    //pair 2
    double getNumX2();
    double getNumY2();
    //pair 3
    double getNumX3();
    double getNumY3();
    //pair 4
    double getNumX4();
    double getNumY4();

    void print();
    
    private:
    //var
    double numX;
    double numY;
    double numX2;
    double numY2;
    double numX3;
    double numY3;
    double numX4;
    double numY4;
};
//#endif