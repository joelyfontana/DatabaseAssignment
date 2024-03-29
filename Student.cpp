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
	//cout << "in operator function" << endl;
	out << "\nID: " << c.ID << endl;
	//cout << "after ID" << endl;
	out << "Name: " << c.name << endl;
	out << "Grade: " << c.grade << endl;
	//cout << "after grade out" << endl;
	out << "Major: "<< c.major << endl;
	out <<"GPA: "<< c.GPA << endl;
	out <<"Advisor ID: " << c.adID << endl;
	return out;
}

istream& operator >>(istream& in, Student& c)
{
	//
}