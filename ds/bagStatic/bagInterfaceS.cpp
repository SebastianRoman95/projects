#include"bagInterfaceS.h"

//make constructor
template<class ItemType>
bagInterfaceS<ItemType>::bagInterfaceS(){
    itemCount =0;
    maxItems = DEFAULT_Capacity;
}
//size of vector
template<class ItemType>
int bagInterfaceS<ItemType>::getCurrentSize(){
    return itemCount;
}

//occurences
template<class ItemType>
int bagInterfaceS<ItemType>::getFrequency( ItemType &item){
    int frequency=0, current=0;
    while(current<itemCount){
        try{
            cout << "old " <<frequency << endl;
            if(item[current]==item){
            ++frequency;
            throw frequency;
        }
        }
        catch{
            cout << "current" <<frequency << endl;
        }
        ++current;
    }
    return frequency;
}

//check if empty
template<class ItemType>
bool bagInterfaceS<ItemType>::isEmpty(){
    return itemCount=0;
}

//add error
template<class ItemType>
bool bagInterfaceS<ItemType>::add( ItemType & item){
    bool space = (itemCount<maxItems);
    if(space){
        items[itemCount]=item;
        ++item;
    }
    return space;
}

//remove
template<class ItemType>
bool bagInterfaceS<ItemType>::remove( ItemType & item){
    return false;
}

//container
template<class ItemType>
bool bagInterfaceS<ItemType>::contains(ItemType & item) {
    if(getFrequency()>0){
        return true;
    }
    return false;
    
}
//clear
template<class ItemType>
void bagInterfaceS<ItemType>::clear(){
    return itemCount=0;
}

//tovector
template<class ItemType>
vector<ItemType> bagInterfaceS<ItemType>::toVector(){
    vector<ItemType> bagContents;
    for(int i=0;i<itemCount;++i){
        bagContents.push_back(items[i]);
    }
    return bagContents;
}