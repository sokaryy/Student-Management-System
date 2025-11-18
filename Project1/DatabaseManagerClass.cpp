#include "DatabaseManagerClass.h"

DataBaseManager::DataBaseManager():driver(nullptr),con(nullptr)
{
    try
    {
        driver = get_driver_instance();
        con = driver->connect(SERVER, USER, PASSWORD);
        isValidConnection();
        con->setSchema(DBNAME);
    }
    catch (sql::SQLException& e)
    {
        cerr << "SQL Error: " << e.what() << endl;
        cerr << " (MySQL error code: " << e.getErrorCode();
        cerr << ", SQL State: " << e.getSQLState() << " )" << endl;
    }
}

void DataBaseManager::isValidConnection()
{
	if (con->isValid())
	{
		cout << "Connection is Valid!"<<endl;
	}
	else
	{
		cout << "Invalid Connection!"<<endl;
	}
}

bool DataBaseManager::insertRecord(const Student& s)
{
    if (!con)
    {
        cerr << "ERROR : NOT CONNECTED TO DATABASE";
    }
    try {
        std::unique_ptr<sql::PreparedStatement>  pstatement(con->prepareStatement("INSERT INTO students (student_id , first_name , last_name , age ,gpa , department , graduation_date) values (?,?,?,?,?,?,?)"));
        pstatement->setInt(1,s.getId());
        pstatement->setString(2,s.getFirstName());
        pstatement->setString(3, s.getLastName());
        pstatement->setInt(4, s.getAge());
        pstatement->setDouble(5, s.getGpa());
        pstatement->setString(6, s.getDepartment());
        pstatement->setString(7, s.getGraduationDate());
        int Flag = pstatement->executeUpdate();
        return Flag;
    }
    catch (sql::SQLException &err) {
        cerr << "ERROR: Failed to add student: " << err.what() << endl;
        return false;

    }
    
}

bool DataBaseManager::deleteRecord(int id)
{
    if (!con)
    {
        cerr << "ERROR : NOT CONNECTED TO DATABASE";
    }
    try
    {
        std::unique_ptr<sql::PreparedStatement>  pstatement(con->prepareStatement("delete from students where student_id = ?"));
        pstatement->setInt(1, id);
        int Flag = pstatement->executeUpdate();
        if (Flag == 0)
        {
            cout << "No Records deleted"<<endl;
        }
        else
        {
            cout << "Record of student of id " << id << " deleted successfuly" << endl;
        }
        return true;
    }
    catch (sql::SQLException& err) {
        cerr << "ERROR: Failed to Retrieve students: " << err.what() << endl;
        return false;
    }

}

std::unique_ptr<sql::ResultSet> DataBaseManager::selectAllRecords(void)
{
    if (!con)
    {
        cerr << "ERROR : NOT CONNECTED TO DATABASE";
    }
    try {

        unique_ptr < sql::Statement > pstatement(con->createStatement());

        return unique_ptr <sql::ResultSet>(pstatement->executeQuery("SELECT * From students"));
    }
    catch (sql::SQLException& err) {
        cerr << "ERROR: Failed to Retrieve students: "  << err.what() << endl;
        return nullptr;
    }
}

bool DataBaseManager::viewAllStudents(void)
{
    unique_ptr <sql::ResultSet> pRS = selectAllRecords();
    Student s;
    if (!pRS)
    {
        return false;
    }
    s.printHeader();
    while (pRS->next())
    {
        s.setId(pRS->getInt("student_id"));
        s.setAge(pRS->getInt("age"));
        s.setFirstName(pRS->getString("first_name"));
        s.setLastName(pRS->getString("last_name"));
        s.setGpa(pRS->getDouble("gpa"));
        s.setDepartment(pRS->getString("department"));
        s.setGraduationDate(pRS->getString("graduation_date"));
        s.printStudentInfoTabular();
    }
    return true;
}

bool DataBaseManager::searchByID(int id)
{
    if (!con)
    {
        cerr << "ERROR : NOT CONNECTED TO DATABASE";
    }
    try {
        std::unique_ptr<sql::PreparedStatement>  pstatement(con->prepareStatement("select * from students where student_id = ?"));
        pstatement->setInt(1, id);
        unique_ptr<sql::ResultSet> pRS= (unique_ptr <sql::ResultSet>)pstatement->executeQuery();
        if (pRS->next())
        {
            Student S(pRS->getInt("student_id"), pRS->getInt("age"), pRS->getString("first_name"), pRS->getString("last_name"), pRS->getDouble("gpa")
                , pRS->getString("department"), pRS->getString("graduation_date"));
            S.printHeader();
            S.printStudentInfoTabular();
        }
        else
        {
            cerr << "Student with ID " << id << " not found.";
        }
    }
    catch (sql::SQLException& err) {
        cerr << "ERROR: Failed to Retrieve student: " << err.what() << endl;
        return false;
    }
    
}





