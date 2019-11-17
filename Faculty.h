/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Assignment 5 - Building a Database with BST*/

#pragma once
#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

class Faculty
{
public:
	Faculty(int ID, string name, string job, string department);
	~Faculty();
	int ID;
	string name;
	string job;
	string department;
	//make the student IDs a gen linked list
	DoublyLinkedList <int>* studentIDs; 

	friend ostream& operator << (ostream& out, const Faculty& c);
	//friend ostream& operator >> (ostream& out, const Faculty& c);
};