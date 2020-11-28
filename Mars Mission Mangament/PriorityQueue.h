#pragma once
#include "PriorityQueueNode.h"

template<typename T>
class PriorityQueue
{
private :
	PriorityQueueNode<T>* front;
	int count;
public:
	PriorityQueue() {
		front = nullptr;
        count = 0;
	}

    bool enqueue(const T& item, int priority) {
        PriorityQueueNode<T>* t, * q;
        t = new PriorityQueueNode<T>();
        t->setItem(item);
        t->setPriority(priority);
        if (front == nullptr || priority > front->getPriority()) {
            t->setNext(front);
            front = t;
            delete t;
            delete q;
            return true;
        }
        else {
            q = front;
            while (q->getNext() != nullptr && q->getNext()->getPriority() >= priority)
                q = q->getNext();
            t->setNext( q->getNext());
            q->setNext(t);
            delete t;
            delete q;
            return true;
        }
    }
    bool dequeue(T& item) {
        PriorityQueueNode<T>* t;
        if (front == nullptr) //if queue is null
            return false;
        else {
            t = front;
            item = t->getItem();
            front = front->getNext();
            delete t;
            return true;
        }
    }
    bool peek(T& item) //print queue 
    {
        if (front == nullptr) //if queue is null
            return false;
        else {
            item = front->getItem();
            return true;
        }
    }
};

