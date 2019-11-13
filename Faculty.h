/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Assignment 5 - Building a Database with BST*/

#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

class Faculty
{
	int ID;
	string name;
	string job;
	string department;
	//make the student IDs a gen linked list
	DoublyLinkedList <int>* studentIDs;
};