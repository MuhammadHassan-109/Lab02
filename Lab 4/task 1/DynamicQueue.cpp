#include "DynamicQueue.h"
#include <stdexcept>

using namespace std;

template <class ItemType>
DynamicQueue<ItemType>::DynamicQueue(int initialCapacity)
    : front(0), rear(0), count(0), capacity(initialCapacity)
{
    data = new ItemType[capacity];
}

template <class ItemType>
DynamicQueue<ItemType>::~DynamicQueue()
{
    delete[] data;
}

template <class ItemType>
void DynamicQueue<ItemType>::resize()
{
    int newCapacity = capacity * 2;
    ItemType* newData = new ItemType[newCapacity];

    for (int i = 0; i < count; ++i)
        newData[i] = data[(front + i) % capacity];

    delete[] data;
    data = newData;
    front = 0;
    rear = count;
    capacity = newCapacity;
}

template <class ItemType>
void DynamicQueue<ItemType>::Enqueue(const ItemType& value)
{
    if (IsFull())
        resize();

    data[rear] = value;
    rear = (rear + 1) % capacity;
    ++count;
}

template <class ItemType>
ItemType DynamicQueue<ItemType>::Dequeue()
{
    if (IsEmpty())
        throw out_of_range("Queue is empty");

    ItemType value = data[front];
    front = (front + 1) % capacity;
    --count;
    return value;
}

template <class ItemType>
ItemType DynamicQueue<ItemType>::Peek() const
{
    if (IsEmpty())
        throw out_of_range("Queue is empty");

    return data[front];
}

template <class ItemType>
bool DynamicQueue<ItemType>::IsEmpty() const
{
    return count == 0;
}

template <class ItemType>
bool DynamicQueue<ItemType>::IsFull() const
{
    return count == capacity;
}

template <class ItemType>
int DynamicQueue<ItemType>::Size() const
{
    return count;
}

// Explicit template instantiation for int (add more types as needed)
template class DynamicQueue<int>;
