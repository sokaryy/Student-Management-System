// #include <iostream>
// #include <string>

// // Include the necessary MySQL Connector/C++ headers
// #include <cppconn/driver.h>
// #include <cppconn/exception.h>
// #include <cppconn/connection.h>

// using namespace std;

// // --- CONNECTION DETAILS ---
// // Replace these with your actual server details
// const string SERVER = "tcp://127.0.0.1:3306";
// const string USERNAME = "root";
// // WARNING: Never hardcode sensitive passwords in production code!
// const string PASSWORD = "1234";

// int main()
// {
//    sql::Driver* driver = nullptr;
//    sql::Connection* con = nullptr;

//    try
//    {
//        // 1. Get the SQL driver instance
//        driver = get_driver_instance();
//        cout << "Driver instance retrieved." << endl;

//        // 2. Attempt to connect to the MySQL server
//        con = driver->connect(SERVER, USERNAME, PASSWORD);
//        cout << "-----------------------------------" << endl;
//        cout << "SUCCESS! Connected to MySQL server." << endl;
//        cout << "-----------------------------------" << endl;

//        // Optional: Check connection status and close
//        if (con->isValid()) {
//            cout << "Connection is valid." << endl;
//        }
//        else {
//            cout << "Connection is not valid." << endl;
//        }

//    }
//    catch (sql::SQLException& e)
//    {
//        // 3. Handle connection errors
//        cout << "------------------------------------------------------------------" << endl;
//        cout << "ERROR: Failed to connect to MySQL." << endl;
//        cout << "  (Connection/authentication failure or server not running.)" << endl;
//        cout << "------------------------------------------------------------------" << endl;

//        // Print detailed error information
//        cout << "MySQL Error Message: " << e.what() << endl;
//        cout << "MySQL Error Code: " << e.getErrorCode() << endl;
//        cout << "SQL State: " << e.getSQLState() << endl;
//    }

//    // 4. Clean up connection object
//    if (con != nullptr) {
//        delete con;
//        cout << "Connection closed and memory released." << endl;
//    }

//    // This will pause the console window so you can read the output
//    cout << "Press Enter to exit..." << endl;
//    cin.get();

//    return 0;
// }