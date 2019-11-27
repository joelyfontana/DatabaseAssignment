/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Assignment 5 - Building a Database with BST*/

#include "FileReader.h"
#include <string>
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
	cout << "in read student file " << endl;
	//check to make sure the file exists
	int line = 0;
	ifstream studentFile;
	studentFile.open(studentFileName);
	if (studentFile.is_open())
	{
		cout << "in student file is open if statement" << endl;
		//if the file is open read the student tree
		BST<int, Student*>* studentTree = new BST<int, Student*>();
		//put the information from the student file in the tree
		//eof = end of file so while you are not at the end of the file
		while (studentFile.eof() == false)
		{
			cout << "inwhile loop" << endl;
			int index = 0;
			string line;
			//check to make sure that there is not any blank lines
			getline(studentFile, line);
			while(line == "")
			{
				//move to the next line
				getline(studentFile, line);
				if (studentFile.eof() == true)
				{
					cout << "Reached the end of the file" << endl;
					return studentTree;
				}
			}
			//get the student's ID
			//getline(studentFile, line);
			//get the index of the : in the string
			index = line.find_first_of(':');
			string IDstr = line.substr(index + 2);
			//make the string an integer
			int ID = stoi(IDstr);
			cout << "ID: " << ID << endl;
			//get the students name
			getline(studentFile, line);
			//get the index of the : in the string
			index = line.find_first_of(':');
			string nameStr = line.substr(index + 2);
			cout << "nameStr: " << nameStr << endl;
			//get the students grade
			getline(studentFile, line);
			//get the index of the : in the string
			index = line.find_first_of(':');
			string gradeStr = line.substr(index + 2);
			cout << "gradeStr: " << gradeStr << endl;
			//get the students grade
			getline(studentFile, line);
			//get the index of the : in the string
			index = line.find_first_of(':');
			string majorStr = line.substr(index + 2);
			cout << "majorStr: " << majorStr << endl;
			//get the student's GPA
			getline(studentFile, line);
			//get the index of the : in the string
			index = line.find_first_of(':');
			string GPAstr = line.substr(index + 2);
			//make the string an integer
			double GPA = stod(GPAstr);
			cout << "GPAStr: " << GPAstr << endl;
			//get the student's advisor ID
			getline(studentFile, line);
			//get the index of the : in the string
			index = line.find_first_of(':');
			string adStr = line.substr(index + 2);
			//make the string an integer
			int adID = stoi(adStr);
			cout << "adID: " << adID << endl;
			//skip the blank line
			getline(studentFile, line);

			//insert the student into the tree
			Student* student = new Student(ID, nameStr, gradeStr, majorStr, GPA, adID);
			studentTree->insert(ID, student);
		}
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

		//put the information from the student file in the tree
		//eof = end of file so while you are not at the end of the file
		while (facultyFile.eof() == false)
		{
			int index = 0;
			string line;
			//check to make sure that there is not any blank lines
			getline(facultyFile, line);
			while (line == "")
			{
				//move to the next line
				getline(facultyFile, line);
				if (facultyFile.eof() == true)
				{
					cout << "Reached the end of the file" << endl;
					return facultyTree;
				}
			}
			//get the faculty's ID
			//get the index of the : in the string
			index = line.find_first_of(':');
			string IDstr = line.substr(index + 2);
			//make the string an integer
			int ID = stoi(IDstr);
			cout << "ID: " << ID << endl;
			//get the facultys name
			getline(facultyFile, line);
			//get the index of the : in the string
			index = line.find_first_of(':');
			string nameStr = line.substr(index + 2);
			cout << "nameStr: " << nameStr << endl;
			//get the facultys job
			getline(facultyFile, line);
			//get the index of the : in the string
			index = line.find_first_of(':');
			string jobStr = line.substr(index + 2);
			cout << "jobStr: " << jobStr << endl;
			//get the facultys department
			getline(facultyFile, line);
			//get the index of the : in the string
			index = line.find_first_of(':');
			string departmentStr = line.substr(index + 2);
			cout << "departmentStr: " << departmentStr << endl;
			
			//insert the faculty into the tree
			Faculty* faculty = new Faculty(ID, nameStr, jobStr, departmentStr);
			//add the student ID into the list

			//get the student's ID's
			getline(facultyFile, line);
			
			while (!line.empty())
			{
				int studentID = stoi(line);
				faculty->addStudent(studentID);
				getline(facultyFile, line);
			}

			//skip the blank line
			getline(facultyFile, line);

			facultyTree->insert(ID, faculty);
		}
		 



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