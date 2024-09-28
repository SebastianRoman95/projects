#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#include "Integer.h"

template<typename t, typename U>
double Integer<t,U>::function1(const t a, const t b) throw(runtime_error){
    string error = {"No good"};

    if(b==0){
        throw runtime_error("Division by zero!\n");
        cout << "unanle to solve problem.\n";
    }
    return static_cast<U>(a)/b;
}

template<typename t, typename U>
void Integer<t,U>::function2(const t a, const t b) throw(runtime_error){
    cout << "function 3 is called inside function 2" << endl;
    return function1<t, U>(a,b);
}

template<typename t, typename U>
void Integer<t,U>::function3(const t a, const t b) throw(runtime_error){
    cout << "function 2 is called inside function 1" << endl;
    return function2<t, U>(a,b);
}