#include <iostream>
#include "square.h"
//#include "quadrilateral.h"
using namespace std;

double square::getSide(){
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

    double square::areaS(){
        return getSide()*4;
    }