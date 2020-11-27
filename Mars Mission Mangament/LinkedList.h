#ifndef _LINKEDLIST
#define _LINKEDLIST

#include "Node.h"
#include <iostream>

using namespace std;
template <typename T>
class LinkedList
{
private:
	Node<T> *Head;	//Pointer to the head of the list
	//You can add tail pointer too (depending on your problem)
	int count;	//Number of nodes in the list
public:

	LinkedList()
	{
		count = 0;
		Head = nullptr;
	}
	/*bool operator == (const string& str1, const string& str2)
	{
		return str1.compare(str2) == 0;
	}

	bool operator > (const string& str1, const string& str2)
	{
		return str1.compare(str2) > 0;
	}

	bool operator <(const string& str1, const string& str2)
	{
		return str1.compare(str1) < 0;
	}*/
	/////////////////////////////////////////////////

	Node<T>* getHead() {
		return Head;
	}
	
	int getCount() {
		return count;
	}

	////////////////////////////////////////////////////////////////////////
	/*
	* Function: PrintList.
	* prints the values of all nodes in a linked list.
	*/
	void PrintList()	const
	{
		cout<<"\nList has "<<count<<" nodes";
		cout<<"\nPrinting list contents:\n\n";
		Node<T> *p = Head;

		while(p)
		{
			cout << "[ " << p->getItem() << " ]";
			cout << "--->";
			p = p->getNext();
		}
		cout << "*\n";
	}
	////////////////////////////////////////////////////////////////////////
	/*
	* Function: InsertBeg.
	* Creates a new node and adds it to the beginning of a linked list.
	* 
	* Parameters:
	*	- data : The value to be stored in the new node.
	*/
	void InsertBeg(const T &data)
	{
		Node<T> *R = new Node<T>(data);
		R->setNext(Head);
		Head = R;
		count++;
	}

	////////////////////////////////////////////////////////////////////////
	/*
	* Function: DeleteAll.
	* Deletes all nodes of the list.
	*/
	void DeleteAll()
	{
		Node<T> *P = Head;
		while (Head)
		{
			P = Head->getNext();
			delete Head;
			Head = P;
		}
		count = 0;
	}
	////////////////////////////////////////////////////////////////////////
	//List is being desturcted ==> delete all items in the list
	~LinkedList()
	{
		DeleteAll();
	}

	////////////////////////////////////////////////////////////////////////
	////////////////     Requirements   ///////////////////
	//
	// Implement the following member functions


	//[1]InsertEnd 
	//inserts a new node at end if the list
	void InsertEnd(const T& data) {

		if (Head == nullptr) {
			InsertBeg(data);
			return;
		}
		else {
			Node<T>* p = Head;
			while (p->getNext()) {
				p = p->getNext();
			}
			Node<T>* R = new Node<T>(data);
			p->setNext(R);
			count++;
			return;
		}
	}

	//[2]Find 
	//searches for a given value in the list, returns true if found; false otherwise.
	bool Find(T Key) {
		Node<T>* p = Head;
		while (p) {
			if (p->getItem() == Key) {
				cout << "Found the element " << Key << endl;
				return true;
			}
			p = p->getNext();
		}
		cout << "\nElement " << Key << " not found" << endl;
		return false;
	}

	//[3]CountOccurance
	//returns how many times a certain value appeared in the list
	int CountOccurance(const T& value) {
		int noOfOccurances = 0 ;
		Node<T> * pointer = Head;
		while (pointer) {
			if (pointer->getItem() == value) {
				noOfOccurances++;
			}
			pointer = pointer->getNext();
		}
		return noOfOccurances;
	}

	//[4] DeleteFirst
	//Deletes the first node in the list
	void DeleteFirst() {
		Node<T>* P = Head;
		if (Head->getNext() == nullptr) {
			Head = nullptr;
			delete P;
			count--;
		}
		else if (Head->getNext()) {
		Head = Head->getNext();
		delete P;
		count--;
}
		
	}

