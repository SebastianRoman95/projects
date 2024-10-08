#include <iostream>
using std::cerr;
using std::cout;
using std::cin;
using std::endl;
#include <iomanip>
using std::setw;
#include<cstdlib>
using std::exit;
#include "OneDimensional.h"

//constructor
OneDimensional::OneDimensional(int arraySize){
    size = (arraySize > 0? arraySize :10);
    ptr = new int[size];

    for(int i=0; i < size; ++i){
        ptr[i]=0;
    }
}

//copy constructor
OneDimensional::OneDimensional(const OneDimensional &arrayToCopy):size(arrayToCopy.size){
    ptr=new int[size];

    for(int i=0; i< size; ++i){
        ptr[i]=arrayToCopy.ptr[i];
    }
}

//destructor
OneDimensional::~OneDimensional(){
    delete[]ptr;
}

//return elements size
int OneDimensional::getSize() const{
    return size;
}

//overload assignment operator
const OneDimensional &OneDimensional::operator=(const OneDimensional &right){
    if (&right != this){
        if(size != right.size){
            delete[]ptr;
            size = right.size;
            ptr= new int[size];
        }

        for(int i=0;i<size;++i){
            ptr[i]=right.ptr[i];
        }
    }
    return *this;
}

//two arrays equality
bool OneDimensional::operator==(const OneDimensional &right) const{
    if(size!= right.size){
        return false;
    }

    for(int i=0;i<size;++i){
        if(ptr[i]!=right.ptr[i]){
            return false;
        }
    }

    return true;
}

//overload subscript
int &OneDimensional::operator[](int subscript){
    if(subscript < 0 || subscript >= size){
        cerr << "\nError: Subscript " << subscript << " out of range"<< endl;
        exit(1);
    }
    return ptr[subscript];
}

//overload subscript const
int OneDimensional::operator[](int subscript) const{
    if(subscript < 0 || subscript >= size){
        cerr << "\nError: Subscript " << subscript << " out of range"<< endl;
        exit(1);
    }
    return ptr[subscript];
}

//input values
istream &operator>>(istream &input, OneDimensional &a){
    for(int i=0;i<a.size;++i){
        input >> a.ptr[i];
    }

    return input;
}

//input values
ostream &operator<<(ostream &output, const OneDimensional &a){
    int i;
    for(i=0;i<a.size;++i){
        output << setw(12) << a.ptr[i];

        if((i+1)%4==0){
            output<<endl;
        }
    }

    if(i%4!=0){
        output<<endl;
    }
    return output;
}