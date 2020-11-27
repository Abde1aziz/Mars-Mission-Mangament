#pragma once

template<typename T>
class PriorityQueueNode
{
private:
	int priority;
	T item;
	PriorityQueueNode<T>* next;
public:
	PriorityQueueNode() //default constructor
	{
		next = nullptr;
	}

	PriorityQueueNode(T newItem, int priorty) //non-default constructor
	{
		priority = priorty;
		item = newItem;
		next = nullptr;
	}

	void setItem(T newItem)
	{
		item = newItem;
	} // end setItem

	void setNext(PriorityQueueNode<T>* nextNodePtr)
	{
		next = nextNodePtr;
	} // end setNext

	void setPriority(int priorty) {
		priority = priorty;
	}

	T getItem() const
	{
		return item;
	} // end getItem

	PriorityQueueNode<T>* getNext() const
	{
		return next;
	}

	int getPriority() const {
		return priority;
	}
};

