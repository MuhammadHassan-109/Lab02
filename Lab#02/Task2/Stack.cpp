#include "Stack.h"
using namespace std;
template <class Student>
studentStack<Student>::studentStack()
{
	top = -1;
	maxStack = 5;
	items = new Student[500];
}

template <class Student>
studentStack<Student>::studentStack(int max)
{
	top = -1;
	maxStack = max;
	items = new Student[max];
}

template <class Student>
studentStack<Student>::~studentStack()
{
	delete[] items;
}

template <class Student>
bool studentStack<Student>::isEmpty() const
{
	return top == -1;
}

template <class Student>
bool studentStack<Student>::isFull() const
{
	return top == maxStack - 1;
}

template <class Student>
void studentStack<Student>::Push(Student newItem)
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

template <class Student>
void studentStack<Student>::Pop(Student& item)
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