#include"srandNum.c"
using namespace std;

int main() {
    srandNum<int> SRN; 
    vector<int>vec;
    int limit, avg, comp, numb1, numb2;
    srand(time(NULL));

    SRN.num(vec, limit);
    cout << "The numbers are " << endl;
    SRN.print(vec, limit);
    cout << endl <<"average: "<< ' ';
    SRN.aver(vec, limit, avg);
    SRN.compare(vec, limit, comp, numb1, numb2);
    cout <<endl << "Compare: " << ' ';
}