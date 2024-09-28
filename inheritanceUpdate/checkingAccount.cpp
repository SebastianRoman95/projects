#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#include"checkingAccount.h"

template<typename T, typename S>
checkingAccount<T, S>::checkingAccount(const S &fname, const S &lname, const T &balance, const T &fee):
account<T, S>(fname, lname, balance){
    setFee(fee);
}

//copy constructor
template<typename T, typename S>
checkingAccount<T, S>::checkingAccount(const checkingAccount<T, S> &CaccountToCopy){
    setFee(CaccountToCopy.fee);
}

template<typename T, typename S>
checkingAccount<T, S>::~checkingAccount(){
    cout << "checking account destructor completed." <<endl;
}

template<typename T, typename S>
void checkingAccount<T, S>::credit(const T &deposit){
    account<T, S>::credit(deposit);
    account<T, S>::setBalance(account<T, S>::getBalance()-(deposit*(fee/100)));
}

template<typename T, typename S>
bool checkingAccount<T, S>::debit(const T &withdraw){
    if(account<T, S>::debit(withdraw)==true){
        cout << withdraw*(fee/100) <<endl;
        account<T, S>::setBalance(account<T, S>::getBalance()-(withdraw*(fee/100)));
        return true;
    }
    return false;
}

template<typename T, typename S>
T checkingAccount<T, S>::getFee()const{
    return fee;
}

template<typename T, typename S>
void checkingAccount<T, S>::setFee(const T &fee){
    this->fee = (fee < 0 ? 2 : fee);
    this->fee = (fee > 50 ? 50 : fee);
}

template<typename U, typename V>
istream &operator>>(istream &input, checkingAccount<U, V> &a){
    input >> a.lname >> a.fname >> a.balance;
    return input;
}

template<typename U, typename V>
ostream &operator<<(ostream &output, const checkingAccount<U, V> &a){
    output << a.getFirstName() << ' ' << a.getLastName() << " balance is " << fixed << setprecision(2) << a.getBalance() <<endl;
    return output;
}