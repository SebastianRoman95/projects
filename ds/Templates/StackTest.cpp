#include"Stack.cpp"
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    Stack<double>doubleStack(5);
    double doubleValue=1.1;
    cout << "Pushing elements onto doubleStack\n";

    while(doubleStack.push(doubleValue)){
        cout<<doubleValue<< ' ';
        doubleValue+=1.1;
    }

    cout<<"\nStack is full"<<doubleValue<<"\n\nPopping elements from doubleStack\n";

    while(doubleStack.pop(doubleValue))
        cout<<doubleValue<< ' ';
    
        

    cout<<"\nStack is empty. cannot pop\n";

    Stack<int>intStack;
    int intValue=1;
    cout<<"Pushing elements onto intValue\n";

    while(intStack.push(intValue)){
        cout<<intValue++<< ' ';
    }

    cout<<"\nStack is full. cannot push\n"<<intValue<<"\n\nPopping elements from intStack\n";

    while(intStack.pop(intValue))
        cout<<intValue<< ' ';

    cout<<"\nStack is empty. cannot pop\n"; 
}