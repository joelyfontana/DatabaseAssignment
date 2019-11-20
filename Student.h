/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Assignment 5 - Building a Database with BST*/

#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Student
{
public:
	Student(int ID, string name, string grade, string major, double GPA, int adID);
	~Student();
	//overloading the operators << and >>
	friend ostream& operator << (ostream& out, const Student& c);
	friend istream& operator >> (istream& out, const Student& c);
	int ID;
	string name;
	string grade;
	string major;
	double GPA;
	int adID;
};