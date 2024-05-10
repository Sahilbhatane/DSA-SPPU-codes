/*
Consider telephone book database of N clients. Make use of a hash table implementation to
quickly look up client‘s telephone number. Make use of two collision handling techniques
and compare them using number of comparisons required to find a set of telephone
numbers
*/


#include <iostream>
using namespace std;

const int SIZE = 100;

// Hash table implementation with linear probing
class HashTableLinearProbing
{
private:
    int ht[SIZE]; // Array for linear probing

public:
    // Constructor
    HashTableLinearProbing()
    {
        // Initialize hash table with -1 (indicating empty)
        for (int i = 0; i < SIZE; ++i)
        {
            ht[i] = -1;
        }
    }

    // Hash function
    int hashFunction(int data)
    {
        return (data % SIZE);
    }

    // Insert data into the hash table
    void insert(int data)
    {
        int index = hashFunction(data);
        if (ht[index] == -1)
        {
            cout << "No collision occurred while inserting" << endl;
            ht[index] = data;
        }
        else
        {
            cout << "Collision occurred while inserting" << endl;
            bool flag = false;
            while (true)
            {
                index = (index + 1) % SIZE;
                if (ht[index] == -1)
                {
                    ht[index] = data;
                    flag = true;
                    return;
                }
                if (index == hashFunction(data))
                {
                    cout << "The directory is full!" << endl;
                    return;
                }
            }
            if (!flag)
            {
                cout << "The directory is full!" << endl;
            }
        }
    }

    // Print the hash table
    void printHashTable()
    {
        for (int i = 0; i < SIZE; ++i)
        {
            if (ht[i] != -1)
            {
                cout << ht[i] << endl;
            }
        }
    }

    // Search for data in the hash table
    void search(int data)
    {
        int index = hashFunction(data);
        int temp = index;
        while (true)
        {
            if (ht[index] == data)
            {
                cout << "Phone Number found in the directory!" << endl;
                return;
            }
            index = (index + 1) % SIZE;
            if (index == temp)
            {
                cout << "Phone Number not found in the directory!" << endl;
                break;
            }
        }
    }
};

int main()
{
    // Initialize hash table
    HashTableLinearProbing linearProbingTable;

    while (true)
    {
        int choice;
        cout << "Enter 1 to insert a Phone Number in the directory\nEnter 2 to search a Phone Number in the directory\nEnter 3 to Print the directory\nEnter 4 to quit\n";
        cin >> choice;

        if (choice == 1)
        {
            int n;
            cout << "Enter the count of Phone Numbers to be inserted:" << endl;
            cin >> n;
            for (int i = 0; i < n; ++i)
            {
                int x;
                cout << "Enter the Phone Number to be inserted:" << endl;
                cin >> x;
                if (to_string(x).length() == 10)
                {
                    linearProbingTable.insert(x);
                }
                else
                {
                    cout << "Please enter a valid number!" << endl;
                }
            }
        }
        else if (choice == 2)
        {
            int x;
            cout << "Enter the Phone Number to be searched in the directory:" << endl;
            cin >> x;
            linearProbingTable.search(x);
        }
        else if (choice == 3)
        {
            linearProbingTable.printHashTable();
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            cout << "Please Enter a valid choice!" << endl;
        }
    }

    return 0;
}

/*

Insert phone numbers into the directory:

Enter the count of phone numbers to be inserted: 5
Enter the phone number to be inserted: 1234567890
Enter the phone number to be inserted: 9876543210
Enter the phone number to be inserted: 5551234567
Enter the phone number to be inserted: 9998887777
Enter the phone number to be inserted: 8805530486 (This will result in a collision)
Search for a phone number in the directory:

Enter the phone number to be searched in the directory: 8805530486 (This should be found)
Enter the phone number to be searched in the directory: 1112223333 (This should not be found)
Print the directory.

Choose any other options as needed.


explaination - 
We include the necessary header file for input/output operations and define a constant SIZE which represents the size of our hash table.
This line declares a class HashTableLinearProbing which encapsulates the functionality of a hash table using linear probing. It has a private member ht which is an array representing the hash table.
The constructor initializes the hash table with -1, indicating that the slots are initially empty.
The hashFunction method calculates the hash value for a given data using the modulo operator %.
The insert method inserts data into the hash table. If the calculated index is empty, it inserts the data there. If there's a collision, it uses linear probing to find the next available slot.
This method prints the non-empty elements of the hash table.
The search method searches for a given data in the hash table. It uses linear probing to find the data if there's a collision.
The main function initializes a HashTableLinearProbing object and enters a loop to interact with the user.
68-72. Inside the loop, the user is prompted to choose an operation: insert, search, print, or quit.

74-88. Depending on the user's choice, the program executes the corresponding operation: insert phone numbers, search for a phone number, print the directory, or quit the program.

The program ends when the user chooses to quit.





*/