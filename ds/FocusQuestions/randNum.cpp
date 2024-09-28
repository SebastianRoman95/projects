#include <bits/stdc++.h>
using namespace std;

//input random numbers in vec
void num (vector<int>& vec, int limit){
    int nums;

    for(int i=0;i<limit;++i){
    nums = rand();
    vec.push_back(nums);
    }
    
}

//print vec
void print(vector<int>& vec, int limit){
    for(int i=0;i<limit;++i){
    cout << vec[i] << ' ';
    }
}

//averaging
int aver(vector<int>& vec, int limit, int & avg){
    for(int i=0;i<limit;++i){
    avg+=vec[i];
    }

    avg=avg/limit;
}
//comparing 
int compare (vector<int>& vec, int limit, int & comp, int & numb1, int & numb2){

    numb1 = rand() % 10 -1;
    numb2 = rand() % 10 -1;
    comp = vec[numb1]-vec[numb2];
}


//main
int main(){
    vector<int>vec;
    int limit=10, comp, numb1, numb2, avg=0;
    srand(time(NULL));

    num(vec, limit);
    cout << "The numbers are " << endl;
    print(vec, limit);
    aver(vec, limit, avg);
    cout << endl <<"average: "<< avg << endl;
    compare(vec, limit, comp, numb1, numb2);
    cout << vec[numb1] << '-' << vec[numb2] << '=' << comp <<endl;
}