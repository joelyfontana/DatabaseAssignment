/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Assignment 5 - Building a Database with BST*/

#include <iostream>
#include "Student.h"
using namespace std;

Student::Student(int ID, string name, string grade, string major, double GPA, int adID)
{
	this->ID = ID;
	this->name = name;
	this->grade = grade;
	this->major = major;
	this->GPA = GPA;
	this->adID = adID;
}

Student::~Student()
{

}

//overloaded operator functions
ostream& operator<<(ostream& out, const Student& c)
{
	cout << "in operator function" << endl;
	out << c.ID << endl;
	cout << "after ID" << endl;
	out << c.name << endl;
	out << c.grade << endl;
	cout << "after grade out" << endl;
	out << c.major << endl;
	out << c.GPA << endl;
	out << c.adID << endl;
	return out;
}

istream& operator >>(istream& in, Student& c)
{
	//
}