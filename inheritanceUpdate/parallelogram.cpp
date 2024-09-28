#include "parallelogram.h"
#include <iostream>

template<typename T>
parallelogram<T>::parallelogram(const T& numX, const T& numY, const T& numX2, const T& numY2,
const T& numX3, const T& numY3, const T& numX4, const T& numY4):quadrilateral<T>(numX, numY, numX2, numY2,
numX3, numY3, numX4, numY4){
}

//copy
template<typename T>
parallelogram<T>::parallelogram(const parallelogram<T> &parallelogramToCopy){
}

//destructor
template<typename T>
parallelogram<T>::~parallelogram(){
    cout << "parallelogram destructor completed." <<endl;
}

template<typename T>
T parallelogram<T>::getWidthP(){
    double left=0;
    left = abs(quadrilateral<T>::getNumX()-quadrilateral<T>::getNumX2());
    return left;
}

//height
template<typename T>
T parallelogram<T>::getHeightP(){
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
T parallelogram<T>::areaP(){
    return getHeightP()*getWidthP();
}

template<typename U>
istream &operator>>(istream &input, parallelogram<U> &a){
    input >> a.numY >> a.numX >> a.numY2 >> a.numX2 >> a.numY3 >>
    a.numX3 >> a.numY4 >> a.numX4;
    return input;
}

template<typename U>
ostream &operator<<(ostream &output, const parallelogram<U> &a){
    output << "side one: " << a.getNumX() << ' ' << a.getNumY() <<endl 
    << "side two: " << a.getNumX2() << ' ' << a.getNumY2() <<endl
    << "side three: " << a.getNumX3() << ' ' << a.getNumY3() <<endl
    << "side four: " << a.getNumX4() << ' ' << a.getNumY4() <<endl;
    return output;
}