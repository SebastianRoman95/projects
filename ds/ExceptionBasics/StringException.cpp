#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#include<exception>
using std::exception;

void throwException(){
    try{
        cout << "Function throwException throws an exception\n";
        throw exception();
    }
    catch(exception&){
        cout << "Exception handled in function throwException" << "\n Function throwException rethrow exception";
        throw;
    }

    cout << "This is also should not print\n";
}

int main (){
    try{
        cout << "\nmain invokes function throwException\n";
        throwException();
        cout << "This should not print\n";
    }
    catch(exception&){
        cout << "\n\nException handled in main\n";
    }

    cout << "program control continues after catch in main\n";
    return 0;
}



