#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#include "Integer.cpp"

int main(){
    try{
        cout << "function 1 is called inside  main" << endl;
        cout << function3<int, double>(10, 5) << endl;
    }
    catch (runtime_error &error){
        cout << "Exception occured: " << error.what() << endl;
        cout << "Exception handled in main" <<endl;
    }
    return 0;
}