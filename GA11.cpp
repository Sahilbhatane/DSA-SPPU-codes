/*Department maintains a student information. The filecontains roll
number, name, division, and address. Allowuser to add, delete information of
student. Display information of particular employee. If record of student doesnot
exist an appropriate message is displayed. If it is, then the
system displays the student details. Use sequential file to mainthe data.*/

#include <bits/stdc++.h>
#include <fstream>
using namespace std;

struct Student
{
    int roll_number;
    string name;
    char division;
    string address;
};

void add_students()
{
    Student s;
    cout << "Enter the roll number of the student to be added-\n";
    cin >> s.roll_number;
    cout << "Enter the name of the student to be added-\n";
    cin >> s.name;
    cout << "Enter the division of the student to be added-\n";
    cin >> s.division;
    cout << "Enter the address of the student to be added-\n";
    cin >> s.address;

    ofstream write;
    write.open("students.txt", ios::app);

    write << "\n"
          << s.roll_number;
    write << "\n"
          << s.name;
    write << "\n"
          << s.division;
    write << "\n"
          << s.address;

    write.close();
}

void display(Student s)
{
    cout << "Roll Number- " << s.roll_number << endl;
    cout << "Name- " << s.name << endl;
    cout << "Division- " << s.division << endl;
    cout << "Address- " << s.address << endl;
    cout << endl;
}

void read_students()
{
    Student s;
    ifstream read;
    read.open("students.txt");

    while (!read.eof())
    {
        read >> s.roll_number;
        read >> s.name;
        read >> s.division;
        read >> s.address;

        display(s);
    }

    read.close();
}

int search_students(int roll_number)
{
    Student s;

    ifstream read;
    read.open("students.txt");

    while (!read.eof())
    {
        read >> s.roll_number;
        read >> s.name;
        read >> s.division;
        read >> s.address;

        if (s.roll_number == roll_number)
        {
            cout << "Student's record found!" << endl;
            return s.roll_number;
        }
    }

    read.close();
    cout << "Student's record not found!" << endl;
    return -1;
}

void delete_students(int roll_number)
{
    roll_number = search_students(roll_number);

    if (roll_number == -1)
    {
        cout << "Student record to be deleted is not present in the file!" << endl;
        return;
    }
    else
    {
        Student s;

        ofstream write;
        write.open("temp.txt", ios::app);

        ifstream read;
        read.open("students.txt");

        while (!read.eof())
        {
            read >> s.roll_number;
            read >> s.name;
            read >> s.division;
            read >> s.address;

            if (s.roll_number != roll_number)
            {
                write << "\n"
                      << s.roll_number;
                write << "\n"
                      << s.name;
                write << "\n"
                      << s.division;
                write << "\n"
                      << s.address;
            }
        }

        write.close();
        read.close();

        remove("students.txt");
        rename("temp.txt", "students.txt");

        cout << "Student record to be deleted is deleted successfully!" << endl;
    }
}

int main()
{
    int choice;
    do
    {
        cout << "-----STUDENT RECORDS-----" << endl;
        cout << "Enter 1 for adding a record" << endl;
        cout << "Enter 2 for displaying the records" << endl;
        cout << "Enter 3 for searching a record" << endl;
        cout << "Enter 4 for deleting a record" << endl;
        cout << "Enter 0 to exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            add_students();
            break;
        case 2:
            read_students();
            break;
        case 3:
            int roll_number;
            cout << "Enter roll number of the student to be searched-\n";
            cin >> roll_number;
            search_students(roll_number);
            break;
        case 4:
            cout << "Enter roll number of the student to be deleted-\n";
            cin >> roll_number;
            delete_students(roll_number);
            break;
        case 0:
            break;
        }
    } while (choice != 0);
}

/*
-----STUDENT RECORDS-----
Enter 1 for adding a record
Enter 2 for displaying the records
Enter 3 for searching a record
Enter 4 for deleting a record
Enter 0 to exit
1
Enter the roll number of the student to be added-
101
Enter the name of the student to be added-
John Doe
Enter the division of the student to be added-
A
Enter the address of the student to be added-
123 Main Street

-----STUDENT RECORDS-----
Enter 1 for adding a record
Enter 2 for displaying the records
Enter 3 for searching a record
Enter 4 for deleting a record
Enter 0 to exit
2
Roll Number- 101
Name- John
Division- A
Address- 123 Main Street

-----STUDENT RECORDS-----
Enter 1 for adding a record
Enter 2 for displaying the records
Enter 3 for searching a record
Enter 4 for deleting a record
Enter 0 to exit
3
Enter roll number of the student to be searched-
101
Student's record found!

-----STUDENT RECORDS-----
Enter 1 for adding a record
Enter 2 for displaying the records
Enter 3 for searching a record
Enter 4 for deleting a record
Enter 0 to exit
4
Enter roll number of the student to be deleted-
101
Student record to be deleted is deleted successfully!

-----STUDENT RECORDS-----
Enter 1 for adding a record
Enter 2 for displaying the records
Enter 3 for searching a record
Enter 4 for deleting a record
Enter 0 to exit
0


EXPLANATION -
This C++ program manages student records by allowing users to add, display, search, and delete records. Let's review its functionality:

1. **Student Struct**:
   - It defines a `Student` struct with attributes for roll number, name, division, and address.

2. **Add Students Function** (`add_students()`):
   - Prompts the user to input student details (roll number, name, division, address).
   - Appends the entered details to a file named "students.txt".

3. **Display Function** (`display()`):
   - Displays the details of a single student.

4. **Read Students Function** (`read_students()`):
   - Reads student records from the "students.txt" file and displays them.

5. **Search Students Function** (`search_students()`):
   - Searches for a student record by roll number.
   - Returns the roll number if found, otherwise, returns -1.

6. **Delete Students Function** (`delete_students()`):
   - Deletes a student record by roll number.
   - Creates a temporary file to store records except the one to be deleted.
   - Renames the temporary file to replace the original file.

7. **Main Function**:
   - Presents a menu to the user with options to add, display, search, or delete records.
   - Reads the user's choice and calls the corresponding function.
   - Loops until the user chooses to exit (enters 0).

This program effectively manages student records through file handling operations, providing basic CRUD (Create, Read, Update, Delete) functionalities. However, there are some improvements that can be made, such as error handling and more robust file input/output operations.
*/