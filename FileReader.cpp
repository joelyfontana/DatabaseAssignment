/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Assignment 5 - Building a Database with BST*/

#include "FileReader.h"
using namespace std;

FileReader::FileReader()
{}
FileReader::~FileReader()
{}


//open the files that contains the tree, reads the file, and makes an object
BST<int, Student*>* FileReader::readStudentFile()
{
	//check to make sure the file exists
	ifstream studentFile;
	studentFile.open(studentFileName);
	if (!studentFile.is_open())
	{
		//if the file does not exist make an empty tree for each class (student and faculty)
		BST<int, Student*>* studentTree = new BST<int, Student*>();
		return studentTree;
	}
	//if the file does exist
	else
	{

	}
}

//check to see if the files are in the directory
BST<int, Faculty*>* FileReader::readFacultyFile()
{
	//check to make sure the file exists
	ifstream facultyFile;
	facultyFile.open(facultyFileName);
	if (!facultyFile.is_open())
	{
		//if the file does not exist make an empty tree for each class (student and faculty)
		BST<int, Faculty*>* facultyTree = new BST<int, Faculty*>();
		return facultyTree;
	}
	//if the file does exist
	else
	{

	}
}


//write the tree first, and then read it
// assume we already have the tree
void FileReader::writeToStudentFile(BST <int, Student*>* studentTree)
{
	//create and open the file to write out to
	ofstream studentFile;
	studentFile.open(studentFileName);
	//write and serialize the student tree
	studentFile.write((char*)&studentTree, sizeof(studentTree));
	cout << "student tree: " << studentTree << endl;
	//close the file you numbnut
	studentFile.close();
}

//write to the faculty tree
void FileReader::writeToFacultyFile(BST <int, Faculty*>* facultyTree)
{
	ofstream facultyFile;
	facultyFile.open(facultyFileName);
	//write and serialize the faculty tree
	facultyFile.write((char*)&facultyTree, sizeof(facultyTree));
	cout << "faculty Tree: " << facultyTree << endl;
	facultyFile.close();
}