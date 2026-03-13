#pragma once

using namespace std;


template<class ItemType>
class List
{
protected:
	struct node
	{
		ItemType info;
		struct node* next;
	};
	typedef struct node* NODEPTR;
	NODEPTR listptr;
public:
	List();
	~List();
	bool emptyList();
	void insertSorted(ItemType newvalue);
	void Deletion(ItemType value);
	void Traversing();
	void Search(ItemType value);
};

