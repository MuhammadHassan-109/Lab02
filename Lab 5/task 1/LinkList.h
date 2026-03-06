#pragma once
using namespace std;

template <class ItemType>
class List
{
protected:
	struct node {
		ItemType info;
		struct node* next;
	};
	typedef struct node* NODEPTR;
	NODEPTR listptr;
public:
	List();
	~List();
	bool emptyList();
	bool insertafter(ItemType oldvalue, ItemType newvalue);
	bool deleteItem(ItemType oldvalue);
	void push(ItemType newvalue);
	void displayList();
	ItemType pop();
};




