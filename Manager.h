/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Assignment 5 - Building a Database with BST*/

#include <iostream>
#include "FileReader.h"
#include "Student.h"
#include "Faculty.h"
#include "DoublyLinkedList.h"
#include "BST.h"
using namespace std;

class Manager
{
	//make master student and faculty here
	BST<int, Student*>* masterStudent;
	BST<int, Faculty*>* masterFaculty;

	Manager();
	~Manager();

	// make a function that assigns the student to the correct faculty
	void assignAdvisor(Student student, Faculty faculty);
};