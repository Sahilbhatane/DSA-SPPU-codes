
/*
Convert given binary tree into threaded binary tree. Analyzetime and space complexity
of the algorithm.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    Node* left;
    Node* right;
    Node (char data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

struct Stack 
{
    Node* data[100];
    int top = -1;
    void push(Node* element)
    {
        if (isFull() == true)
        {
            cout << "Overflow" << endl;
            return;
        }
        top++;
        data[top] = element;
    }
    void pop()
    {
        if (isEmpty() == true)
        {
            cout << "Underflow" << endl;
            return;
        }
        top--;
    }
    Node* peek()
    {
        return data[top];
    }
    int size()
    {
        return (top + 1);
    }
    bool isEmpty()
    {
        if (top == -1) return true;
        else return false;
    }
    bool isFull()
    {
        if (top == 99) return true;
        else return false;
    }
};

Node* constructTree(Stack &mystack, string expression)
{
    for (int i = expression.length()-1; i >= 0; i--)
    {
        if ((expression[i] == '+') or (expression[i] == '-') or (expression[i] == '/') or (expression[i] == '*'))
        {
            Node* op1 = mystack.peek();
            mystack.pop();
            Node* op2 = mystack.peek();
            mystack.pop();
            Node* newnode = new Node(expression[i]);
            newnode->left = op1;
            newnode->right = op2;
            mystack.push(newnode);
        }
        else
        {
            Node* newnode1 = new Node(expression[i]);
            mystack.push(newnode1);
        }
    }
    return mystack.peek();
}

void inorder_traversal(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    inorder_traversal(root->left);
    cout << root->data;
    inorder_traversal(root->right);
}

void postorder_traversal(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout << root->data;
}

void delete_root(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    delete_root(root->left);
    delete_root(root->right);
    delete (root);
}

void iterative_preorder(Node* root)
{
    Stack mystack;
    mystack.push(root);
    while (mystack.isEmpty() != true)
    {
        Node* temp = mystack.peek();
        mystack.pop();
        cout << temp->data;
        if (temp->right != NULL) mystack.push(temp->right);
        if (temp->left != NULL) mystack.push(temp->left);
    }
    cout << endl;
}

void iterative_postorder(Node* root)
{
    if (root == NULL) return;
    Stack stack1;
    Stack stack2;
    stack1.push(root);
    while (stack1.isEmpty() != true)
    {
        Node* temp = stack1.peek();
        stack1.pop();
        stack2.push(temp);
        if (temp->left != NULL) stack1.push(temp->left);
        if (temp->right != NULL) stack1.push(temp->right);
    }
    while (stack2.isEmpty() != true)
    {
        cout << stack2.peek()->data;
        stack2.pop();
    }
    cout << endl;
}


int main()
{
    Stack mystack;
    string s;
    cout << "Enter the prefix expression here-\n";
    cin >> s;
    Node* root = constructTree(mystack, s);
    // cout << "Inorder traversal of the prefix tree is- ";
    // inorder_traversal(root);
    // cout << "\n";
    cout << "Postorder traversal of the expression tree is- ";
    postorder_traversal(root);
    cout << "\n";
    // cout << "Iterative preorder traversal of the expression tree is- ";
    // iterative_preorder(root);
    cout << "Iterative postorder traversal of the expression tree is- ";
    iterative_postorder(root);
    delete_root(root);
    return 0;
}


/*
*+AB-CD
*/

// To convert the given binary tree into a threaded binary tree, we need to implement threading in such a way that each node's right child pointer points to the inorder successor if it exists; otherwise, it should point to the inorder successor in the threaded binary tree.

// To analyze the time and space complexity of the algorithm:

// Time Complexity:
// - The `constructTree` function constructs the binary tree from the given prefix expression. It traverses the expression string once, so its time complexity is O(n), where n is the length of the expression.
// - The `inorder_traversal`, `postorder_traversal`, and `iterative_postorder` functions perform tree traversal, visiting each node once. So, their time complexity is O(n), where n is the number of nodes in the tree.
// - The `delete_root` function deletes each node in the tree recursively, visiting each node once. So, its time complexity is also O(n).
// - Overall, the time complexity of the algorithm is O(n), where n is the number of nodes in the tree.

// Space Complexity:
// - The `Stack` structure is used to implement the stack for iterative traversals and for constructing the binary tree. Its size is fixed at 100 in this implementation, so the space complexity of the stack is O(1).
// - Other than the stack, additional space is used for storing the binary tree nodes and temporary variables during traversal. As each node is stored only once, the space complexity for the tree is O(n), where n is the number of nodes in the tree.
// - Overall, the space complexity of the algorithm is O(n) due to the space required for storing the binary tree.

// This C++ code converts a given prefix expression into a binary tree and then performs postorder traversal of the binary tree iteratively, including the implementation of the iterative postorder traversal algorithm.

// Let's break down the code:

// 1. Includes necessary header files for input/output and the standard library.
// 2. Defines a structure `Node` representing a node in the binary tree. Each node contains a character `data`, representing an operand or operator, and pointers `left` and `right` to its left and right children.
// 3. Defines a structure `Stack` for implementing a stack using an array. It contains methods for push, pop, peek, size, isEmpty, and isFull operations.
// 4. Defines a function `constructTree` to construct a binary tree from the given prefix expression. It uses a stack to construct the tree by iterating over the expression characters from right to left. Operators are popped from the stack and combined with the next two operands until the tree is fully constructed.
// 5. Defines functions `inorder_traversal`, `postorder_traversal`, and `iterative_postorder` for performing inorder, postorder, and iterative postorder traversals of the binary tree, respectively.
// 6. Defines a function `delete_root` to recursively delete all nodes of the binary tree.
// 7. In the `main` function:
//    - Creates an instance of the `Stack` structure.
//    - Prompts the user to input a prefix expression.
//    - Constructs a binary tree from the prefix expression using the `constructTree` function.
//    - Performs postorder traversal of the binary tree using both recursive and iterative methods.
//    - Deletes the binary tree using the `delete_root` function.

// Overall, this code converts a prefix expression into a binary tree, performs postorder traversal iteratively, and demonstrates the iterative postorder traversal algorithm.