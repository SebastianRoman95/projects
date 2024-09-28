#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

#include<stdexcept>
using std::runtime_error;

template<typename t, typename U>
U function1(const t a, const t b) throw(runtime_error){
    string error = {"No good"};

    if(b==0){
        throw runtime_error("Division by zero!\n");
        cout << "unanle to solve problem.\n";
    }
    return static_cast<U>(a)/b;
}

template<typename t, typename U>
void function2(const t a, const t b) throw(runtime_error){
    cout << "function 3 is called inside function 2" << endl;
    return function1<t, U>(a,b);
}

template<typename t, typename U>
void function3(const t a, const t b) throw(runtime_error){
    cout << "function 2 is called inside function 1" << endl;
    return function2<t, U>(a,b);
}

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

//in the main throw string, expetion 2
