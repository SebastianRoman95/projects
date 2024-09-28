#include "square.h"
#include <iostream>

template<typename T>
square<T>::square(const T& numX, const T& numY, const T& numX2, const T& numY2,
const T& numX3, const T& numY3, const T& numX4, const T& numY4):quadrilateral<T>(numX, numY, numX2, numY2,
numX3, numY3, numX4, numY4){
}

//copy
template<typename T>
square<T>::square(const square<T> &squareToCopy){
}

//destructor
template<typename T>
square<T>::~square(){
    cout << "square destructor completed." <<endl;
}

//height
template<typename T>
T square<T>::getSide(){
    double highx=0, lowx=0; 

    //high
    if(quadrilateral<T>::getNumX()>=quadrilateral<T>::getNumX2()&&
    quadrilateral<T>::getNumX()>=quadrilateral<T>::getNumX3()&&
    quadrilateral<T>::getNumX()>=quadrilateral<T>::getNumX4()){
        highx=quadrilateral<T>::getNumX();//point 1
    }
    else if(quadrilateral<T>::getNumX2()>=quadrilateral<T>::getNumX()&&
    quadrilateral<T>::getNumX2()>=quadrilateral<T>::getNumX3()&&
    quadrilateral<T>::getNumX2()>=quadrilateral<T>::getNumX4()){
        highx=quadrilateral<T>::getNumX2();//point 2
    }
    else if(quadrilateral<T>::getNumX3()>=quadrilateral<T>::getNumX()&&
    quadrilateral<T>::getNumX3()>=quadrilateral<T>::getNumX2()&&
    quadrilateral<T>::getNumX3()>=quadrilateral<T>::getNumX4()){
        highx=quadrilateral<T>::getNumX3();//point 3
    }
    else if(quadrilateral<T>::getNumX4()>=quadrilateral<T>::getNumX()&&
    quadrilateral<T>::getNumX4()>=quadrilateral<T>::getNumX2()&&
    quadrilateral<T>::getNumX4()>=quadrilateral<T>::getNumX3()){
        highx=quadrilateral<T>::getNumX4();//point 4
    }
    //low
    if(quadrilateral<T>::getNumX()<=quadrilateral<T>::getNumX2()&&
    quadrilateral<T>::getNumX()<=quadrilateral<T>::getNumX3()&&
    quadrilateral<T>::getNumX()<=quadrilateral<T>::getNumX4()){
        lowx=quadrilateral<T>::getNumX();//point 1
    }
    else if(quadrilateral<T>::getNumX2()<=quadrilateral<T>::getNumX()&&
    quadrilateral<T>::getNumX2()<=quadrilateral<T>::getNumX3()&&
    quadrilateral<T>::getNumX2()<=quadrilateral<T>::getNumX4()){
        lowx=quadrilateral<T>::getNumX2();//point 2
    }
    else if(quadrilateral<T>::getNumX3()<=quadrilateral<T>::getNumX()&&
    quadrilateral<T>::getNumX3()<=quadrilateral<T>::getNumX2()&&
    quadrilateral<T>::getNumX3()<=quadrilateral<T>::getNumX4()){
        lowx=quadrilateral<T>::getNumX3();//point 3
    }
    else if(quadrilateral<T>::getNumX4()<=quadrilateral<T>::getNumX()&&
    quadrilateral<T>::getNumX4()<=quadrilateral<T>::getNumX2()&&
    quadrilateral<T>::getNumX4()<=quadrilateral<T>::getNumX3()){
        lowx=quadrilateral<T>::getNumX4();//point 4
    }
    
    return highx - lowx;
}

//area
template<typename T>
T square<T>::areaS(){
    return getSide()*4;
}

template<typename U>
istream &operator>>(istream &input, square<U> &a){
    input >> a.numY >> a.numX >> a.numY2 >> a.numX2 >> a.numY3 >>
    a.numX3 >> a.numY4 >> a.numX4;
    return input;
}

template<typename U>
ostream &operator<<(ostream &output, const square<U> &a){
    output << "side one: " << a.getNumX() << ' ' << a.getNumY() <<endl 
    << "side two: " << a.getNumX2() << ' ' << a.getNumY2() <<endl
    << "side three: " << a.getNumX3() << ' ' << a.getNumY3() <<endl
    << "side four: " << a.getNumX4() << ' ' << a.getNumY4() <<endl;
    return output;
}