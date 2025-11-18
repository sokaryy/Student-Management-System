#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Student {
private:
	int id;
	int age;
	string first_name;
	string last_name;
	float gpa;
	string department;
	string graduation_date;
public:
	//Constructors

	Student();
	Student(int c_id, int c_age, const string& c_first_name, const string& c_last_name,
		float c_gpa, const string& c_department, const string& c_graduation_date);

	//Getters

	int getId() const ;
	int getAge() const;
	const string& getFirstName() const;
	const string& getLastName() const;
	float getGpa() const;
	const string& getDepartment() const;
	const string& getGraduationDate() const;

	//Setters

	void setId(int c_id);
	void setAge(int c_age);
	void setFirstName(const string& c_first_name);
	void setLastName(const string& c_last_name);
	void setGpa(float c_gpa);
	void setDepartment(const string& c_department);
	void setGraduationDate(const string& c_graduation_date);
	
	//helpers

	void printStudentInfo();
	void printStudentInfoTabular();
	void printHeader();
};