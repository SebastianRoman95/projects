#include <iostream>
using std::cerr;
using std::cout;
using std::cin;
using std::endl;
#include <iomanip>
using std::setw;
#include<cstdlib>
using std::exit;
#include <cmath>
using std::floor;
#include "TwoDimensional.h"

//constructor
TwoDimensional::TwoDimensional(int arrayRowSize, int arrayColSize){
    rowSize = (arrayRowSize > 0? arrayRowSize :10);
    colSize = (arrayColSize > 0? arrayColSize :10);
    ptr = new int*[rowSize];

    for(int i=0; i < rowSize; ++i){
        ptr[i]= new int[colSize];
    }

    for(int i = 0; i < rowSize; ++i) {
        for(int j = 0; j < colSize; ++j) {
            ptr[i][j]=0;
        }
    }
}

//copy constructor
TwoDimensional::TwoDimensional(const TwoDimensional &arrayToCopy):rowSize(arrayToCopy.rowSize){
    ptr=new int *[rowSize];
    for(int i=0; i< rowSize; ++i){
            ptr[i]=arrayToCopy.ptr[i]; 
            this->ptr[i]=new int[this->colSize];     
    }
    //does this need col?
}

//destructor
TwoDimensional::~TwoDimensional(){
    for(int i=0;i<rowSize;++i){
        delete[]ptr[i];
    }
    delete[]ptr;
}

//return elements row size
int TwoDimensional::getRowSize() const{
    return rowSize;
}

//return elements row size
int TwoDimensional::getColSize() const{
    return colSize;
}

//overload assignment operator 
const TwoDimensional &TwoDimensional::operator=(const TwoDimensional &right){
    if (&right != this){
        if(rowSize != right.rowSize){
            delete[]ptr;
            rowSize = right.rowSize;
            int **ptr= new int*[rowSize];
        }

        for(int i=0;i<rowSize;++i){
            ptr[i]=right.ptr[i];
            this->ptr[i]=new int[this->colSize]; //this here or its own statement?
        }
    }
    return *this;
}

//two arrays equality
bool TwoDimensional::operator==(const TwoDimensional &right) const{
    if(rowSize!= right.rowSize){
        return false;
    }

    for(int i=0;i<rowSize;++i){
        if(ptr[i]!=right.ptr[i]){
            return false;
        }
    }
    //do i need a statement for col?
    return true;
}

bool TwoDimensional::operator!=(const TwoDimensional &right) const{
    return !(*this == right);
}

//overload subscript lvalue
int &TwoDimensional::operator[](int subscript){

    if(rowSize*colSize<subscript||subscript<0){
        cerr << "\nError: Subscript " << subscript << " out of range"<< endl;
        exit(1);
    }
    
    int rowS=floor(subscript/colSize);
    int colS=subscript%rowSize;
    return this->ptr[rowS][colS];
}

//overload subscript const rvalue
int TwoDimensional::operator[](int subscript) const{
    if(rowSize*colSize<subscript||subscript<0){
        cerr << "\nError: Subscript " << subscript << " out of range"<< endl;
        exit(1);
    }
    
    int rowS=floor(subscript/colSize);
    int colS=subscript%rowSize;
    return this->ptr[rowS][colS];
}

//input values
istream &operator>>(istream &input, TwoDimensional &a){
    cout << "input "<<a.rowSize*a.colSize << " elements ";
    for(int i=0;i<a.rowSize;++i){
        for(int j=0;j<a.colSize;++j){
            input >> a.ptr[i][j];
        }
    }

    return input;
}

//input values
ostream &operator<<(ostream &output, const TwoDimensional &a){
    int i = 0, j = 0;
    //cout << "log\n";
    for(i=0;i<a.rowSize;++i){
        //cout << "Row " << i << '\n';
        //cout << a.colSize << '\n';
        for(j=0;j<a.colSize;++j){
            //cout << "Col " << j << " ";
            output << setw(12) << a.ptr[i][j];
            /*if((i+1)%4==0){
                output<<endl;
            }*/
        }
        cout << endl;
    }

    if(i%4!=0){
        output<<endl;
    }
    cout << "end\n";
    return output;
}