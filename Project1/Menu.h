#pragma once
#include "DatabaseManagerClass.h"
#include "studentclass.h"

class MenuSystem
{
private:
	DataBaseManager dbm;
	void handleAddStudent();
	void handleViewStudent();
	void handleSearchStudent();
	void handleUpdateStudent();
	void handleDeleteStudent();
	void handleExport();
	void displayMenu();
public:
	MenuSystem();
	void run(void);
};