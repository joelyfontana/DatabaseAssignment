/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Assignment 5 - Building a Database with BST*/

#pragma once
#include <iostream>
#include <fstream>
#include "BST.h"
#include "Student.h"
#include "Faculty.h"


using namespace std;

class FileReader
{
public:
	//constructor
	FileReader();
	//destructor
	~FileReader();
	//preset the files 
	//make them static because the information never changes and consts so they cant be changed (and saves memory)
	static const string studentFileName;
	static const string facultyFileName;

	static BST<int, Student*>* readStudentFile();
	static BST<int, Faculty*>* readFacultyFile();
	//Binary search tree called studentTree of int student IDs and of values students as a pointer
	static void writeToStudentFile(BST <int, Student*>* studentTree);
	//Binary search tree called facultyTree of int faculty IDs and of values faculty as a pointer
	static void writeToFacultyFile(BST <int, Faculty*>* facultyTree);
};