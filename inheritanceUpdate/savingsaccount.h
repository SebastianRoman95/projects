#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include<string>
using std::string;
#include<iostream>
#include"account.h"

template<typename T=double, typename S=string>
class savingsAccount: public account<T, S>{
    template<typename U, typename V>
    friend ostream &operator<<(ostream&, const savingsAccount<U, V>&);
    template<typename U, typename V>
    friend istream &operator>>(istream&, savingsAccount<U, V>&);

    public:
    savingsAccount(const S &fname="James", const S &lname="Berry", const T &balance=20, const T &rate=1.5);
    savingsAccount(const savingsAccount&);
    ~savingsAccount();

    T getRate()const;//double
    void setRate(const T&);//double
    T calculateInterest();//double

    private:
    T rate;//double
    
};
#endif