	//[5] DeleteLast
	//Deletes the last node in the list
	void DeleteLast() {
		if (Head == nullptr) {
			return;
		}
		else {
			Node<T>* p = Head;
			while (p->getNext()) {
				p = p->getNext();
			}
			delete p;
			count--;
			return;
		}
	}

	//[6] DeleteNode
	//deletes the first node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
	bool DeleteNode(const T& value) {
		if (Head->getNext() == nullptr) {
			if (Head->getItem() == value) {
				DeleteFirst();
				count--;
				return true;
			}
			else {
				return false;
			}
			
		}
		else if (Find(value)) {
			Node<T>* p = Head;
			while (p) {
				if (p->getNext()->getItem() == value) {
					Node<T>* foundNode = p->getNext();
					p->setNext(foundNode->getNext());
					delete foundNode;
					count--;
					return true;
				}
				p = p->getNext();
			}
		}
		else {
			return false;
		}
	}

	//[7] DeleteNodes
	//deletes ALL node with the given value (if found) and returns true
	//if not found, returns false
	//Note: List is not sorted
	bool DeleteNodes(const T& value) {
		bool isFound = false;
		if (Head->getNext() == nullptr) {
			if (Head->getItem() == value) {
				DeleteFirst();
				count--;
				isFound = true;
			}
			else {
				isFound =  false;
			}

		}
		else if (Find(value)) {
			Node<T>* p = Head;
			while (p) {
				if (p->getNext()->getItem() == value) {
					Node<T>* foundNode = p->getNext();
					p->setNext(foundNode->getNext());
					delete foundNode;
					count--;
					isFound = true;
				}
				p = p->getNext();
			}
		}
		else {
			isFound = false;
		}
		return isFound;
	}

	//[8]Merge
	//Merges the current list to another list L by making the last Node in the current list 
	//point to the first Node in list L
	void Merge(const LinkedList& L) {
		if (Head == nullptr) {
			Head = L.Head;
		}
		else {
			Node<T>* p = Head;
			while (p->getNext()) {
				p = p->getNext();
			}
			p->setNext(L.Head);
			count += L.count;
		}
	}

	//[9] Reverse
	//Reverses the linked list (without allocating any new Nodes)
	void Reverse() {

	}

	/////////////////////////////////////////////////
	// Excercise 3:
	//[a]
	void PrintKth(int k) {
		int n = 0;
		if (Head == nullptr) {
			cout << "Beyond List Length";
			return;
		}
		else {
			Node<T>* p = Head;
			while (p) {
				if (n == k) {
					cout << "The element that is at index " << k << " has a value of " << p->getItem();
					return;
				}
				p = p->getNext();
				n++;
			}
			cout << "Beyond List Length";
			return;
		}
	}

	//[b]
	bool InsertSorted(T data) {
		if (Head == nullptr) {
			Node<T>* p = new Node<T>(data);
			Head = p;
			return true;
		}
		else {
			Node<T>* p = Head;
			Node<T>* previousPtr = nullptr;
			while (p) {
				if (data == p->getItem()) {
					return false;
				}
				else if(data < p->getItem()){
					Node<T>* newData = new Node<T>(data);
					newData->setNext(p);
					previousPtr->setNext(newData);
					return true;
				}
				else if (p->getNext() == nullptr) {
					this->InsertEnd(data);
					return true;
				}
				previousPtr = p;
				p = p->getNext();
			}
		}
	}

	//[c]
	
	Node<T>* GetMin() {
		if (Head == nullptr) {
			return nullptr;
		}
		else {
			Node<T>* min = Head;
			Node<T>* ptr = Head;
			while (ptr) {
				if (ptr->getItem() <= min->getItem()) {
					min = ptr;
				}
				ptr = ptr->getNext();
			}
			return min;

		}
	}

