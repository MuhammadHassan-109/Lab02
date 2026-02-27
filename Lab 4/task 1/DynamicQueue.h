#pragma once

template <class ItemType>
class DynamicQueue {
private:
    ItemType* data;
    int front;
    int rear;
    int count;
    int capacity;

    void resize();

public:
    DynamicQueue(int initialCapacity = 4);
    ~DynamicQueue();

    void Enqueue(const ItemType& value);
    ItemType Dequeue();
    ItemType Peek() const;
    bool IsEmpty() const;
    bool IsFull() const;
    int Size() const;
};
