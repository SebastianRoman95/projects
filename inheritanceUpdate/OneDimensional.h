#ifndef ONEDIMENSIONAL_H
#define ONEDIMENSIONAL_H
#include <iostream>
using std::ostream;
using std::istream;

class OneDimensional{
    friend ostream &operator<<(ostream &, const OneDimensional &);
    friend istream &operator>>(istream &, OneDimensional &);

    public: 
    OneDimensional(int =10); 
    OneDimensional(const OneDimensional &);
    ~OneDimensional();
    int getSize()const;

    const OneDimensional &operator=(const OneDimensional&);
    bool operator==(const OneDimensional &) const;

    bool operator!=(const OneDimensional &right) const{
        return !(*this == right);
    }

    int &operator[](int);
    int operator[](int)const;

    private:
    int size;
    int *ptr;
};

#endif