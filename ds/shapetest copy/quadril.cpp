#include "quadrilateral.h"
#include <iostream>
using namespace std;

    double quadrilateral::setNumY(int snumY, int snumY2, int snumY3, int snumY4){
        numY=snumY;
        numY2=snumY2;
        numY3=snumY3;
        numY4=snumY4;
    }
    
    double quadrilateral::setNumX(int snumX, int snumX2, int snumX3, int snumX4){
        numX=snumX;
        numX2=snumX2;
        numX3=snumX3;
        numX4=snumX4;
    }

    //pair 1
    double quadrilateral::getNumX(){
        return numX;
    }
    double quadrilateral::getNumY(){
        return numY;
    }
    //pair 2
    double quadrilateral::getNumX2(){
        return numX2;
    }
    double quadrilateral::getNumY2(){
        return numY2;
    }
    //pair 3
    double quadrilateral::getNumX3(){
        return numX3;
    }
    double quadrilateral::getNumY3(){
        return numY3;
    }
    //pair 4
    double quadrilateral::getNumX4(){
        return numX4;
    }
    double quadrilateral::getNumY4(){
        return numY4;
    }

    void quadrilateral::print(){
        cout << "side one: " <<getNumX() << ' ' << getNumY() <<endl;
        cout << "side two: " <<getNumX2() << ' ' << getNumY2() <<endl;
        cout << "side three: " <<getNumX3() << ' ' << getNumY3() <<endl;
        cout << "side four: " <<getNumX4() << ' ' << getNumY() <<endl;
    }