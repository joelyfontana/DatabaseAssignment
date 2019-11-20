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

void Manager::assignAdvisor(int sID, int fID)
{
	Student* student = masterStudent->searchWithKey(sID);

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

Faculty* Manager::findFacultyWithStudentID(int ID)
{
	try
	{
		Student* student = masterStudent->searchWithKey(ID);
		return masterFaculty->searchWithKey(student->adID);
	}
	catch (nodeDNEexception e)
	{
		throw StudentDNEexception("That student does not exist");
	}
}

//Change a student's advisor given the student ID and the new faculty ID
void Manager::changeStudentAdvisor(int sID, int fID)
{
	Student* student;
	Faculty* newFaculty;
	try
	{
		//find student
		student = masterStudent->searchWithKey(sID);
	}
	catch (nodeDNEexception e)
	{
		throw StudentDNEexception("That student does not exist");
	}
	//check to make sure that the student does not already have that advisor
	if (student->adID == fID)
	{
		cout << "Student already has that advisor. No changes were made." << endl;
		return;
	}
	//find the new advisor before removing them from the old
	//find new advisor and insert student
	try
	{
		newFaculty = masterFaculty->searchWithKey(fID);
		newFaculty->addStudent(student->ID);
	}
	catch (nodeDNEexception e)
	{
		throw FacultyDNEexception("That faculty does not exist");
	}
	//change the advisor in the student
	student->adID = fID;
	//find current advisor and remove student
	Faculty* currFaculty = masterFaculty->searchWithKey(student->adID);
	currFaculty->removeStudent(student->ID);
}

//Given a faculty ID, print ALL the namesand info of his / her advisees
void Manager::printFacultyAdvisees(int fID)
{
	Faculty* faculty = masterFaculty->searchWithKey(fID);
	cout<<faculty->studentIDs;
}

//Remove an advisee from a faculty member given the IDs
void Manager::removeAdviseeFromFaculty(int sID, int fID)
{
	Student* removeStudent = masterStudent->searchWithKey(sID);
	Faculty* faculty = masterFaculty->searchWithKey(fID);

	faculty->removeStudent(removeStudent->ID);
	//IS THIS CORRECT??? WHAT DOES THE STUDENT NEED TO KNOW AFTER THEY HAVE BEEN REMOVED FROM THE FACULTY
	removeStudent->adID = 0;
}


