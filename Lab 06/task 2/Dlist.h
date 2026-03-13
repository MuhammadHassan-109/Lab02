#pragma once

using namespace std;

template <class ItemType>
class Dlist
{
protected:
	struct node
	{
		ItemType info;
		struct node* next;
		struct node* prev;
	};
	typedef struct node* NODEPTR;
	NODEPTR listptr;
public:
	Dlist();
	~Dlist();
	bool emptyList();
	void insertSorted(ItemType newvalue);
	void Deletion(ItemType value);
	void Traversing();
	void Search(ItemType value);
};