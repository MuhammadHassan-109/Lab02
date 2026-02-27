#pragma once

template<class ItemType>
class DynamicQueue {
    ItemType* data;
    int capacity;
    int frontIdx;
    int rearIdx;
    int count;
    void resize();
public:
    DynamicQueue();
    ~DynamicQueue();
    void enqueue(const ItemType& x);
    ItemType dequeue();
    int size() const;
    ItemType front() const;
    void reverseFirstK(int k);
};
