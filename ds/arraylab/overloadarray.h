#ifndef OVERLOADARRAY_H
#define OVERLOADARRAY_H
#include <iostream>
using std::ostream;
using std::istream;

class overloadArray{
    friend ostream &operator<<(ostream &, const overloadArray &);
    friend istream &operator>>(istream &, overloadArray &);

    public: 
    overloadArray(int =10); //explicit need?
    overloadArray(const overloadArray &);
    ~overloadArray();
    int getSize()const;

    const overloadArray &operator=(const overloadArray&);
    bool operator==(const overloadArray &) const;

    bool operator!=(const overloadArray &right) const{
        return !(*this == right);
    }//missing?

    int &operator[](int);
    int operator[](int)const;

    private:
    int size;
    int *ptr;
};

#endif