#include "DynamicQueue.h"

template<class ItemType>
DynamicQueue<ItemType>::DynamicQueue() : capacity(8), frontIdx(0), rearIdx(0), count(0) {
    data = new ItemType[capacity];
}

template<class ItemType>
DynamicQueue<ItemType>::~DynamicQueue() {
    delete[] data;
}

template<class ItemType>
void DynamicQueue<ItemType>::resize() {
    int newCap = capacity * 2;
    ItemType* newData = new ItemType[newCap];
    for (int i = 0; i < count; ++i)
        newData[i] = data[(frontIdx + i) % capacity];
    delete[] data;
    data = newData;
    capacity = newCap;
    frontIdx = 0;
    rearIdx = count;
}

template<class ItemType>
void DynamicQueue<ItemType>::enqueue(const ItemType& x) {
    if (count == capacity) resize();
    data[rearIdx] = x;
    rearIdx = (rearIdx + 1) % capacity;
    ++count;
}

template<class ItemType>
ItemType DynamicQueue<ItemType>::dequeue() {
    if (count == 0) return ItemType(); // or throw
    ItemType val = data[frontIdx];
    frontIdx = (frontIdx + 1) % capacity;
    --count;
    return val;
}

template<class ItemType>
int DynamicQueue<ItemType>::size() const {
    return count;
}

template<class ItemType>
ItemType DynamicQueue<ItemType>::front() const {
    if (count == 0) return ItemType(); 
    return data[frontIdx];
}

template<class ItemType>
void DynamicQueue<ItemType>::reverseFirstK(int k) {
    if (k <= 0 || k > count) return;
    ItemType* temp = new ItemType[k];
    for (int i = 0; i < k; ++i)
        temp[i] = data[(frontIdx + i) % capacity];
    for (int i = 0; i < k; ++i)
        data[(frontIdx + i) % capacity] = temp[k - 1 - i];
    delete[] temp;
}


template class DynamicQueue<int>;
