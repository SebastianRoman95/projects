#include <iostream>
using namespace std;

int main (){

    int Pnumber[5]={1,3,2,4,5}, AT[5], BT[5], Prio[5]={2,1,1,3,4}, Psize, PrioSize=6; //change PrioSize to -1

    /*
    for(int i=0;i<5; ++i){
        cin >> Pnumber[i] >> AT[i] >> BT[i] >> Prio[i];
        if(Prio[i]>PrioSize){
            PrioSize=Prio[i];
        }
    }
    */

   int Pswap;
    for(int i=0;i<5; ++i){
        for(int j=i+1;j<5;j++){
            if(Prio[j]<Prio[i]){
                swap(Prio[i],Prio[j]);
                swap(Pnumber[i],Pnumber[j]);
            }
            else if(Prio[j]==Prio[i]&&Pnumber[j]<Pnumber[i]){
                swap(Prio[i],Prio[j]);
                swap(Pnumber[i],Pnumber[j]);
            }
        }
    }

    for(int i=0;i<5; ++i){
        cout << "Pnumber" << Pnumber[i] <<Prio[i];
    }
}

    

/*
p number so default order
AT:
BT: 
Priority:
CT: Which is the total for each priority (non preemptive or preemptive)
TAT: CT - AT
WT: TAT - BT
*/