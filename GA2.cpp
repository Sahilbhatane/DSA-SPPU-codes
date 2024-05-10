
/*
Implement all the functions of a dictionary (ADT) using hashing and handle collisions
using chaining with / without replacement.
Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable,
Keys must be unique. Standard Operations: Insert (key, value),
Find(key), Delete(key)

*/
#include <iostream>
#include <list>
using namespace std;

class HashTable {
private:
    static const int tableSize = 10;
    list<pair<int, string>> table[tableSize];

    // Hash function to map keys to indices
    int hashFunction(int key) {
        return key % tableSize;
    }

public:
    // Insert (key, value) pair into the hash table
    void insert(int key, string value) {
        int index = hashFunction(key);
        table[index].push_back(make_pair(key, value));
    }

    // Find the value associated with a given key
    string find(int key) {
        int index = hashFunction(key);
        for (auto& kvp : table[index]) {
            if (kvp.first == key) {
                return kvp.second;
            }
        }
        return "Key not found";
    }

    // Delete the (key, value) pair associated with a given key
    void remove(int key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);
                break;
            }
        }
    }
};

int main() {
    HashTable dictionary;
    int choice, key;
    string value;

    do {
        cout << "1. Insert\n2. Find\n3. Delete\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key and value to insert: ";
                cin >> key >> value;
                dictionary.insert(key, value);
                break;
            case 2:
                cout << "Enter key to find: ";
                cin >> key;
                cout << "Value: " << dictionary.find(key) << endl;
                break;
            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                dictionary.remove(key);
                cout << "Key deleted successfully." << endl;
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}


// 1-2. We include the necessary header files for input/output operations and for using lists (dynamic arrays) in C++.

// We declare a class HashTable to represent our hash table data structure.
// We define a constant tableSize representing the size of our hash table. Here, it's set to 10.
// We declare an array of lists named table, where each list will store key-value pairs.
// This is a private member function hashFunction that calculates the hash value (index) for a given key.
// This is the public insert method. It takes a key-value pair and inserts it into the hash table.
// This is the public find method. It searches for a key in the hash table and returns the associated value if found, otherwise, it returns "Key not found".
// This is the public remove method. It deletes the key-value pair associated with a given key from the hash table.
// The main function starts here. It's the entry point of the program.
// We create an instance of the HashTable class named dictionary to work with.
// 47-52. We declare variables choice, key, and value to store user input.

// 54-73. This is a do-while loop that repeatedly displays a menu to the user, takes input, and performs corresponding operations until the user chooses to exit (by entering 4).

// 55-58. Inside the loop, we display the menu options to the user.

// We prompt the user to enter their choice.
// 61-69. Based on the user's choice, we perform insert, find, delete, or exit operations on the hash table.

// We repeat the loop until the user chooses to exit (by entering 4).
// The program ends, returning 0 to indicate successful completion.