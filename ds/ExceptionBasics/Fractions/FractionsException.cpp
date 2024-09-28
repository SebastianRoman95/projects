#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#include "FractionsException.h"

double quotient(int numerator, int denominator){
    if(denominator==0){
        throw FractionsException();
        return static_cast<double>(numerator)/denominator;
    }
}

