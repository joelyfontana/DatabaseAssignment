/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Assignment 4 - Registrar's Office*/

//to solve the redefining errors (when the class is being called multiple times)
#pragma once
#include <iostream>
using namespace std;

//make a template 
template <class T>

//make the node class
class ListNode
{
public:
	T data;
	//make the pointers
	ListNode<T> *next;
	ListNode<T> *prev;

	//constructor
	ListNode();
	//overloaded constructor
	ListNode(T d);
	//destructor
	~ListNode();
};

//ListNode Functions
//constructor 
template <class T>
ListNode<T>::ListNode() {}

//overloaded constructor
template <class T>
ListNode<T>::ListNode(T d)
{
	data = d;
	next = NULL;
	prev = NULL;
}

//destructor
template <class T>
ListNode<T>::~ListNode()
{
	next = NULL;
	prev = NULL;
}
