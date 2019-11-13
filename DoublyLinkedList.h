/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Assignment 4 - Registrar's Office*/

//to solve the redefining errors (when the class is being called multiple times)
#pragma once
#include <iostream>
#include "listNode.h"
using namespace std;


//make the class a template class
template <class T>
//doubly linked list class
class DoublyLinkedList
{
//make the nodes
public:
	ListNode<T> *front;
	ListNode<T> *back;
//make size unsigned so it cant go negative
	unsigned int size;

//constructor
	DoublyLinkedList();
	//Destructors
	~DoublyLinkedList();

	void insertFront(T d);
	void insertBack(T d);
	T removeFront();
	T removeBack();
	T deletePos(int position);
	int find(T d);

	bool isEmpty();
	void printList();
	unsigned int getSize();
};

//doubly linked list implementation

//constructor
template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	size = 0;
	front = NULL;
	back = NULL;
}

//destrcutor
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
//make both pointers equal to the front
	ListNode<T>* current = front;
	ListNode<T>* previous = front;

	//iterate through the pointers
	while (current != NULL)
	{
		previous = current;
		current = current->next;
		previous = NULL;
	}
}

//insert front function
template <class T>
void DoublyLinkedList<T>::insertFront(T d)
{
	//create a new node of template type
	ListNode<T>* node = new ListNode<T>(d);
	
	//check to see if the list is empty
	if (size == 0)
	{
	//the front and the back are the same 
		back = node;
	}
	//if the list is not empty, insert the new node into the beginning of the list
	else
	{
		
		front->prev = node;
		node->next = front;
	}
	//make the new node the front and increment the size
	front = node;
	size++;
}

//remove front function
template <class T>
T DoublyLinkedList<T>::removeFront()
{ 
	//make sure the list is not empty and if it is throw an error
	if (isEmpty())
	{
		throw runtime_error("list is empty");
	}

	ListNode<T>* frontTemp = front;
	//check to see if the list is empty before removing
	if (size == 1)
	{
		back = NULL;
	}
	else
	{
	//deletes the pointer that points back to the front element so you cant go back - but can still go forward
		front->next->prev = NULL;
	}
	//move the front variable to the next node - now front only exists in the frontTemp variable
	front = front->next;
	//store the front's data in a temp variable
	T temp = frontTemp->data;
	//empty the front
	frontTemp->next = NULL;
	delete frontTemp;
	//decrease size
	size--;

	return temp;
}

//insert back function
template <class T>
void DoublyLinkedList<T>::insertBack(T d)
{
	//create a new node
	ListNode<T>* node = new ListNode<T>(d);

	///check if the list is empty
	if (isEmpty())
	{
	//the front is the same as node
		front = node;
	}
	else
	{
	//if not empty
		back->next = node;
		node->prev = back;
	}
	back = node;
	size++;
}

//remove the last element in the list
template <class T>
T DoublyLinkedList<T>::removeBack()
{
	//make sure the list is not empty and if it is throw an error
	if (isEmpty())
	{
		throw runtime_error("list is empty");
	}
	//make a new node
	ListNode<T>* backTemp = back;
	
	//if there is one element in the list make the back and the front the same
	if (size == 1)
	{
		back = NULL;
	}
	else
	{
		back->previous->next = NULL;
	}
	back = back->previous;
	T temp = backTemp->data;
	backTemp->previous = NULL;
	delete backTemp;
	size--;
	return temp;
}

//may be only for linked lists not doubly linked lists!!!
template <class T>
T DoublyLinkedList<T>::deletePos(int pos)
{
	int index = 0;
	ListNode<T>* current = front;
	ListNode<T>* previous = front;

	while (index != pos)
	{
		previous = current;
		current = current->next;
		index++;
	}
}

//search/ find function
template <class T>
int DoublyLinkedList<T>::find(T d)
{
	int index=0;
	ListNode<T>* current = front;

	while (current != NULL)
	{
		if (current->data == d)
		{
			break;
		}
		index++;
		current = current->next;
	}
	if (current = NULL)
	{
		index = -1;
	}
	return index;
}

//prints the list 
template <class T>
void DoublyLinkedList<T>::printList()
{
	ListNode<T>* current = front;
	while (current != NULL)
	{
		cout << current->data << endl;
		current = current->next;
	}
}

//print the size of the list
template <class T>
unsigned int DoublyLinkedList<T>::getSize()
{
	return size;
}

//boolean to check to see if the list is empty or not
template <class T> 
bool DoublyLinkedList<T>::isEmpty()
{
	if (size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}