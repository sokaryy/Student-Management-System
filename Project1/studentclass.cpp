#include "studentclass.h"






Student::Student() :
	id(0), age(0), first_name(""), last_name(""), gpa(0.0), department(""), graduation_date("")
{
}

Student::Student(int c_id, int c_age, const string& c_first_name, const string& c_last_name,
	float c_gpa, const string& c_department, const string& c_graduation_date) :
	id(c_id), age(c_age), first_name(c_first_name), last_name(c_last_name), gpa(c_gpa), department(c_department), graduation_date(c_graduation_date)
{
}

int Student::getId() const
{
	return id;
}

int Student::getAge() const
{
	return age;
}

const string& Student::getFirstName() const
{
	return first_name;
}

const string& Student::getLastName() const
{
	return last_name;
}

float Student::getGpa() const
{
	return gpa;
}

const string& Student::getDepartment() const
{
	return department;
}

const string& Student::getGraduationDate() const
{
	return graduation_date;
}

void Student::setId(int c_id)
{
	id = c_id;
}

void Student::setAge(int c_age)
{
	age = c_age;
}

void Student::setFirstName(const string& c_first_name)
{
	first_name = c_first_name;
}

void Student::setLastName(const string& c_last_name)
{
	last_name = c_last_name;
}

void Student::setGpa(float c_gpa)
{
	gpa = c_gpa;
}

void Student::setDepartment(const string& c_department)
{
	department = c_department;
}

void Student::setGraduationDate(const string& c_graduation_date)
{
	graduation_date = c_graduation_date;
}

void Student::printStudentInfo()
{
	cout << "********************************************" << endl;
	cout << "Student ID: " << getId() << endl;
	cout << "Student Age: " << getAge() << endl;
	cout << "Student Name: " << getFirstName() << " " << getLastName() << endl;
	cout << "Student Gpa: " << getGpa() << endl;
	cout << "Student Department Name: " << getDepartment() << endl;
	cout << "Student Graduation Date: " << getGraduationDate() << endl;
	cout << "********************************************" << endl;
}

void Student::printStudentInfoTabular()
{
	
	const int ID_WIDTH = 6;
	const int AGE_WIDTH = 5;
	const int FIRST_NAME_WIDTH = 13;
	const int LAST_NAME_WIDTH = 12;
	const int GPA_WIDTH = 5;
	const int DEPT_WIDTH = 25;
	const int DATE_WIDTH = 15;

	
	cout << left << setw(ID_WIDTH) << getId()
		<< left << setw(AGE_WIDTH) << getAge()
		<< left << setw(FIRST_NAME_WIDTH) << getFirstName()
		<< left << setw(LAST_NAME_WIDTH) << getLastName();

	// GPA 
	cout << left << setw(GPA_WIDTH) << fixed << setprecision(2) << getGpa()
		<< left << setw(DEPT_WIDTH) << getDepartment()
		<< left << setw(DATE_WIDTH) << getGraduationDate()
		<< endl;

	cout << resetiosflags(ios::fixed | ios::showpoint | ios::left);
}

void Student::printHeader()
{
	const int ID_WIDTH = 6;
	const int AGE_WIDTH = 5;
	const int FIRST_NAME_WIDTH = 13;
	const int LAST_NAME_WIDTH = 12;
	const int GPA_WIDTH = 5;
	const int DEPT_WIDTH = 25;
	const int DATE_WIDTH = 15;

	
	const int TOTAL_WIDTH = ID_WIDTH + AGE_WIDTH + FIRST_NAME_WIDTH + LAST_NAME_WIDTH + GPA_WIDTH + DEPT_WIDTH + DATE_WIDTH + 5;

	
	cout << string(TOTAL_WIDTH, '=') << endl;
	cout << left << setw(ID_WIDTH) << "ID"
		<< left << setw(AGE_WIDTH) << "AGE"
		// New separate headers
		<< left << setw(FIRST_NAME_WIDTH) << "FIRST NAME"
		<< left << setw(LAST_NAME_WIDTH) << "LAST NAME"
		<< left << setw(GPA_WIDTH) << "GPA"
		<< left << setw(DEPT_WIDTH) << "DEPARTMENT"
		<< left << setw(DATE_WIDTH) << "GRAD DATE"
		<< endl;
	cout << string(TOTAL_WIDTH, '=') << endl;
}

