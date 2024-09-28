#ifndef ACCOUNT_H
#define ACCOUNT_H
#include<iostream>
#include<string>
using std::string;
using std::ostream;
using std::istream;

template<typename T=double, typename S=string>
class account{
    template<typename U, typename V>
    friend ostream &operator<<(ostream&, const account<U, V>&);
    template<typename U, typename V>
    friend istream &operator>>(istream&, account<U, V>&);

    public:
    account(const S &fname="Jame", const S &lname="Berry", const T &balance=20);
    account(const account&);
    ~account();
    //names
    S getFirstName()const;
    void setFirstName(const S&);
    S getLastName()const;
    void setLastName(const S&);

    //balance,credit,debit
    T getBalance()const;//double
    void setBalance(const T&);//S
    bool debit(const T&);//double
    void credit(const T&);//double

    private:
    T balance;//double
    S fname;
    S lname;

};
#endif