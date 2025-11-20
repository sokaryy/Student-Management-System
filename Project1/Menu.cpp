#include "Menu.h"

void MenuSystem::handleAddStudent()
{
	int id, age;
	string first_name, last_name, department, graduation_date;
	float gpa;
	cout << "\n================================================ Adding new Student ================================================"<<endl;
	cout << "Enter Student ID: ";
	cin >> id;
	cout << "Enter First Name: ";

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	getline(cin, first_name);
	cout << "Enter Last Name: ";
	getline(cin, last_name);
	cout << "Enter Age: ";
	cin >> age;
	cout << "Enter GPA: ";

	do
	{
		cin >> gpa;
		if (gpa >= 0.0 && gpa <= 4.0)
		{
			break;
		}
		else
		{
			cout << "Please Enter GPA value between 0.0 and 4.0: ";
		}
	} while (true);
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Enter Department: ";
	getline(cin, department);

	cout << "Enter Graduation Date in (YYYY-MM-DD) Format: ";
	getline(cin, graduation_date);

	Student s(id, age, first_name, last_name, gpa,department,graduation_date);

	if (dbm.insertRecord(s))
	{
		cout << "Student Added Succesfully";
	}
	else
	{
		cout << "Couldn't Add student";
	}
}

void MenuSystem::handleViewStudent()
{
	dbm.viewAllStudents();
}

void MenuSystem::handleSearchStudent()
{
	cout << "\n=============================================== Searching for a Student ================================================" << endl;
	int id;
	cout << "Enter Studnet ID: ";
	cin >> id;
	dbm.searchByID(id);
}

void MenuSystem::handleUpdateStudent()
{
	bool flag = true;
	int id;
	int choice;
	string attribute;
	string value;
	while (flag)
	{
		flag = false;
		cout << "\n================================================ Updating Student ================================================"<< endl;
		cout << "Enter Student ID to update: ";
		cin >> id;
		if (!dbm.isAvailable(id))
		{
			cout << "Invalid ID Entered ";
			flag = true;
			continue;
		}
		cout << "Which attribute would you like to update?" << endl;
		cout << "1. First Name" << endl;
		cout << "2. Last Name" << endl;
		cout << "3. Age" << endl;
		cout << "4. GPA" << endl;
		cout << "5. Department" << endl;
		cout << "6. Graduation Date" << endl;
		cout << "Choice: ";

		bool loopchoice = true;
		while (loopchoice)
		{
			cin >> choice;
			loopchoice = false;
			switch (choice)
			{
			case 1: attribute = "first_name"; break;
			case 2: attribute = "last_name"; break;
			case 3: attribute = "age"; break;
			case 4: attribute = "gpa"; break;
			case 5: attribute = "department"; break;
			case 6: attribute = "graduation_date"; break;
			default:
				cout << "Invalid Choice Enter choice again: ";
				loopchoice = true;
				break;
			}
		}
		
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter Value for attribute " << attribute<< ": ";
		getline(cin, value);
		if (dbm.updateStudent(id, attribute, value))
		{
			cout << "Attribute " << attribute << " for student " << id << " updated Succesfully.";
		}
		else
		{
			cout << "Couldn't Update attribute!";
		}
	}
}

void MenuSystem::handleDeleteStudent()
{
	cout << "\n================================================ Deleting Student =================================================" << endl;
	int id;
	cout << "Enter Student ID to be Deleted: ";
	cin >> id;
	dbm.deleteRecord(id);
}

void MenuSystem::handleExport()
{	
	int choice=0;
	int count=-1;
	do {
		cout << "Choose one of the following options: " << endl;
		cout << " 1. All students " << endl;
		cout << " 2. Top students " << endl;
		cin >> choice;
		if (choice == 1 || choice == 2)
		{
			break;
		}
	} while (true);
	if (choice == 2)
	{	
		cout << "Enter Number of top students required: ";
		cin >> count;
	}
	string filename;
	cout << "Enter CSV File name ";
	cin >> filename;
	dbm.exportToCSV(filename,count);
}

void MenuSystem::displayMenu()
{
	cout << "\n============================================== STUDENT MANAGEMENT SYSTEM ===============================================" << endl;
	cout << "1. Add New Student" << endl;
	cout << "2. View All Students" << endl;
	cout << "3. Search by ID" << endl;
	cout << "4. Update Student" << endl;
	cout << "5. Delete Student" << endl;
	cout << "6. Export to CSV" << endl;
	cout << "7. Exit" << endl;
	cout << "Enter choice : ";
}

MenuSystem::MenuSystem()
{
}

void MenuSystem::run(void)
{
	bool flag = true;
	char ch ;
	while (flag)
	{
		displayMenu();
		cin >>ch;
		switch (ch)
		{
		case '1':
			handleAddStudent();
			break;
		case '2':
			handleViewStudent();
			break;
		case '3':
			handleSearchStudent();
			break;
		case '4':
			handleUpdateStudent();
			break;
		case '5':
			handleDeleteStudent();
			break;
		case '6':
			handleExport();
			break;
		case '7':
			flag = false;
			break;
		default:
			cout << "Invalid Input Try again : "<<endl;
			break;
		}
	}
}

