#pragma once

using namespace std;

template <class itemType>
class DynamicStack
{
private:
	int top;
	int maxStack;
	itemType* items;
public:
	DynamicStack();
	DynamicStack(int max);
	~DynamicStack();
	bool isEmpty() const;
	bool isFull() const;
	void Push(itemType newItem);
	void Pop(itemType& item);
};