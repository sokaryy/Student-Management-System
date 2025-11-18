#pragma once
#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h> 
#include <string>
#include "studentclass.h"
using namespace std;

class DataBaseManager
{
private:
	sql::Driver* driver;
	sql::Connection* con;
	const string SERVER = "tcp://127.0.0.1:3306";
	const string USER = "root";
	const string PASSWORD = "1234";
	const string DBNAME = "STUDENT_MANAGEMENT_SYSTEM";
public:
	DataBaseManager();
	void isValidConnection();
	bool insertRecord(const Student& s);
	bool deleteRecord(int id);
	std::unique_ptr<sql::ResultSet> selectAllRecords(void);
	bool viewAllStudents(void);
	bool searchByID(int id);

};