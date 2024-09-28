#ifndef SRANDNUM_H
#define SRANDNUM_H
#include<iostream>
#include<vector>

using  namespace std;

template <typename T>

class srandNum{  
    public:   
void num(vector<T>& vec, int limit);
void print(vector<T>& vec, int limit);
int aver(vector<T>& vec, int limit, int & avg);
int compare (vector<T>& vec, int limit, int & comp, int & numb1, int & numb2);

private:
vector<T> vec;
int limit, avg, comp, numb1, numb2; 

};
#endif