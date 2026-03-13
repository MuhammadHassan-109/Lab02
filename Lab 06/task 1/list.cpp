#include "list.h"
#include <iostream>

/* Some conventions are:
* listptr = first element
* ->next = address of the next element
* ->info = value of the element stored in the node
* system("pause") is a built in function that waits for a keypress
* system("cls") clears the terminal screen
*/
template<class ItemType>
List<ItemType>::List()
{
	listptr = 0;
}


template<class ItemType>
List<ItemType>::~List()
{
	NODEPTR p = listptr;
	while (p != nullptr)
	{
		//Iterate throught the whole list and delete all elements one by one
		NODEPTR temp;
		temp = p->next;
		delete p;
		p = temp;
	}
}

template<class ItemType>
bool List<ItemType>::emptyList()
{
	return (listptr == nullptr);
}

template<class ItemType>
void List<ItemType>::insertSorted(ItemType newvalue)
{
	NODEPTR p = new node;
	//insertion at start in case of empty list or newvalue being the smallest value
	if (emptyList() || newvalue < listptr->info)
	{

		p->info = newvalue;
		p->next = listptr;
		listptr = p;
		cout << "\nValue inserted" << endl;
		system("pause");

		return;
	}

	NODEPTR l = listptr;
	//insertion at the middle or the end
	while (l->next != nullptr && l->next->info < newvalue)
	{
		l = l->next;
	}

	p->info = newvalue;
	p->next = l->next;
	l->next = p;
	cout << "\nValue inserted" << endl;
	system("pause");

	return;
}


template<class ItemType>
void List<ItemType>::Deletion(ItemType value)
{

	if (emptyList())
	{
		cout << "\nList is empty.... " << endl;
		return;
	}
	NODEPTR q = listptr;
	NODEPTR p = listptr->next;
	//if the value to be deleted is the first value
	if (q->info == value)
	{
		listptr = q->next;
		delete q;
		cout << "\nValue deleted." << endl;
		system("pause");
		return;
	}
	//to traverse and find the value
	while (p != nullptr && p->info != value)
	{
		q = p;
		p = p->next;
	}

	if (p == nullptr)
	{
		//this case is for if the value is not found in the lsit
		cout << "\nThe sought value does not exist in the list" << endl;
		system("pause");

		return;
	}
	q->next = p->next;
	delete p;
	cout << "\nDeleted " << value << " from the list" << endl;
	system("pause");

	return;
}

template<class ItemType>
void List<ItemType>::Traversing()
{
	if (emptyList())
	{
		cout << "\nThe list is empty" << endl;
		return;
	}

	NODEPTR p;
	p = listptr;
	while (p != nullptr)
	{
		//access all elements
		cout << p->info << " -> ";
		p = p->next;
	}
	cout << "null" << endl;
	return;
}

template<class ItemType>
void List<ItemType>::Search(ItemType value)
{
	int pos = 1;
	if (emptyList())
	{
		cout << "The list is empty...." << endl;
		return;
	}
	NODEPTR p = listptr;
	//To iterate throught the list until the list ends or the value is found
	while (p != nullptr && p->info != value)
	{
		p = p->next;
		pos++;
	}
	if (p == nullptr)
	{
		//case if the value is not found in the list
		cout << "\nThe sought value is not found in the list...." << endl;
		return;
	}
	else
	{
		//if the value is found
		cout << "\nValue " << value << " found at position " << pos << endl;
	}
	return;
}

