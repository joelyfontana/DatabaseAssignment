/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Assignment 5 - Building a Database with BST*/

#include "FileReader.h"
using namespace std;


const string FileReader::studentFileName = "studentTable.txt";
const string FileReader::facultyFileName = "facultyTable.txt";

FileReader::FileReader()
{}
FileReader::~FileReader()
{}

//open the files that contains the tree, reads the file, and makes an object
BST<int, Student*>* FileReader::readStudentFile()
{
	//check to make sure the file exists
	int line = 0;
	ifstream studentFile;
	studentFile.open(studentFileName);
	if (studentFile.is_open())
	{
		//if the file is open read the student tree
		BST<int, Student*>* studentTree = new BST<int, Student*>();
		//put the information from the student file in the tree
		//use the override operator


		return studentTree;
	}
	//if the file does not exist
	else
	{
		//initialize master student as a new empty tree
		return new BST<int, Student*>();
	}
}

//check to see if the files are in the directory
BST<int, Faculty*>* FileReader::readFacultyFile()
{
	//check to make sure the file exists
	ifstream facultyFile;
	facultyFile.open(facultyFileName);
	if (facultyFile.is_open())
	{
		//if the file does exist read the faculty tree
		BST<int, Faculty*>* facultyTree = new BST<int, Faculty*>();



		return facultyTree;
	}
	//if the file does not exist
	else
	{
		//initialize master faculty as a new empty tree
		return new BST<int, Faculty*>();
	}
}


//write the tree first, and then read it
// assume we already have the tree
void FileReader::writeToStudentFile(BST <int, Student*>* studentTree)
{	
	//write and serialize the student tree
	//use the printing function in the tree to write to it instead
	studentTree->serialization(studentFileName);
}

//write to the faculty tree
void FileReader::writeToFacultyFile(BST <int, Faculty*>* facultyTree)
{
	//write and serialize the faculty tree
	//use the printing function in the tree to write to it instead
	facultyTree->serialization(facultyFileName);
}