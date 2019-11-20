/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Assignment 5 - Building a Database with BST*/

#include <iostream>
#include "Faculty.h"
using namespace std;

//constructor
Faculty::Faculty(int ID, string name, string job, string department)
{
	this->ID = ID;
	this->name = name;
	this->job = job;
	this->department = department;
	//this->studentIDs = studentIDs;
	//make an empty list of student IDs
	studentIDs = new DoublyLinkedList<int>();
}
Faculty::~Faculty()
{

}

//overloaded operator functions
ostream& operator <<(ostream& out, const Faculty& c)
{
	out << c.ID << endl;
	out << c.name << endl;
	out << c.job << endl;
	out << c.department << endl;
	out << *(c.studentIDs) << endl;
	return out;
}

//add students to the faculty list
void Faculty::addStudent(int ID)
{
	studentIDs->insertFront(ID);
}

//remove students from the faculty list
void Faculty::removeStudent(int ID)
{
	studentIDs->remove(ID);
}

////make a function that inputs all of a faculty's advisees into their list
//void Faculty::addAdvisees(int ID)
//{
//	studentIDs->insertFront(ID);
//}


