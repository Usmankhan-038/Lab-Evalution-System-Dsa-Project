#pragma once
#include <iostream>
using namespace std;

template<class ItemType>
struct Node
{
	ItemType info;
	struct Node* next;
	struct Node* pre;
};

template<class ItemType>
class List
{
	typedef struct Node<ItemType>* NodePtr;
	NodePtr start; // start pointer
public:
	List();
	~List();
	bool isEmptyList();
	void traverse();
	void insertAtStart(ItemType newItem);
	void insertAtEnd(ItemType newItem);
	void insertAtMiddle(ItemType key, ItemType newItem);
	ItemType deleteAtStart();
	ItemType deleteAtEnd();
	ItemType deleteAtMiddle(ItemType key);
	NodePtr getStart();
};
template<class ItemType>
struct Node<ItemType>* List <ItemType>::getStart()
{
	return this->start;
}
template<class ItemType>
List <ItemType>::List()
{
	start = NULL;
}
template<class ItemType>
List <ItemType>::~List()
{
	NodePtr p, q;
	if (isEmptyList())
		exit(0);
	for (p = start, q = p->next; p != 0; p = q, q = p->next)
		delete p;
}
template<class ItemType>
bool List <ItemType>::isEmptyList()
{
	return (start == NULL);
}
template<class ItemType>
void List <ItemType>::traverse()
{
	NodePtr p;
	p = start;
	if (start != NULL)
	{
		while (p != NULL)
		{
			cout << " \n\t\t\t\t\t" << p->info;
			p = p->next;
		}
	}
	else
	{
		cout << "List is empty" << endl;
	}
}
template<class ItemType>
void List <ItemType>::insertAtStart(ItemType newItem)
{
	NodePtr p = new Node<ItemType>;
	p->info = newItem;
	if (start == NULL)
	{
		p->next = NULL;
	}
	else
	{
		start->pre = p;
		p->next = start;
	}
	p->pre = NULL;
	start = p;

}
template<class ItemType>
void List <ItemType>::insertAtEnd(ItemType newItem)
{
	if (start == NULL)
		insertAtStart(newItem);
	else
	{
		NodePtr p, q = NULL;
		for (p = start; p->next != NULL; p = p->next);

		q = new Node<ItemType>;
		q->next = NULL;
		q->info = newItem;
		q->pre = p;
		p->next = q;
	}

}

template<class ItemType>
void List <ItemType>::insertAtMiddle(ItemType key, ItemType newItem)
{
	if (start == NULL)
	{
		insertAtStart(newItem);
	}
	else
	{
		NodePtr p, q = NULL;
		for (p = start; p != NULL && p->info != key; p = p->next);
		if (p->info == key) //found 
		{
			q = new Node<ItemType>;
			NodePtr r = p->next;
			q->next = p->next;
			q->info = newItem;
			p->next = q;
			if (r != NULL)
			{
				r->pre = q;
			}
			q->pre = p;
		}
		else // not found the value
		{
			insertAtEnd(newItem);
		}
	}
}
template<class ItemType>
ItemType List <ItemType>::deleteAtStart()
{
	if (start != NULL)
	{
		NodePtr p = start;
		start = start->next;
		ItemType temp = p->info;
		delete p;
		if(start!=NULL)
			start->pre = NULL;
		return temp;
	}

}
template<class ItemType>
ItemType List <ItemType>::deleteAtEnd()
{
	if (start != NULL)
	{
		NodePtr p, q = NULL;
		for (p = start; p->next != NULL; p = p->next)
			q = p;
		if (q == NULL)
			return(deleteAtStart());
		else
		{
			q->next = NULL;
			ItemType temp = p->info;
			delete p;
			return temp;
		}
	}
}
template<class ItemType>
ItemType List <ItemType>::deleteAtMiddle(ItemType key)
{
	if (start == NULL)
	{
		ItemType obj;
		return obj;
	}
	else
	{
		NodePtr p, q = NULL;
		for (p = start; p != NULL && p->info != key; p = p->next)
			q = p;
		if (q == NULL)
			return(deleteAtStart());
		else if (p->info == key) // found
		{
			NodePtr r = p->next;
			q->next = p->next;
			ItemType temp = p->info;
			delete p;
			if (r != NULL)
			{
				r->pre = q;
			}
			return temp;
		}
	}
}