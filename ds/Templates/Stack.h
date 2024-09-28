#ifndef STACK_H
#define STACK_H
using  namespace std;

template<typename T>
class Stack{
    Public:
    Stack(int =10);
    
    //destructor 
    ~Stack(){
        delete[]stackPtr;
    } 

    bool push(const T &);
    bool pop(T&);

    bool isEmpty() const{
        return top ==-1;
    }

    bool isFull()const{
        return top ==size-1;
    }

    Private:
    int size;
    int top;
    T *stackPtr;
};
#endif