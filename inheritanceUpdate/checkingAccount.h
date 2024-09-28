#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H
#include<string>
using std::string;
#include<iostream>
#include"account.h"

template<typename T=double, typename S=string>
class checkingAccount: public account<T, S>{
    template<typename U, typename V>
    friend ostream &operator<<(ostream&, const checkingAccount<U, V>&);
    template<typename U, typename V>
    friend istream &operator>>(istream&, checkingAccount<U, V>&);

    public:
    checkingAccount(const S &fname="James", const S &lname="Berry", const T &balance=20, const T &fee=2);
    checkingAccount(const checkingAccount&);
    ~checkingAccount();

    void credit(const T&);//double
    bool debit(const T&);
    T getFee()const;//double
    void setFee(const T&);//double

    private:
    T fee;//double
    
};
#endif