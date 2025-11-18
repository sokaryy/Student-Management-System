#include "studentclass.h"
#include "DatabaseManagerClass.h"
int main()
{
	Student s1(7366, 22, "Zeyad", "Elsokary", 3.82, "Mechatronics", "2025-7-15");
	//s1.printStudentInfo();
	Student s2(7576, 23, "youssef", "walid", 3.98, "Compu", "2025-7-16");
	//s2.printStudentInfo();
	Student s3(7657, 24, "Ahmed", "Hossam", 3.5, "BioMedical", "2025-6-8");
	//s3.printStudentInfo();*/
	DataBaseManager dbm;
	//dbm.insertRecord(s2);
	//dbm.insertRecord(s3);
	dbm.viewAllStudents();
}