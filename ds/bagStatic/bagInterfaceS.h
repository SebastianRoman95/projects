#ifndef Bag_INTERFACE_H
#define Bag_INTERFACE_H
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
using namespace std;

template<class ItemType>
class bagInterfaceS{
    public:
    bagInterfaceS();
    virtual int getCurrentSize(void)=0;
    virtual int getFrequency(ItemType & item) =0;
    virtual bool isEmpty(void)=0;
    virtual bool add(ItemType & item) =0;
    virtual bool remove( ItemType & item)=0;
    virtual bool contains( ItemType & item)=0;
    virtual void clear(void)=0;
    virtual vector<ItemType> toVector(void)=0;
    private:
    int DEFAULT_Capacity=50;
    int itemCount;
    int maxItems;
    ItemType items[DEFAULT_Capacity];
};

#endif
