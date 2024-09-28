#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H
#include <iostream>
using namespace std;

//parent quad
template<typename T=double>
class quadrilateral {
    template<typename U>
    friend ostream &operator<<(ostream&, const quadrilateral<U>&);
    template<typename U>
    friend istream &operator>>(istream&, quadrilateral<U>&);

    public:
    quadrilateral(const T& numX=1, const T& numY=1,const T& numX2=2, const T& numY2=2,
    const T& numX3=3, const T& numY3=3,const T& numX4=4, const T& numY4=4);
    quadrilateral(const quadrilateral&);
    ~quadrilateral();

    //pair 1
    T getNumX()const;
    T getNumY()const;
    void setNumY(const T&); 
    void setNumX(const T&);
    //pair 2
    T getNumX2()const;
    T getNumY2()const;
    void setNumY2(const T&); 
    void setNumX2(const T&);
    //pair 3
    T getNumX3()const;
    T getNumY3()const;
    void setNumY3(const T&); 
    void setNumX3(const T&);
    //pair 4
    T getNumX4()const;
    T getNumY4()const;
    void setNumY4(const T&); 
    void setNumX4(const T&);

    private:
    T numX;
    T numY;
    T numX2;
    T numY2;
    T numX3;
    T numY3;
    T numX4;
    T numY4;
};
#endif