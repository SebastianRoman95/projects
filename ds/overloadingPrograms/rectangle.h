#include "quadrilateral.h"
#include <iostream>
using namespace std;

//child rec class
class rectangle: public quadrilateral {
    public:

    //width
    double setWidthRec(){
        double high=0, low=0;

        //high
        if(numY>=numY2&&numY>=numY3&&numY>=numY4){
            high=numY;//point 1
        }
        else if(numY2>=numY&&numY2>=numY3&&numY2>=numY4){
            high=numY;//point 2
        }
        else if(numY3>=numY2&&numY3>=numY&&numY3>=numY4){
            high=numY;//point 3
        }
        else if(numY4>=numY2&&numY4>=numY3&&numY4>=numY){
            high=numY4;//point 4
        }
        //low
        if(numY<=numY2&&numY<=numY3&&numY<=numY4){
            low=numY;//point 1
        }
        else if(numY2<=numY&&numY2<=numY3&&numY2<=numY4){
            low=numY;//point 2
        }
        else if(numY3<=numY2&&numY3<=numY&&numY3<=numY4){
            low=numY;//point 3
        }
        else if(numY4<=numY2&&numY4<=numY3&&numY4<=numY){
            low=numY4;//point 4
        }
        return high - low;
    }

    //height
    double setHeightRec(){
        double highx=0, lowx=0; //heightx;

        //high
        if(numX>=numX2&&numX>=numX3&&numX>=numX4){
            highx=numX;//point 1
        }
        else if(numX2>=numX&&numX2>=numX3&&numX2>=numX4){
            highx=numX2;//point 2
        }
        else if(numX3>=numX&&numX3>=numX2&&numX3>=numX4){
            highx=numX3;//point 3
        }
        else if(numX4>=numX&&numX4>=numX2&&numX4>=numX3){
            highx=numX4;//point 4
        }
        //low
        if(numX<=numX2&&numX<=numX3&&numX<=numX4){
            lowx=numX;//point 1
        }
        else if(numX2<=numX&&numX2<=numX3&&numX2<=numX4){
            lowx=numX2;//point 2
        }
        else if(numX3<=numX&&numX3<=numX2&&numX3<=numX4){
            lowx=numX3;//point 3
        }
        else if(numX4<=numX&&numX4<=numX2&&numX4<=numX3){
            lowx=numX4;//point 4
        }
        return highx - lowx;
    }

    //area
    double getAreaR() { 
        return (setHeightRec() * setWidthRec()); 
    }
};