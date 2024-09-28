#include <bits/stdc++.h>
using namespace std;

int fib(int size){
    
    if(size<=1){
        return size;
    }   

    return fib(size-1)+fib(size-2);
}

int main(){
    int size;
    cout << "Enter a number: " <<endl; 
    cin>> size;

    cout << "Your fibonacci number is: "<< fib(size) <<endl;
}