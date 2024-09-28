#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#include"savingsaccount.h"

template<typename T, typename S>
savingsAccount<T, S>::savingsAccount(const S &fname, const S &lname, const T &balance,const T &rate):
account<T, S>(fname, lname, balance){
    setRate(rate);
}

//copy constructor
template<typename T, typename S>
savingsAccount<T, S>::savingsAccount(const savingsAccount<T, S> &SaccountToCopy){
    setRate(SaccountToCopy.rate);
}

template<typename T, typename S>
savingsAccount<T, S>::~savingsAccount(){
    cout << "savings account destructor completed." <<endl;
}

template<typename T, typename S>
void savingsAccount<T, S>::setRate(const T &rate){
  this->rate = (rate < 0 ? 0 : rate);
  this->rate = (rate > 4 ? 4 : rate);
}

template<typename T, typename S>
T savingsAccount<T, S>::getRate()const{
    return rate;
}

template<typename T, typename S>
T savingsAccount<T, S>::calculateInterest(){
    account<T, S>::setBalance(account<T, S>::getBalance()+((getRate()/100)*account<T, S>::getBalance()));
    return account<T, S>::getBalance()+((getRate()/100)*account<T, S>::getBalance());
    
}

template<typename U, typename V>
istream &operator>>(istream &input, savingsAccount<U, V> &a){
    input >> a.fname >> a.lname >> a.balance;
    return input;
}

template<typename U, typename V>
ostream &operator<<(ostream &output, const savingsAccount<U, V> &a){
    output << a.getFirstName() << ' ' << a.getLastName() << " balance is " << fixed << setprecision(2) << a.getBalance()  << endl;
    return output;
}
