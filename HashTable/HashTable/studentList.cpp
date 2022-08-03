//****************************************************************************************************
//
//		File:					studentList.cpp
//		
//		Name:					Alex Orescanin
//
//		This program will contain the main function and prove HashTable.h to be correct
// 
//		other files included: HashTable.h, student.h, node.h, studentFile.txt
//		 	
//****************************************************************************************************

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

#include "student.h"
#include "HashTable.h"

//****************************************************************************************************

void buildList(HashTable<Student>& studentList);
void process(HashTable<Student>& studentList);
char getChoice();
void displayStudents(HashTable<Student>& studentList);
void printStudents(HashTable<Student>& studentList);
void addStudent(HashTable<Student>& studentList);
void findStudent(HashTable<Student>& studentList);
void removeStudent(HashTable<Student>& studentList);
void displayStatistics(HashTable<Student>& studentList);

//****************************************************************************************************

int main()
{
	HashTable<Student> studentList(61);

	buildList(studentList);
	process(studentList);

	return 0;
}

//****************************************************************************************************

void buildList(HashTable<Student>& studentList)
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

void process(HashTable<Student>& studentList)
{
	char choice;

	do
	{
		choice = getChoice();

		switch (choice)
		{
		case 'A':	addStudent(studentList);
			break;
		case 'F':	findStudent(studentList);
			break;
		case 'R':	removeStudent(studentList);
			break;
		case 'S':	displayStatistics(studentList);
			break;
		case 'D':	displayStudents(studentList);
			break;
		case 'P':	printStudents(studentList);
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
		<< " F:   Find a Student Record \n"
		<< " R:   Remove a Student \n"
		<< " S:   Display Statistics \n"
		<< " D:   Display Students \n"
		<< " P:   Print Students \n"
		<< " Q: Quit      \n\n"
		<< "Enter your choice: ";

	do
	{
		cin >> choice;
		choice = toupper(choice);

		switch (choice)
		{
		case 'A':
		case 'F':
		case 'R':
		case 'S':
		case 'D':
		case 'P':
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

void displayStudents(HashTable<Student>& studentList)
{
	studentList.displayTable();
}

//****************************************************************************************************

void printStudents(HashTable<Student>& studentList)
{
	studentList.writeFile();
}

//****************************************************************************************************

void addStudent(HashTable<Student>& studentList)
{
	Student s1;

	cout << "Enter Student ID: ";
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

void findStudent(HashTable<Student>& studentList)
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

void removeStudent(HashTable<Student>& studentList)
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

void displayStatistics(HashTable<Student>& studentList)
{
	studentList.statistics();

	if (studentList.isEmpty())
	{
		cout << endl << "The Hash Table is empty" << endl;
	}
	else
	{
		cout << endl << "The Hash Table is not empty" << endl;
	}
}

//****************************************************************************************************

/*

Sample Output:
========MENU========
 A:   Add a new Student
 F:   Find a Student Record
 R:   Remove a Student
 S:   Display Statistics
 D:   Display Students
 P:   Print Students
 Q: Quit

Enter your choice: s
Table size:                  67

Number of elements:          61

Empty positions:             28

Number of chains:            17

Max chain length:            4

Number of collisions:        22

Average chain length:        1.3

Percentage collisions:       36.1 %

Load factor:                 58.2 %

Average # search steps:      1.508


The Hash Table is not empty
========MENU========
 A:   Add a new Student
 F:   Find a Student Record
 R:   Remove a Student
 S:   Display Statistics
 D:   Display Students
 P:   Print Students
 Q: Quit

Enter your choice: q

*/