/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Assignment 5 - Building a Database with BST*/

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
	string studentFileName = "studentTable.txt";
	string facultyFileName = "facultyTable.txt";

	BST<int, Student*>* readStudentFile();
	BST<int, Faculty*>* readFacultyFile();
	//Binary search tree called studentTree of int student IDs and of values students as a pointer
	void writeToStudentFile(BST <int, Student*>* studentTree);
	//Binary search tree called facultyTree of int faculty IDs and of values faculty as a pointer
	void writeToFacultyFile(BST <int, Faculty*>* facultyTree);
};