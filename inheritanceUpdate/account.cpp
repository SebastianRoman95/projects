#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#include "account.h"

template<typename T, typename S>
account<T, S>::account(const S &fname, const S &lname, const T &balance):
fname(fname),lname(lname),balance(balance){
    setFirstName(fname);
    setLastName(lname);
    setBalance(balance);
}

//copy constructor
template<typename T, typename S>
account<T, S>::account(const account<T, S> &accountToCopy){
    setFirstName(accountToCopy.fname);
    setLastName(accountToCopy.fname);
    setBalance(accountToCopy.fname);
}

template<typename T, typename S>
account<T, S>::~account(){
    cout << "account destructor completed." <<endl;
}

//name
template<typename T, typename S>
S account<T, S>::getFirstName()const{
    return fname;
}

template<typename T, typename S>
void account<T, S>::setFirstName(const S &fname){
    this->fname=(fname.length()>20)?fname.substr(0,20):fname;
}

//last name
template<typename T, typename S>
S account<T, S>::getLastName()const{
    return lname;
}

template<typename T, typename S>
void account<T, S>::setLastName(const S &lname){
    this->lname=(lname.length()>30?lname.substr(0,30):lname);
}

//starting amount
template<typename T, typename S>
T account<T, S>::getBalance()const{
    return balance;
}

template<typename T, typename S>
void account<T, S>::setBalance(const T &balance){
    this->balance = (balance < 0 ? 0 : balance);
}

template<typename T, typename S>
void account<T, S>::credit(const T &depositMoney){
   /* if(depositMoney < 0){
        depositMoney = (depositMoney < 0 ? 0 : depositMoney);
        cout << "Invalid number" <<endl;
    }
    else if(depositMoney > 1000){
        depositMoney = (depositMoney > 1000 ? 1000 : depositMoney);
        cout << "Exceeded deposit amount" <<endl;
    }*/
    double deposit =depositMoney;
    deposit = (deposit < 0 ? 0 : deposit);
    deposit = (deposit > 1000 ? 1000 : deposit);
    balance+=deposit; 
}

template<typename T, typename S>
bool account<T, S>::debit(const  T &withdrawMoney){ 
        if(withdrawMoney>balance){
            cout << "Invalid exceeded balance amount" <<endl;
            return false;
        }
        else{
            double withdraw=withdrawMoney;
            withdraw = (withdraw > 1000 ? 1000 : withdraw);
            balance-=withdraw;
            return true;
        }
        return true;     
}

template<typename U, typename V>
istream &operator>>(istream &input, account<U, V> &a){
    input >> a.fname >> a.lname >> a.balance;
    return input;
}

template<typename U, typename V>
ostream &operator<<(ostream &output, const account<U, V> &a){
    output << a.getFirstName() << ' ' << a.getLastName() << " balance is " << fixed  << setprecision(2) <<a.getBalance() <<endl;
    return output;
}

