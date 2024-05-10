/*Company maintains employee information as employee ID, name, designation, and
salary. Allow user to add, delete information of employee. Display information of
particular employee. If employee does not exist an appropriate message is displayed.
If it is, then the system displays the employee details. Use index sequential file to
maintain the data.*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Employee
{
    int employeeID;
    string name;
    string designation;
    double salary;
};

// Function to add employee information to the file
void addEmployee(const Employee &emp)
{
    ofstream file("employee_data.txt", ios::app);
    file << emp.employeeID << "," << emp.name << "," << emp.designation << "," << emp.salary << endl;
    file.close();
}

// Function to delete employee information from the file
void deleteEmployee(int employeeID)
{
    ifstream file("employee_data.txt");
    ofstream temp("temp.txt");
    int id;
    string name, designation;
    double salary;
    bool found = false;
    while (file >> id >> name >> designation >> salary)
    {
        if (id == employeeID)
        {
            found = true;
            continue; // Skip writing this employee to the temp file
        }
        temp << id << "," << name << "," << designation << "," << salary << endl;
    }
    file.close();
    temp.close();
    remove("employee_data.txt");
    rename("temp.txt", "employee_data.txt");
    if (!found)
    {
        cout << "Employee with ID " << employeeID << " not found." << endl;
    }
    else
    {
        cout << "Employee with ID " << employeeID << " deleted successfully." << endl;
    }
}

// Function to display employee information
void displayEmployee(int employeeID)
{
    ifstream file("employee_data.txt");
    int id;
    string name, designation;
    double salary;
    bool found = false;
    while (file >> id >> name >> designation >> salary)
    {
        if (id == employeeID)
        {
            found = true;
            cout << "Employee ID: " << id << endl;
            cout << "Name: " << name << endl;
            cout << "Designation: " << designation << endl;
            cout << "Salary: " << salary << endl;
            break; // No need to continue searching
        }
    }
    file.close();
    if (!found)
    {
        cout << "Employee with ID " << employeeID << " not found." << endl;
    }
}

int main()
{
    int choice, employeeID;
    Employee emp;
    do
    {
        cout << "1. Add Employee\n2. Delete Employee\n3. Display Employee\n0. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Employee ID: ";
            cin >> emp.employeeID;
            cout << "Enter Name: ";
            cin.ignore(); // Clear buffer
            getline(cin, emp.name);
            cout << "Enter Designation: ";
            getline(cin, emp.designation);
            cout << "Enter Salary: ";
            cin >> emp.salary;
            addEmployee(emp);
            cout << "Employee added successfully." << endl;
            break;
        case 2:
            cout << "Enter Employee ID to delete: ";
            cin >> employeeID;
            deleteEmployee(employeeID);
            break;
        case 3:
            cout << "Enter Employee ID to display: ";
            cin >> employeeID;
            displayEmployee(employeeID);
            break;
        case 0:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
    return 0;
}

/*
1. Add Employee
2. Delete Employee
3. Display Employee
0. Exit
Enter your choice: 1
Enter Employee ID: 101
Enter Name: John Doe
Enter Designation: Manager
Enter Salary: 50000
Employee added successfully.
1. Add Employee
2. Delete Employee
3. Display Employee
0. Exit
Enter your choice: 1
Enter Employee ID: 102
Enter Name: Jane Smith
Enter Designation: Developer
Enter Salary: 40000
Employee added successfully.
1. Add Employee
2. Delete Employee
3. Display Employee
0. Exit
Enter your choice: 3
Enter Employee ID to display: 101
Employee ID: 101
Name: John Doe
Designation: Manager
Salary: 50000
1. Add Employee
2. Delete Employee
3. Display Employee
0. Exit
Enter your choice: 2
Enter Employee ID to delete: 102
Employee with ID 102 deleted successfully.
1. Add Employee
2. Delete Employee
3. Display Employee
0. Exit
Enter your choice: 3
Enter Employee ID to display: 102
Employee with ID 102 not found.
1. Add Employee
2. Delete Employee
3. Display Employee
0. Exit
Enter your choice: 0
Exiting program.



EXPLANATION - 
This C++ program manages employee information by allowing users to add, delete, and display employee records. Let's go through its functionality:

1. **Employee Struct**:
   - It defines a `Employee` struct with attributes for employee ID, name, designation, and salary.

2. **Add Employee Function** (`addEmployee(const Employee &emp)`):
   - Appends the employee's information to a file named "employee_data.txt" in CSV format.

3. **Delete Employee Function** (`deleteEmployee(int employeeID)`):
   - Reads employee records from the file and copies them to a temporary file, excluding the record with the specified employee ID.
   - Deletes the original file and renames the temporary file to replace it.

4. **Display Employee Function** (`displayEmployee(int employeeID)`):
   - Searches for an employee record by employee ID and displays the details if found.

5. **Main Function**:
   - Presents a menu to the user with options to add, delete, or display employee records, or to exit the program.
   - Reads the user's choice and calls the corresponding function.
   - Loops until the user chooses to exit (enters 0).

Overall, this program provides basic CRUD (Create, Read, Update, Delete) functionalities for managing employee records using file handling operations. However, it lacks error handling for invalid input or file operations. Adding error handling would make the program more robust.
*/