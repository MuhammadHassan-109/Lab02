#include "Dlist.h"
#include <iostream>
using namespace std;


template <class ItemType>
Dlist<ItemType>::Dlist()
{
	listptr = 0;
}

template <class ItemType>
Dlist<ItemType>::~Dlist()
{
	NODEPTR p = listptr;
	while (p != nullptr)
	{
		NODEPTR temp;
		temp = p->next;
		delete p;
		p = temp;
	}
}

template <class ItemType>
bool Dlist<ItemType>::emptyList()
{
	return listptr == 0;
}

template <class ItemType>
void Dlist<ItemType>::insertSorted(ItemType newvalue)
{
    NODEPTR r = new node;
    r->info = newvalue;
    r->next = nullptr;
    r->prev = nullptr;

    if (emptyList())
    {
        listptr = r;
        cout << "\nValue inserted successfully." << endl;
        system("pause");
        return;
    }

    NODEPTR p = listptr;

    // Insert before head
    if (newvalue < p->info)
    {
        r->next = p;
        p->prev = r;
        listptr = r;
        cout << "\nValue inserted successfully." << endl;
        system("pause");
        return;
    }

    while (p->next != nullptr && p->next->info < newvalue)
    {
        p = p->next;
    }
    if (p->next == nullptr)
    {
        r->prev = p;
        r->next = nullptr;
        p->next = r;
    }
    else
    {
        r->next = p->next;
        r->prev = p;
        p->next->prev = r;
        p->next = r;
    }
    cout << "\nValue inserted successfully." << endl;
    system("pause");
    return;
}

template <class ItemType>
void Dlist<ItemType>::Deletion(ItemType value)
{
    if (emptyList())
    {
        cout << "\nList is empty\n";
        system("pause");
        return;
    }
    NODEPTR p;
    p = listptr;

    if (p->info == value)
    {
        listptr = p->next;
        if (listptr != nullptr)
        {
            listptr->prev = nullptr;
        }
        delete p;
        cout << "\nValue deleted successfully." << endl;
        system("pause");
        return;
    }

    while (p != nullptr && p->info != value)
    {
        p = p->next;
    }
    if (p == nullptr)
    {
        cout << "\nThe value is not found in the list\n";
        system("pause");
        return;
    }
    else
    {
        if (p->next != nullptr)
        {
            p->next->prev = p->prev;
        }
        if (p->prev != nullptr)
        {
            p->prev->next = p->next;
        }
        delete p;
        cout << "\nValue deleted successfully." << endl;
        system("pause");
    }
}


template <class ItemType>
void Dlist<ItemType>::Traversing()
{
	if (emptyList())
	{
		cout << "List is empty." << endl;
		return;
	}
	NODEPTR p = listptr;
	cout << "List contents: ";
	while (p != nullptr)
	{
		cout << p->info << " ";
		p = p->next;
	}
	cout << endl;
}

template <class ItemType>
void Dlist<ItemType>::Search(ItemType value)
{
    int pos = 1;
	if (emptyList())
	{
		cout << "List is empty." << endl;
		return;
	}
	NODEPTR p = listptr;
	while (p != nullptr)
	{
		if (p->info == value)
		{
			cout << "Value " << value << " found in the list on "<<pos<<" position." << endl;
			return;
            
		}
        pos++;
		p = p->next;
	}
	cout << "Value " << value << " not found in the list." << endl;
}
