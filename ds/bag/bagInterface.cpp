#include"bagInterface.h"

//make constructor
template<class ItemType>
bagInterface<ItemType>::bagInterface(){
    itemCount =0;
    maxItems = DEFAULT_Capacity;
}
//size of vector
template<class ItemType>
int bagInterface<ItemType>::getCurrentSize() const{
    return itemCount;
}

//occurences
template<class ItemType>
int bagInterface<ItemType>::getFrequency(const ItemType &item) const{
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
bool bagInterface<ItemType>::isEmpty() const{
    return itemCount=0;
}

//add error
template<class ItemType>
bool bagInterface<ItemType>::add(const ItemType & item)const{
    bool space = (itemCount<maxItems);
    if(space){
        items[itemCount]=item;
        ++item;
    }
    return space;
}

//remove
template<class ItemType>
bool bagInterface<ItemType>::remove(const ItemType & item)const{
    return false;
}

//container
template<class ItemType>
bool bagInterface<ItemType>::contains(const ItemType & item) const{
    if(getFrequency()>0){
        return true;
    }
    return false;
    
}
//clear
template<class ItemType>
void bagInterface<ItemType>::clear(){
    return itemCount=0;
}

//tovector
template<class ItemType>
vector<ItemType> bagInterface<ItemType>::toVector() const{
    vector<ItemType> bagContents;
    for(int i=0;i<itemCount;++i){
        bagContents.push_back(items[i]);
    }
    return bagContents;
}