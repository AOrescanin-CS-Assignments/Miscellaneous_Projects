//****************************************************************************************************
//
//		File:					student.h
//		
//		Name:					Alex Orescanin
//
//		This program will contain the definition of the struct "Student"
// 
//		other files included: DLList.h, studentList.cpp, node.h, studentFile.txt
//		 	
//****************************************************************************************************

#ifndef STUDENT_H
#define STUDENT_H

//****************************************************************************************************

struct Student
{
	int id;
	char name[50];
	char citystate[50];
	char phone[12];
	char gender;
	int year;
	int credits;
	float gpa;
	char major[6];

	Student();
	friend ostream& operator << (ostream& out, const Student& data);

	bool operator == (const Student& rhs)const;
	bool operator == (int value)const;
	bool operator != (const Student& rhs)const;
	bool operator != (int value)const;
	bool operator < (const Student& rhs)const;
	bool operator < (int value)const;
	bool operator <= (const Student& rhs)const;
	bool operator <= (int value)const;
	bool operator > (const Student& rhs)const;
	bool operator > (int value)const;
	bool operator >= (const Student& rhs)const;
	bool operator >= (int value)const;
	int operator % (int value)const;
	Student& operator = (int value);
};

//****************************************************************************************************

Student::Student()
{
	id = 0;
}

//****************************************************************************************************

ostream& operator << (ostream& out, const Student& data)
{
	out << left << setw(10) << data.id << left << setw(30) << data.name
		<< left << setw(8) << data.major << setprecision(2) << fixed << data.gpa << endl;

	return out;
}


//****************************************************************************************************

bool Student::operator == (const Student& rhs)const
{
	return (this->id == rhs.id);
}

//****************************************************************************************************

bool Student::operator == (int value)const
{
	return (this->id == value);
}

//****************************************************************************************************

bool Student::operator != (const Student& rhs)const
{
	return (this->id != rhs.id);
}

//****************************************************************************************************

bool Student::operator != (int value)const
{
	return (this->id != value);
}

//****************************************************************************************************

bool Student::operator < (const Student& rhs)const
{
	return (this->id < rhs.id);
}

//****************************************************************************************************

bool Student::operator < (int value)const
{
	return (this->id < value);
}

//****************************************************************************************************

bool Student::operator <= (const Student& rhs)const
{
	return (this->id <= rhs.id);
}

//****************************************************************************************************

bool Student::operator <= (int value)const
{
	return (this->id <= value);
}

//****************************************************************************************************

bool Student::operator > (const Student& rhs)const
{
	return (this->id > rhs.id);
}

//****************************************************************************************************

bool Student::operator > (int value)const
{
	return (this->id > value);
}

//****************************************************************************************************

bool Student::operator >= (const Student& rhs)const
{
	return (this->id >= rhs.id);
}

//****************************************************************************************************

bool Student::operator >= (int value)const
{
	return (this->id >= value);
}

//****************************************************************************************************

int Student::operator % (int value)const
{
	return (this->id % value);
}

//****************************************************************************************************

Student& Student::operator = (int value)
{
	this->id = value;
	return *this;
}

//****************************************************************************************************

#endif !STUDENT_H