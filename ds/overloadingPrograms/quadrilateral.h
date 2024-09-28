#include <iostream>
#pragma once
using namespace std;
//parent quad
class quadrilateral {
    public:

    //set functions
    double setNumY(int snumY, int snumY2, int snumY3, int snumY4){
        numY=snumY;
        numY2=snumY2;
        numY3=snumY3;
        numY4=snumY4;
    }   
    double setNumX(int snumX, int snumX2, int snumX3, int snumX4){
        numX=snumX;
        numX2=snumX2;
        numX3=snumX3;
        numX4=snumX4;
    }

    //pair 1
    double getNumX(){
        return numX;
    }
    double getNumY(){
        return numY;
    }
    //pair 2
    double getNumX2(){
        return numX2;
    }
    double getNumY2(){
        return numY2;
    }
    //pair 3
    double getNumX3(){
        return numX3;
    }
    double getNumY3(){
        return numY3;
    }
    //pair 4
    double getNumX4(){
        return numX4;
    }
    double getNumY4(){
        return numY4;
    }

    //print sides
    void print(){
        cout << "side one: " <<getNumX() << ' ' << getNumY() <<endl;
        cout << "side two: " <<getNumX2() << ' ' << getNumY2() <<endl;
        cout << "side three: " <<getNumX3() << ' ' << getNumY3() <<endl;
        cout << "side four: " <<getNumX4() << ' ' << getNumY() <<endl;
    }
    protected:
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