/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Assignment 5 - Building a Database with BST*/

#include <iostream>
#include <string>
#include "FileReader.h"
#include "Student.h"
#include "Faculty.h"
using namespace std;
int main(int argc, char** argv)
{
	int choice;
	cout << "1. Print all students and their information (sorted by ascending id #)"<< endl;
	cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
	cout << "3. Find and display student information given the students id " << endl;
	cout << "4. Find and display faculty information given the faculty id" << endl;
	cout << "5. Given a studentís id, print the name and info of their faculty advisor" << endl;
	cout << "6. Given a faculty id, print ALL the names and info of his/her advisees." << endl;
	cout << "7. Add a new student 8. Delete a student given the id" << endl;
	cout << "8. Delete a student given the id " << endl;
	cout << "9. Add a new faculty member" << endl;
	cout << "10. Delete a faculty member given the id." << endl;
	cout << "11. Change a studentís advisor given the student id and the new faculty id." << endl;
	cout << "12. Remove an advisee from a faculty member given the ids" << endl;
	cout << "13. Rollback" << endl;
	cout << "14. Exit */" << endl;
	//cin >> choice;
	
	

	//make a new search tree as a pointer - getting rid of/ just for testing
	BST<int, Student*>* studentTree = new BST<int, Student*>();
	BST<int, Faculty*>* facultyTree = new BST<int, Faculty*>();

	//make the student
	Student* student = new Student(2313535, "joely", "sophomore", "history", 4.0, 5592081);
	//insert the student into the tree
	studentTree->insert(2313535, student);
	
	
	//make the faculty
	Faculty* faculty = new Faculty(11111, "kathy", "administrator", "comp sci");
	//insert the faculty into a tree
	facultyTree->insert(11111, faculty);
	
	//FileReader::readStudentFile();
	FileReader::writeToStudentFile(studentTree);
	FileReader::writeToFacultyFile(facultyTree);


	//choices
	/*if (choice == 1)
	{
		studentTree
	}*/
	
}