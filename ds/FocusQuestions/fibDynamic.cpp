#include <bits/stdc++.h>
using namespace std;

int fib(int size){
int gr1=0,gr2=1, gr3;

if(size==0){
    return gr1;
}
for(int i=2;i<=size;++i){
    gr3=gr1+gr2;
    gr1=gr2;
    gr2=gr3;
}
return gr2;
}

int main(){
int size;
cout << "Enter a number: " <<endl; 
cin>> size;

cout << "Your fibonacci number is: "<< fib(size) <<endl;
}