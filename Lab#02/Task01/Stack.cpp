#include "Stack.h"
using namespace std;
template <class itemType>
DynamicStack<itemType>::DynamicStack()
{
	top = -1;
	maxStack = 5;
	items = new itemType[500];
}

template <class itemType>
DynamicStack<itemType>::DynamicStack(int max)
{
	top = -1;
	maxStack = max;
	items = new itemType[max];
}

template <class itemType>
DynamicStack<itemType>::~DynamicStack()
{
	delete[] items;
}

template <class itemType>
bool DynamicStack<itemType>::isEmpty() const
{
	return top == -1;
}

template <class itemType>
bool DynamicStack<itemType>::isFull() const
{
	return top == maxStack - 1;
}

template <class itemType>
void DynamicStack<itemType>::Push(itemType newItem)
{
	if (isFull())
	{
		throw "\nStack Overflow";
	}
	else
	{
		top++;
		items[top] = newItem;
	}
}

template <class itemType>
void DynamicStack<itemType>::Pop(itemType& item)
{
	if (isEmpty())
	{
		throw "\nStack Underflow";
	}
	else
	{
		item = items[top];
		top--;
	}
}