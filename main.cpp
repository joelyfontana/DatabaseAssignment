/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Assignment 5 - Building a Database with BST*/

#include <iostream>
#include <string>
#include "FileReader.h"
#include "Student.h"
#include "Manager.h"
#include "Faculty.h"
using namespace std;
int main(int argc, char** argv)
{
	Manager* manager = new Manager();

	int choice;
	cout << "\nWelcome to the Records Database." << endl;

	while(choice != 14)
	{
		cout << "\n1. Print all student\'s and their information (sorted by ascending id #)" << endl;
		cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
		cout << "3. Find and display student information given the students id " << endl;
		cout << "4. Find and display faculty information given the faculty id" << endl;
		cout << "5. Given a students id, print the name and info of their faculty advisor" << endl;
		cout << "6. Given a faculty id, print ALL the names and info of his/her advisees." << endl;
		cout << "7. Add a new student " << endl;
		cout << "8. Delete a student given the id " << endl;
		cout << "9. Add a new faculty member" << endl;
		cout << "10. Delete a faculty member given the id." << endl;
		cout << "11. Change a student\'s advisor given the student id and the new faculty id." << endl;
		cout << "12. Remove an advisee from a faculty member given the ids" << endl;
		cout << "13. Rollback" << endl;
		cout << "14. Exit */" << endl;
		cout << "\nPlease enter the number of the option you want to perform: ";
		cin >> choice;

		//choices
		//print student data in order
		if (choice == 1)
		{
			try
			{
				//use the print function to print them in ascending order
				manager->printStudentTree();
			}
			catch (treeEmptyException e)
			{
				cout << e.what() << endl;
			}
		}

		//print faculty data in order
		if (choice == 2)
		{
			manager->printFacultyTree();
		}

		if (choice == 3)
		{
			try
			{
				int wantedID;
				cout << "Please enter the ID of the student's information you wish to print: ";
				cin >> wantedID;
				Student* studentInfo = manager->findStudentWithID(wantedID);
				cout << *studentInfo << endl;
			}
			catch (StudentDNEexception e)
			{
				cout << e.what() << endl;
			}
		}
		
		//find the faculty based on ID
		if (choice == 4)
		{
			try
			{
				int wantedID;
				cout << "Please enter the ID of the faculty's information you wish to print: ";
				cin >> wantedID;
				Faculty* facultyInfo = manager->findFacultyWithID(wantedID);
				cout << *facultyInfo << endl;
			}
			catch (FacultyDNEexception e)
			{
				cout << e.what() << endl;
			}
		}

		//MAKE 5 AND 6 HERE

		if (choice == 7)
		{
			int newID;
			string newName;
			string newGrade;
			string newMajor;
			double newGPA;
			int newAdID;

			cout << "Please enter the following information for the student:" << endl;
			cout << "Student ID: ";
			cin >> newID;
			cout << "Student Name: ";
			cin.ignore();
			getline(cin, newName);
			//cout << "name: " << newName << endl;
			cout << "Student Grade: ";
			cin >> newGrade;
			cout << "Student Major: ";
			cin.ignore();
			getline(cin, newMajor);
			cout << "Student GPA: ";
			cin >> newGPA;
			cout << "Student Advisor ID: ";
			cin >> newAdID;
			Student* newStudent = new Student(newID, newName, newGrade, newMajor, newGPA, newAdID);
			manager->addStudent(newStudent);
		}

		//delete students
		if (choice == 8)
		{
			int deleteID;
			cout << "Enter the ID of the student you wish to delete: ";
			cin >> deleteID;
			manager->deleteStudent(deleteID);
		}

		//add faculty
		if (choice == 9)
		{
			int newID;
			string newName;
			string newJob;
			string newDepartment;

			cout << "Please enter the following information for the faculty:" << endl;
			cout << "Faculty ID: ";
			cin >> newID;
			cout << "Faculty Name: ";
			cin.ignore();
			getline(cin, newName);
			//cout << "name: " << newName << endl;
			cout << "Job: ";
			cin >> newJob;
			cout << "Department: ";
			cin.ignore();
			getline(cin, newDepartment);

			Faculty* newFaculty = new Faculty(newID, newName, newJob, newDepartment);
			manager->addFaculty(newFaculty);
		}

		//delete faculty
		if (choice == 10)
		{
			int deleteID;
			cout << "Enter the ID of the faculty you wish to delete: ";
			cin >> deleteID;
			manager->deleteFaculty(deleteID);
		}
	}	
}

//TESTING FUNCTION - NOTHING SHOULD WORK OUTSIDE OF THIS AND IF IT DOES YOU FUCKED UP JOELY 
void Testing()
{
	//make a new search tree as a pointer - getting rid of/ just for testing
	BST<int, Student*>* studentTree = new BST<int, Student*>();
	BST<int, Faculty*>* facultyTree = new BST<int, Faculty*>();

	//make the student
	Student* student = new Student(2313535, "joely fontana", "sophomore", "history", 3.2, 5592081);
	//insert the student into the tree
	studentTree->insert(2313535, student);

	Student* student2 = new Student(2302555, "stephen white", "freshman", "comp sci", 3.7, 5512341);
	//insert the student into the tree
	studentTree->insert(2302555, student2);


	//make the faculty
	Faculty* faculty = new Faculty(11111, "kathy", "administrator", "comp sci");
	//insert the faculty into a tree
	facultyTree->insert(11111, faculty);

	//FileReader::readStudentFile();
	FileReader::writeToStudentFile(studentTree);
	FileReader::writeToFacultyFile(facultyTree);


}