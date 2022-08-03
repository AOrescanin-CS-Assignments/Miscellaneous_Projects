//****************************************************************************************************
//
//		File:					studentList.cpp
//		
//		Name:					Alex Orescanin
//
//		This program will contain the main function and prove the correctness of BST.h
// 
//		other files included: BST.h, student.h, node.h, studentFile.txt
//	
//****************************************************************************************************

#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <new>
#include <cmath>

using namespace std;

#include "student.h"
#include "BST.h"

//****************************************************************************************************

void buildList(BST<Student>& studentList);
void process(BST<Student>& studentList);
char getChoice();
void addStudent(BST<Student>& studentList);
void findStudent(BST<Student>& studentList);
void updateStudent(BST<Student>& studentList);
void removeStudent(BST<Student>& studentList);
void displayAllStudents(BST<Student>& studentList);
void display1Student(const Student& myStudent);
void listInformation(BST<Student>& studentList);

//****************************************************************************************************

int main()
{
	BST<Student> studentList;

	buildList(studentList);
	process(studentList);

	return 0;
}

//****************************************************************************************************

void buildList(BST<Student>& studentList)
{
	Student student;
	ifstream studentData;

	studentData.open("studentFile.txt");

	while (studentData >> student.id)
	{
		studentData.ignore();
		studentData.getline(student.name, 50);
		studentData.getline(student.citystate, 50);
		studentData >> student.phone
			>> student.gender
			>> student.year
			>> student.credits
			>> student.gpa
			>> student.major;

		studentList.insert(student);
	}

	studentData.close();
}

//****************************************************************************************************

void process(BST<Student>& studentList)
{
	char choice;

	do
	{
		choice = getChoice();

		switch (choice)
		{
		case 'A':	addStudent(studentList);
			break;
		case 'S':	findStudent(studentList);
			break;
		case 'U':	updateStudent(studentList);
			break;
		case 'D':	removeStudent(studentList);
			break;
		case 'P':	displayAllStudents(studentList);
			break;
		case 'X':	listInformation(studentList);
			break;
		case 'Q':	break;
		}
	} while (choice != 'Q');
}

//****************************************************************************************************

char getChoice()
{
	char choice;
	bool valid;

	cout << "========MENU========\n"
		<< " A:   Add a new Student \n"
		<< " S:   Search a Student Record \n"
		<< " U:   Update a Student \n"
		<< " D:   Delete a Student \n"
		<< " P:   Print Students \n"
		<< " X:   List information \n"
		<< " Q: Quit      \n\n"
		<< "Enter your choice: ";

	do
	{
		cin >> choice;
		choice = toupper(choice);

		switch (choice)
		{
		case 'A':
		case 'S':
		case 'U':
		case 'D':
		case 'P':
		case 'X':
		case 'Q':	valid = true;
			break;
		default:	valid = false;
			cout << "\aInvalid choice\n"
				<< "Please try again: ";
			break;
		}
	} while (!valid);

	return choice;
}

//****************************************************************************************************

void addStudent(BST<Student>& studentList)
{
	Student s1;
	
	cout << "Enter Student ID: ";
	cin >> s1.id;
	while (isdigit(s1.id) == false)
	{
		cout << "\aInvalid choice\n"
			 << "Please try again: ";
		cout << "Enter Student ID: ";
		cin >> s1.id;
		break;
	}
	cin.ignore();
	cout << endl << "Enter Student name: ";
	cin.getline(s1.name, 50);
	cout << endl << "Enter " << s1.name << "'s city and state: ";
	cin.getline(s1.citystate, 50);
	cout << endl << "Enter " << s1.name << "'s phone number: ";
	cin >> s1.phone;
	cout << endl << "Enter " << s1.name << "'s gender(M or F): ";
	cin >> s1.gender;
	cout << endl << "Enter " << s1.name << "'s year: ";
	cin >> s1.year;
	cout << endl << "Enter " << s1.name << "'s credit hours: ";
	cin >> s1.credits;
	cout << endl << "Enter " << s1.name << "'s GPA: ";
	cin >> s1.gpa;
	cout << endl << "Enter " << s1.name << "'s major: ";
	cin >> s1.major;

	if (studentList.insert(s1))
	{
		cout << s1.name << " has been added to the list" << endl << endl;
	}
	else
	{
		cout << "List is full, cannot add anymore students" << endl << endl;
	}
}

