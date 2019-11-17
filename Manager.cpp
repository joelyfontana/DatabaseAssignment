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