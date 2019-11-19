/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Assignment 5 - Building a Database with BST*/

#include <iostream>
#include "Manager.h"
using namespace std;

//constructor
Manager::Manager()
{
	masterStudent = FileReader::readStudentFile();
	masterFaculty = FileReader::readFacultyFile();
}
Manager::~Manager()
{

}

void Manager::assignAdvisor(Student student, Faculty faculty)
{
	//Faculty* faculty = new Faculty(11111, "kathy", "administrator", "comp sci", );
	/*if (student.adID == faculty.ID)
	{

	}*/

}

//print the student tree
void Manager::printStudentTree()
{
	masterStudent->printTree();
}

//print the faculty tree
void Manager::printFacultyTree()
{
	masterFaculty->printTree();
}

//find the students based on ID
Student* Manager::findStudentWithID(int ID)
{
	try
	{
		return masterStudent->searchWithKey(ID);
	}
	catch (nodeDNEexception e)
	{
		throw StudentDNEexception("That student does not exist");
	}
}

//find the faculty based on ID
Faculty* Manager::findFacultyWithID(int ID)
{
	try
	{
		return masterFaculty->searchWithKey(ID);
	}
	catch (nodeDNEexception e)
	{
		throw FacultyDNEexception("That faculty ID does not exist");
	}
}

void Manager::addStudent(Student* newStudent)
{
	masterStudent->insert(newStudent->ID, newStudent);
}

void Manager::addFaculty(Faculty* newFaculty)
{
	masterFaculty->insert(newFaculty->ID, newFaculty);
}

void Manager::deleteStudent(int ID)
{
	masterStudent->deleteNode(ID);
}

void Manager::deleteFaculty(int ID)
{
	masterFaculty->deleteNode(ID);
}


