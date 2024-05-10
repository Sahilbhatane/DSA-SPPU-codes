/*Beginning with an empty binary search tree, construct binary search tree by inserting the
values in the order given. After constructing a binary tree -
i. Insert new node, ii. Find number of nodes in longest path from root, iii. Minimum
datavalue found in the tree, iv. Change a tree so that the roles of the left and right
pointers.are swapped at every node, v. Search a value*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void traversal(Node* root) 
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        cout << root->data << " ";
        traversal(root->left);
        traversal(root->right);
    }
}

Node* insert(Node* &root, int x)
{
    if (root == NULL)
    {
        root = new Node(x);
    }
    else if (x >= root->data)
    {
        root->right = insert(root->right, x);
    }
    else if (x < root->data)
    {
        root->left = insert(root->left, x);
    }
    return root;
}

int height(Node* root)
{
    if (root == NULL)
    {
        return 0;
    }    
    int left_subtree = 1+height(root->left);
    int right_subtree = 1+height(root->right);
    return max(left_subtree, right_subtree);
}

int minimum(Node* root)
{
    if (root->left == NULL)
    {
        return root->data;
    }
    return min(minimum(root->left), root->data);
}

void search(Node* root, int key, bool &present)
{
    if (root == NULL)
    {
        return;
    }
    if (root->data == key)
    {
        present = true;
    }
    else if (root->data > key)
    {
        search(root->left, key, present);
    }
    else if (root->data <= key)
    {
        search(root->right, key, present);
    }
}

void mirror(Node* &root)
{
    if (root == NULL)
    {
        return;
    }
    mirror(root->left);
    mirror(root->right);
    swap(root->left, root->right);
}

int main()
{
    Node *root = NULL;
    int n;
    cout << "Enter the number of nodes to be inserted in the BST-\n";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int element;
        cout << "Enter the data value to be inserted-\n";
        cin >> element;
        insert(root, element);
    }
    cout << "Displaying the elements of the BST-\n";
    traversal(root);
    cout << endl;
    cout << "Height of the tree is " << height(root) << endl;
    cout << "Minimum value in the BST is " << minimum(root) << endl;
    int key;
    cout << "Enter the data value to be searched in the BST-\n";
    cin >> key;
    bool present = false;
    search(root, key, present);
    if (present == true)
    {
        cout << "Key is present in the BST!" << endl;
    }
    else
    {
        cout << "Key is not present in the BST!" << endl;
    }
    return 0;
}



/*
Enter the number of nodes to be inserted in the BST-
7
Enter the data value to be inserted-
10
Enter the data value to be inserted-
5
Enter the data value to be inserted-
15
Enter the data value to be inserted-
3
Enter the data value to be inserted-
7
Enter the data value to be inserted-
12
Enter the data value to be inserted-
20
Enter the data value to be searched in the BST-
7



explanation - 
This C++ code defines a Binary Search Tree (BST) and provides functions to insert nodes, perform tree traversal, find the height of the tree, find the minimum value in the tree, search for a key, and mirror the tree.

Here's a breakdown of the code:

- Lines 1-2: Include necessary header files.
- Lines 4-11: Define the structure for a binary tree node (`Node`), which contains an integer data value and pointers to left and right child nodes.
- Lines 13-21: Define a recursive function `traversal` to perform pre-order traversal of the binary tree.
- Lines 23-33: Define a recursive function `insert` to insert a new node with the given value into the binary search tree.
- Lines 35-46: Define a recursive function `height` to calculate the height of the binary tree.
- Lines 48-56: Define a function `minimum` to find the minimum value in the binary search tree.
- Lines 58-70: Define a recursive function `search` to search for a key in the binary search tree.
- Lines 72-78: Define a recursive function `mirror` to mirror the binary tree.
- Lines 80-99: The `main` function where the user can input the number of nodes to be inserted into the BST, and then perform various operations on the BST such as traversal, finding height, finding minimum value, and searching for a key.

Overall, this code provides basic functionality for working with binary search trees, including insertion, traversal, height calculation, minimum value finding, and searching.

*/