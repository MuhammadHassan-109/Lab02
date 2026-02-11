#pragma once

using namespace std;

template <class Student>
class studentStack
{
private:
	int top;
	int maxStack;
	Student* items;
public:
	studentStack();
	studentStack(int max);
	~studentStack();
	bool isEmpty() const;
	bool isFull() const;
	void Push(Student newItem);
	void Pop(Student& item);
};