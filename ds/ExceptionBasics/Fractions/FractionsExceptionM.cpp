#include<iostream>
using namespace std;
#include "FractionsException.cpp"

int main(){
    int number1, number2;
    double result;
    cout << "enter two integers (end-of-file to end): ";

    while (cin >> number1 >> number2){
        try{
            result = quotient(number1, number2);
            cout << "The quotient is: " << result  << endl;
        }

        catch (FractionsException &FractionsException){
            cout << "Exception occurred: " << FractionsException.what() << endl;
        }

        cout << "\nenter two integers (end-of-file to end): ";
    }

    cout << endl;
    return 0;
}