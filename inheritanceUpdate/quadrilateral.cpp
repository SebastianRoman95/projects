#include "quadrilateral.h"
#include <iostream>

//constructor
template<typename T>
quadrilateral<T>::quadrilateral(const T& numX, const T& numY, const T& numX2, const T& numY2,
const T& numX3, const T& numY3, const T& numX4, const T& numY4):
numX(numX), numY(numY), numX2(numX2), numY2(numY2), numX3(numX3), numY3(numY3), numX4(numX4), numY4(numY4){
    //pair 1
    setNumY(numY);
    setNumX(numX);
    //pair 2
    setNumY2(numY2);
    setNumX2(numX2);
    //pair 3
    setNumY3(numY3);
    setNumX3(numX3);
    //pair 4
    setNumY3(numY4);
    setNumX3(numX4);
}

//copy
template<typename T>
quadrilateral<T>::quadrilateral(const quadrilateral<T> &quadrilateralToCopy){
    //pair 1
    setNumY(quadrilateralToCopy.numY);
    setNumX(quadrilateralToCopy.numX);
    //pair 2
    setNumY2(quadrilateralToCopy.numY2);
    setNumX2(quadrilateralToCopy.numX2);
    //pair 3
    setNumY3(quadrilateralToCopy.numY3);
    setNumX3(quadrilateralToCopy.numX3);
    //pair 4
    setNumY3(quadrilateralToCopy.numY4);
    setNumX3(quadrilateralToCopy.numX4);
}

//destructor
template<typename T>
quadrilateral<T>::~quadrilateral(){
    cout << "quadrilateral destructor completed." <<endl;
}

//set functions pair 1
template<typename T>
void quadrilateral<T>::setNumY(const T& numY){
    this->numY=numY;
}   

template<typename T>
void quadrilateral<T>::setNumX(const T& numX){
    this->numX=numX;
}

//get function pair 1
template<typename T>
T quadrilateral<T>::getNumX()const{
    return numX;
}

template<typename T>
T quadrilateral<T>::getNumY()const{
    return numY;
}

//set functions pair 2
template<typename T>
void quadrilateral<T>::setNumY2(const T& numY2){
    this->numY2=numY2;
}   

template<typename T>
void quadrilateral<T>::setNumX2(const T& numX2){
    this->numX2=numX2;
}

//get functions pair 2
template<typename T>
T quadrilateral<T>::getNumX2()const{
    return numX2;
}

template<typename T>
T quadrilateral<T>::getNumY2()const{
    return numY2;
}

//set functions pair 3
template<typename T>
void quadrilateral<T>::setNumY3(const T& numY3){
    this->numY3=numY3;
}   

template<typename T>
void quadrilateral<T>::setNumX3(const T& numX3){
    this->numX3=numX3;
}

//get function pair 3
template<typename T>
T quadrilateral<T>::getNumX3()const{
    return numX3;
}

template<typename T>
T quadrilateral<T>::getNumY3()const{
    return numY3;
}

//set functions pair 4
template<typename T>
void quadrilateral<T>::setNumY4(const T& numY4){
    this->numY4=numY4;
}   

template<typename T>
void quadrilateral<T>::setNumX4(const T& numX4){
    this->numX4=numX4;
}

//get function pair 4
template<typename T>
T quadrilateral<T>::getNumX4()const{
    return numX4;
}
template<typename T>
T quadrilateral<T>::getNumY4()const{
    return numY4;
}

template<typename U>
istream &operator>>(istream &input, quadrilateral<U> &a){
    input >> a.numY >> a.numX >> a.numY2 >> a.numX2 >> a.numY3 >>
    a.numX3 >> a.numY4 >> a.numX4;
    return input;
}

template<typename U>
ostream &operator<<(ostream &output, const quadrilateral<U> &a){
    output << "side one: " << a.getNumX() << ' ' << a.getNumY() <<endl 
    << "side two: " << a.getNumX2() << ' ' << a.getNumY2() <<endl
    << "side three: " << a.getNumX3() << ' ' << a.getNumY3() <<endl
    << "side four: " << a.getNumX4() << ' ' << a.getNumY4() <<endl;
    return output;
}