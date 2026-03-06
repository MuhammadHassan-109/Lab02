#include <iostream>
#include "LinkList.h"


template<class ItemType>
List<ItemType>::List()
{
	listptr = 0;
}

template<class ItemType>
List<ItemType>::~List()
{
	NODEPTR p, q;
	for (p = listptr, q = p->next; p != nullptr; p = q, q = p->next)
	{
		delete p;
	}
}

template<class ItemType>
bool List<ItemType>::emptyList()
{
	return (listptr == 0);
}

template<class ItemType>
bool List<ItemType>::insertafter(ItemType oldvalue, ItemType newvalue)
{
	NODEPTR p = listptr;
	while (p != nullptr && p->info != oldvalue)
	{
		p = p->next;
	}
	if (p == nullptr)
	{
		cout << "\nThe Searched value does not exist in the list" << endl;
		return false; // Indicate failure
	}

	NODEPTR q = new node;
	q->info = newvalue;
	q->next = p->next;
	p->next = q;
	return true; // Indicate success
}


template<class ItemType>
bool List<ItemType>::deleteItem(ItemType oldvalue)
{
	NODEPTR p = listptr, q = nullptr;
	while (p != nullptr && p->info != oldvalue) 
	{
		q = p;
		p = p->next;
	}
	if (p == nullptr) {
		cout << "\nValue not found in the list" << endl;
		return false; 
	}
	if (q == nullptr) 
	{
		listptr = p->next;
	}
	else 
	{
		q->next = p->next;
	}
	delete p;
	return true; 
}


template<class ItemType>
void List<ItemType>::push(ItemType newvalue)
{
	NODEPTR p;
	p = new node;
	p->info = newvalue;
	p->next = listptr;
	listptr = p;
}

template<class ItemType>
ItemType List<ItemType>::pop()
{
	NODEPTR p;
	ItemType x;
	if (emptyList())
	{
		cout << " ERROR: the list is empty.";
		exit(1);
	}
	p = listptr;
	listptr = p->next;
	x = p->info;
	delete p;
	return x;
}
template<class ItemType>
void List<ItemType>::displayList()
{
	NODEPTR p;
	for (p = listptr; p != nullptr; p = p->next)
	{
		cout << p->info << "  ";
	}
	cout << endl;
}