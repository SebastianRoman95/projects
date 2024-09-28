#include "rectangle.h"
//#include "quadrilateral.h"
#include <iostream>
using namespace std;

//width
    double rectangle::setWidthRec(){
        double high=0, low=0;// widthy=0;

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
        
        //cout <<numY << ' ' << numY2 << ' ' << numY3 << ' ' << numY4 <<endl;
        //cout << 'w' <<high - low << endl;
        return high - low;
    }

    //height
    double rectangle::setHeightRec(){
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

        //cout << 'h' << ' ' <<numX << ' ' << numX2 << ' ' << numX3 << ' ' << numX4 <<endl;
        //height = ;
        //cout <<'h'<< highx - lowx <<endl;
        return highx - lowx;
    }

    double rectangle::getAreaR() { 
        return (setHeightRec() * setWidthRec()); 
    }