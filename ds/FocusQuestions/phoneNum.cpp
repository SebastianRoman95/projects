#include<iostream>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::ios;

#include<fstream>
using std::ofstream;

#include<cstdlib>
using std::exit;

void wordGenerator(const int *const);

int main(){
    int phoneNumber[7] = {0};

    cout << "Enter a phone number (digits 2-9) " << "in the form: xxx-xxxx\n";

    //phone number
    for(int u=0, v=0; u<8;++u){
        int i=cin.get();
        if (i>= '0' && i <= '9')
            phoneNumber[v++]=i-'0';
    }
}

void wordGenerator(const int * const n){

    //ofstream
    ofstream outFile("phone.dat", ios::out);

    //letter corresponding 
    const char phoneletters[10] = {0,0,0,0,0,0,0,0,0,0};
    //could not open file
    if(!outFile){
        cerr << "File could not be opened" << endl;
        exit(1);
    }

    int count =0;

    for(int *i1=0;*i1<=2;++i1){
        for(int *i2=0;*i2<=2;++i2){
            for(int *i3=0;*i3<=2;++i3){
                for(int *i4=0;*i4<=2;++i4){
                    for(int *i5=0;*i5<=2;++i5){
                        for(int *i6=0;*i6<=2;++i6){
                            for(int *i7=0;*i7<=2;++i7){
                                
                                outFile << phoneletters[n[0]][i1] << phoneletters[n[1]][i2] << phoneletters[n[2]][i3] << phoneletters[n[3]][i4] << phoneletters[n[4]][i5]
                                << phoneletters[n[5]][i6] << phoneletters[n[6]][i7] << ' ';
                                if(++count % 9 == 0)
                                    outFile << '\n';
                            }
                        }   
                    }
                }
            }
        }
    }

    outFile << "\nPhone number is ";

    for(int i =0;i<7; ++i){
        if(i==3)
            outFile << '-';

            outFile << n[i];
    }

    outFile.close();
}