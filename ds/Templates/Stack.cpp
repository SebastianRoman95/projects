#include"Stack.h"

template<typename T>
Stack<T>::Stack(int s)
    :size(s>0?s:10),top(-1),stackPtr(new T[size])
    {
    }

    template<typename T>
    bool Stack<T>::push(const T &pushValue){
        if(!isFull()){
            stackPtr[++top]=pushValue;
            return true;
        }

        return false;
    }

    template<typename T>
    bool Stack<T>::pop(T &popValue){
        if(!isEmpty()){
            popValue=stackPtr[top--];
            return true;
        }

        return false;
    }
