/*
A book consists of chapters, chapters consist of sections and sections consist of
subsections. Construct a tree and print thenodes. Find the time and space requirementsof
your method.
*/

#include<bits/stdc++.h>
using namespace std;

// Define a structure for the node
struct Node
{
    string name;
    vector<Node*> nodes;

    // Constructor to initialize node with a name
    Node (string name)
    {
        this->name = name;
    }
};

// Function to construct the tree
Node* construct()
{
    string rootData;
    cout << "Enter the name here-\n";
    cin >> rootData;

    // Create a new node with the provided name
    Node* root = new Node(rootData);

    int n;
    cout << "Enter the number of children-\n";
    cin >> n;

    // Recursively construct children for the current node
    for (int i = 0; i < n; i++)
    {
        Node* child = construct();
        root->nodes.push_back(child);
    }

    return root;
}

// Function to display the tree
void display(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->name << " : ";

    // Display children of the current node
    for (int i = 0; i < root->nodes.size(); i++)
    {
        cout << root->nodes[i]->name << " ";
    }
    cout << endl;

    // Recursively display children of the current node
    for (int i = 0; i < root->nodes.size(); i++)
    {
        display(root->nodes[i]);
    }
}

// Main function
int main()
{
    // Construct the tree and display it
    Node* book = construct();
    display(book);
    return 0;
}


/*
Enter the name here-
Book
Enter the number of children-
2
Enter the name here-
Chapter1
Enter the number of children-
1
Enter the name here-
Section1.1
Enter the number of children-
0
Enter the name here-
Chapter2
Enter the number of children-
2
Enter the name here-
Section2.1
Enter the number of children-
0
Enter the name here-
Section2.2
Enter the number of children-
1
Enter the name here-
Subsection2.2.1
Enter the number of children-
0


explaination - 
This C++ code defines a structure for a tree node and provides functions to construct and display a tree using the defined node structure.

The `Node` structure has a string variable `name` to store the name of the node and a vector `nodes` to store pointers to its child nodes.

The `construct` function recursively constructs the tree. It prompts the user to enter the name of the current node and the number of its children. Then, it creates a new node with the provided name and recursively constructs its children.

The `display` function recursively displays the tree. It prints the name of the current node along with the names of its children. Then, it recursively displays the children of each child node.

In the `main` function, the tree is constructed using the `construct` function, and then it's displayed using the `display` function.

*/
