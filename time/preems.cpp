#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
// Create a text string, which is used to output the text file
int myText, text2, text3;
int l=0, i=0;
vector<int>p;
vector<int>at;
vector<int>bt;

// Read from the text file
ifstream MyReadFile("preeminput.txt");

while (MyReadFile >> myText >> text2 >> text3) {
  p.push_back(myText);
  at.push_back(text2);
  bt.push_back(text3);
  l++;
}

for(int i=0;i<l;++i){
  cout << p[i] << at[i] << bt[i];
}


// Close the file
MyReadFile.close();
}
