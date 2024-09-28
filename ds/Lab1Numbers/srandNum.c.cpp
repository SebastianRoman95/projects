#include"srandNum.h"

//input random numbers in vec
template<typename T>
void srandNum<T>::num(vector<T>& vec, int limit){
    int nums;

    for(int i=0;i<limit;++i){
    nums = rand()%100;
    cout << nums << ' ';
    vec.push_back(nums);
    }
    
}

//print vec
template<typename T>
void srandNum<T>::print(vector<T>& vec, int limit){
    for(int i=0;i<limit;++i){
    cout << vec[i] << ' ';
    }
}

//averaging
template<typename T>
int srandNum<T>::aver(vector<T>& vec, int limit, int & avg){
    for(int i=0;i<limit;++i){
    avg+=vec[i];
    }
    avg=avg/limit;
    cout << avg;
}

//comparing 
template<typename T>
int srandNum<T>::compare (vector<T>& vec, int limit, int & comp, int & numb1, int & numb2){

    numb1 = rand() % 10 -1;
    numb2 = rand() % 10 -1;
    comp = vec[numb1]-vec[numb2];
    cout << vec[numb1] << '-' << vec[numb2] << '=' << comp <<endl;
}