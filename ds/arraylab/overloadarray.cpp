#include <iostream>
using std::cerr;
using std::cout;
using std::cin;
using std::endl;
#include <iomanip>
using std::setw;
#include<cstdlib>
using std::exit;
#include "overloadarray.h"

//constructor
overloadArray::overloadArray(int arraySize){
    size = (arraySize > 0? arraySize :10);
    ptr = new int[size];

    for(int i=0; i < size; ++i){
        ptr[i]=0;
    }
}

//copy constructor
overloadArray::overloadArray(const overloadArray &arrayToCopy):size(arrayToCopy.size){
    ptr=new int[size];

    for(int i=0; i< size; ++i){
        ptr[i]=arrayToCopy.ptr[i];
    }
}

//destructor
overloadArray::~overloadArray(){
    delete[]ptr;
}

//return elements size
int overloadArray::getSize() const{
    return size;
}

//overload assignment operator
const overloadArray &overloadArray::operator=(const overloadArray &right){
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
bool overloadArray::operator==(const overloadArray &right) const{
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
int &overloadArray::operator[](int subscript){
    if(subscript < 0 || subscript >= size){
        cerr << "\nError: Subsicript " << subscript << " out of range"<< endl;
        exit(1);
    }
    return ptr[subscript];
}

//overload subscript const
int overloadArray::operator[](int subscript) const{
    if(subscript < 0 || subscript >= size){
        cerr << "\nError: Subsicript " << subscript << " out of range"<< endl;
        exit(1);
    }
    return ptr[subscript];
}

//input values
istream &operator>>(istream &input, overloadArray &a){
    for(int i=0;i<a.size;++i){
        input >> a.ptr[i];
    }

    return input;
}

//input values
ostream &operator<<(ostream &output, const overloadArray &a){
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