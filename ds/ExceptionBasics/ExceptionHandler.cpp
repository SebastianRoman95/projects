#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;

#include<new>
using std::set_new_handler;

#include<cstdlib>
using std::abort;

void customNewHandler(){
    cerr << "customNewHandler was called";
    abort();
}

int main(){
    double *ptr[50];
    set_new_handler(customNewHandler);
    for(int i=0; i<50; ++i){
            ptr[i]= new double[50000000];
            cout << "Allocated 50000000 doubles in ptr [" << i << "]\n"; 
    }

    /*
    try{
        for(int i=0; i<50; ++i){
            ptr[i]= new double[50000000];
            cout << "Allocated 50000000 doubles in ptr [" << i << "]\n"; 
        }
    }
    
    catch(bad_alloc &memoryAllocationException){
        cerr << "Exception occurred: " << memoryAllocationException.what() << endl;
    }
    */

    /*
    for(int i=0; i<50; ++i){
        ptr[i]= new double[50000000];

        if(ptr[i]==0){
            cerr << "Memory allocation failed for ptr[" << i << "}\n";
            break;
        }
        else{
            cout << "Allocated 50000000 doubles in ptr [" << i << "]\n"; 
        }
    }
*/
        return 0;   
}