//****************************************************************************************************

void findStudent(BST<Student>& studentList)
{
	Student s1;

	cout << "Please enter the ID of the student you would look to find: ";
	cin >> s1.id;

	if (studentList.retrieve(s1))
	{
		cout << "The student " << s1.name << " was found" << endl << endl;
	}
	else
	{
		cout << "Invalid ID" << endl << endl;
	}
}

//****************************************************************************************************

void updateStudent(BST<Student>& studentList)
{
	Student s1;

	cout << "Enter Student ID of the student you want to update: ";
	cin >> s1.id;
	cin.ignore();
	cout << endl << "Enter Student name: ";
	cin.getline(s1.name, 50);
	cout << endl << "Enter " << s1.name << "'s city and state: ";
	cin.getline(s1.citystate, 50);
	cout << endl << "Enter " << s1.name << "'s phone number: ";
	cin >> s1.phone;
	cout << endl << "Enter " << s1.name << "'s gender(M or F): ";
	cin >> s1.gender;
	cout << endl << "Enter " << s1.name << "'s year: ";
	cin >> s1.year;
	cout << endl << "Enter " << s1.name << "'s credit hours: ";
	cin >> s1.credits;
	cout << endl << "Enter " << s1.name << "'s GPA: ";
	cin >> s1.gpa;
	cout << endl << "Enter " << s1.name << "'s major: ";
	cin >> s1.major;

	if (studentList.update(s1))
	{
		cout << s1.name << " has updated" << endl << endl;
	}
	else
	{
		cout << "Invalid ID" << endl << endl;
	}
}

//****************************************************************************************************

void removeStudent(BST<Student>& studentList)
{
	Student s1;

	cout << "Please enter the ID of the student you would look to remove: ";
	cin >> s1.id;

	if (studentList.remove(s1))
	{
		cout << "The student you removed was " << s1.name << endl << endl;
	}
	else
	{
		cout << "Invalid ID" << endl << endl;
	}
}

//****************************************************************************************************

void displayAllStudents(BST<Student>& studentList)
{
	cout << left << setw(9) << "ID" << left << setw(27) << "NAME"
		<< left << setw(9) << "GPA" << "MAJOR" << endl;

	studentList.inOrderTraverse(display1Student);
}

//****************************************************************************************************

void display1Student(const Student& myStudent)
{
	cout << myStudent;
}

//****************************************************************************************************

void listInformation(BST<Student>& studentList)
{
	cout << "# of students: " << studentList.getCount() << endl
		<< "height of tree: " << studentList.getHt() << endl;

	if (!studentList.isEmpty())
	{
		cout << "The student list is not empty" << endl;
	}
	else
	{
		cout << "The Student list is empty" << endl;
	}

	if (!studentList.isFull())
	{
		cout << "The student List is not full" << endl;
	}
	else
	{
		cout << "The student list is full" << endl;
	}

	if (studentList.isComplete())
	{
		cout << "The student list is complete" << endl;
	}
	else
	{
		cout << "The student list is not complete" << endl;
	}

	if (studentList.isBalanced())
	{
		cout << "The student list is balanced" << endl;
	}
	else
	{
		cout << "The student list is not balanced" << endl;
	}

}

/*

Sample Output:
========MENU========
 A:   Add a new Student
 S:   Search a Student Record
 U:   Update a Student
 D:   Delete a Student
 P:   Print Students
 X:       List information
 Q: Quit

Enter your choice: x
# of students: 61
height of tree: 12
The student list is not empty
The student List is not full
The student list is not complete
The student list is not balanced
========MENU========
 A:   Add a new Student
 S:   Search a Student Record
 U:   Update a Student
 D:   Delete a Student
 P:   Print Students
 X:       List information
 Q: Quit

Enter your choice:

*/