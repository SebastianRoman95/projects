#ifndef TWODIMENSIONAL_H
#define TWODIMENSIONAL_H
#include <iostream>
using std::ostream;
using std::istream;

class TwoDimensional{
    //cout and cin
    friend ostream &operator<<(ostream &, const TwoDimensional &);
    friend istream &operator>>(istream &, TwoDimensional &);

    public: 
    //constructor, copy, deconstructor
    TwoDimensional(int =10, int=10); 
    TwoDimensional(const TwoDimensional &);
    ~TwoDimensional();
    //sizes
    int getRowSize()const;
    int getColSize()const;

    //assignment operator
    const TwoDimensional &operator=(const TwoDimensional&);
    //equality operator
    bool operator==(const TwoDimensional &) const;
    //inequality operator
    bool operator!=(const TwoDimensional &right) const;

    //lvalue
    int &operator[](int);
    //rvalue
    int operator[](int)const;

    private:
    
    int **ptr;
    int rowSize;
    int colSize;
    
};

#endif