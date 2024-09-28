#ifndef Bag_INTERFACE_H
#define Bag_INTERFACE_H
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
using namespace std;

template<class ItemType>
class bagInterface{
    public:
    bagInterface();
    virtual int getCurrentSize(void)const=0;
    virtual int getFrequency(const ItemType & item) const=0;
    virtual bool isEmpty(void)const=0;
    virtual bool add(const ItemType & item)const =0;
    virtual bool remove(const ItemType & item)const=0;
    virtual bool contains(const ItemType & item)const=0;
    virtual void clear(void)=0;
    virtual vector<ItemType> toVector(void)const=0;
    private:
    static const int DEFAULT_Capacity=50;
    int itemCount;
    int maxItems;
    ItemType items[DEFAULT_Capacity];
};

#endif
