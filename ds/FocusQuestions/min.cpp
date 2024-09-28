#include <iostream>
#include <vector>
using namespace std;

int main(){

    //var
    int num, size, min, min2, count=0;
    vector<int>vec;

    //limit
    cout << "Enter how many numbers you will have. " <<endl;
    cin >> size;

    //get first number to find min val
    cout << "Enter number: " << endl;
    cin >> min;
    vec.push_back(min);

    //check if empty
    if(vec[0]==vec.empty()){
        cout << "No numbers inputted" <<endl;
    }//if the vec isn't empty
    else if(size==1){
        cout << "Only one number" <<endl;
    }
    else{
        //2nd value
        cout << "Enter number: " << endl;
        cin >> min2;

        //swap for min and min2 values
        if(min2<min){
            num=min;
            min=min2;
            min2=num;
        }

        vec.push_back(min2);

        //if the size is greater than 3
        for(int i=2;i<size;++i){
            //inputting numbers into vec
            cout << "Enter number: " << endl;
            cin >> num;
            vec.push_back(num);

            //see if they are all the same number
            if(min==num){
                ++count;
            }
            //see if the new value is 
            if(min2>num){
                min2=num;
                if(min>min2){
                    //swap
                    num=min;
                    min=min2;
                    min2=num;
                    count=0;
                }            
            }     
        }
    }  

    //output dupes or min
    if(count+1==size){
        cout << "They are all the same: " <<endl;
    }
    else{
        cout << "The second min is: " << min2 << endl;
    }   
}