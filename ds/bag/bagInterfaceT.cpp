#include"bagInterface.cpp"

int main(){
    string clubs[]={"Joker", "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    bagInterface<string>grabBag;

    grabBag.add(clubs[1]);
    grabBag.add(clubs[2]);
    grabBag.add(clubs[4]);
    grabBag.add(clubs[8]);
    grabBag.add(clubs[10]);
    grabBag.add(clubs[12]);

    int guess =0;
    while (!grabBag.isEmpty()){
        cout << "What is your guess?" << "(1 for Ace to 13 for King):";
        cin >> guess;
        
        if(grabBag.contains(clubs[guess])){
            grabBag.remove(clubs[guess]);
        }
        else{
            cout << "Sorry, card was not in the bag.\n";
        }
    }
    cout << "No more cards in the bag. Game over!\n";
    
    return 0;
}