	Node<T>* RemoveMin() {
		if (Head == nullptr) {
			return nullptr;
		}
		else {
			Node<T>* min = Head;
			Node<T>* ptr = Head;
			Node<T>* previousPtr = nullptr;
			if (ptr->getNext()->getItem() <= min->getItem()) {
				min = ptr->getNext();
				previousPtr = ptr;
			}
			while (ptr->getNext()) {
				if (ptr->getNext()->getItem() <= min->getItem()) {
					min = ptr->getNext();
					previousPtr = ptr;
				}
				ptr = ptr->getNext();
			}
			previousPtr->setNext(min->getNext());
			return min;

		}
	}

	//[d]
	LinkedList<T> CloneList() {
		LinkedList<T> newList;
		if (Head == nullptr) {
			return newList;
		}
		else {
			Node<T>* p = Head;
			while (p) {
				newList.InsertEnd(p->getItem());
				p = p->getNext();
			}
			return newList;
		}
	}

	//[e]
	//It returns an array of two lists the first elemnt contains the Lneg and the second is Lpos
	LinkedList<T>* SignSplit() {
		LinkedList<T> Lneg;
		LinkedList<T> Lpos;
		LinkedList<T> listsArray[2] = {};

		if (Head == nullptr) {
			listsArray[0] = Lneg;
			listsArray[1] = Lpos;
			return listsArray;
		}
		else {
			Node<T> p = Head;

			while (p) {
				if (p->getItem() < 0) {
					Lneg.InsertEnd(p->getItem());
					DeleteNode(p);
				}
				else if(p->getItem() > 0) {
					Lpos.InsertEnd(p->getItem());
					DeleteNode(p);
				}
				p = p->getNext();
			}
			listsArray[0] = Lneg;
			listsArray[1] = Lpos;
			return listsArray;
		}
	}

	//[f]

	//[g]
	LinkedList MergeSorted(LinkedList list1, LinkedList list2) {
		LinkedList mergedList;
		if (list1.getHead() == nullptr) {
			return list2;
		}
		else if (list2.getHead() == nullptr) {
			return list1;
		}
		else {
			Node<T>* ptr1 = list1.getHead();
			Node<T>* ptr2 = list2.getHead();
			while (ptr1) {
				mergedList.InsertEnd(ptr1->getItem());
				ptr1 = ptr1->getNext();
			}
			while (ptr2) {
				mergedList.InsertSorted(ptr2->getItem());
				ptr2 = ptr2->getNext();
			}
		}
	}

	//[h]
	LinkedList SumLists(LinkedList l1, LinkedList l2) {
		LinkedList sumList;
		if (l1.getCount() != l2.getCount()) {
			return NULL;
		}
		else {
			if (l1.getHead() == nullptr) {
				return sumList;
			}
			else {
				Node<T>* p1 = l1.getHead();
				Node<T>* p2 = l2.getHead();
				while (p1) {
					sumList.InsertEnd(p1->getItem() + p2->getItem());
					p1 = p1->getNext();
					p2 = p2->getNext();
				}
				return sumList;
			}

		}
	}

	//[i]
	void ReorderX(T x) {
		if (Head == nullptr) {
			return;
		}
		else {

			LinkedList beforex;
			LinkedList afterx;
		
			Node<T>* p = Head;
			while (p) {
				if (p->getItem <= x) {
					beforex.InsertEnd(p->getItem());
					DeleteNode(p->getItem());
				}
				else {
					afterx.InsertEnd(p->getItem());
					DeleteNode(p->getItem());
				}
				p = p->getNext();
			}
			beforex.Merge(afterx);
			Head = beforex.getHead();
		}
	}

	//[j]
	void ShiftLargest() {
		if (Head == nullptr) {
			return;
		}
		else {
			Node<T>* p = Head;
			T max = p->getItem;
			while (p->getNext()) {
				if (p->getNext()->getItem()> max) {
					Node<T>* temp = p->getNext();
					p->setNext(temp->getNext());
					temp->setNext(p->getNext()->getNext());
					p->getNext()->setNext(temp);
				}
				p = p->getNext();
			}
		}
	}


};

#endif	
