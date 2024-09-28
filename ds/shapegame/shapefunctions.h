#include <iostream>
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

//child para class
class parallelogram: public quadrilateral{
    public:

    //width
    double getWidthP(){
        double left=0;
        left = abs(numX-numX2);
        return left;
    }

    //height
    double getHeightP(){
        double highx=0, lowx=0; 

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
    double areaP(){
        return getHeightP()*getWidthP();
    }
 };

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

//child square class
class square: public quadrilateral{
    public:

    //sides
    double getSide(){
        double highx=0, lowx=0; 

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
    double areaS(){
        return getSide()*4;
    }
 };

//child trap class
class trapezoid: public quadrilateral{
    public:

    //width 
    double getWidthT(){
        double left=0;
        double right=0;
        left = abs(numX-numX2);
        right = abs(numX3-numX4);
        return left+right;
    }

    //height
    double getHeightT(){
        double highx=0, lowx=0; 

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
    double areaT(){
        return (getHeightT()*getWidthT())/2;
    }
};