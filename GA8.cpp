/*A Dictionary stores keywords and its meanings. Provide facility for adding new.
keywords, deleting keywords, updating values of any entry. Provide facility to
display. whole data sorted in ascending/ Descending order. Also find how many
maximum comparisons may require for finding any keyword. Use Height balance
tree and find the complexity for finding a keyword.*/

#include <bits/stdc++.h>
using namespace std;

int sum(int freq[], int i, int j);
int optCost(int freq[], int i, int j)
{
    if (j < i)
        return 0;
    if (j == i)
        return freq[i];
    int fsum = sum(freq, i, j);
    int min = INT_MAX;
    for (int r = i; r <= j; ++r)
    {
        int cost = optCost(freq, i, r - 1) + optCost(freq, r + 1, j);
        if (cost < min)
            min = cost;
    }
    return min + fsum;
}

int optimalSearchTree(int keys[], int freq[], int n)
{
    return optCost(freq, 0, n - 1);
}
int sum(int freq[], int i, int j)
{
    int s = 0;
    for (int k = i; k <= j; k++)
        s += freq[k];
    return s;
}

int main()
{
    int number_of_keys;
    cout << "\nEnter number of keys : ";
    cin >> number_of_keys;
    int keys[number_of_keys];
    int freq[number_of_keys];
    cout << "\n";
    for (int i = 0; i < number_of_keys; ++i)
    {
        cout << "Enter key and frequency : ";
        cin >> keys[i] >> freq[i];
    }
    int n = sizeof(keys) / sizeof(keys[0]);
    cout << "\nCost of Optimal BST : " << optimalSearchTree(keys, freq, n) << "\n";
    return 0;
}

/*Enter number of keys : 5

Enter key and frequency : 10 3
Enter key and frequency : 12 6
Enter key and frequency : 20 1
Enter key and frequency : 25 2
Enter key and frequency : 30 1



EXPLANATION - 
This C++ code calculates the cost of constructing an Optimal Binary Search Tree (BST) using dynamic programming.

Here's how the code works:

1. Includes necessary header files for input/output and the standard library.
2. Defines a function `sum` to calculate the sum of frequencies of keys within a given range.
3. Defines a recursive function `optCost` to calculate the minimum cost of constructing an optimal BST within a given range of keys `[i, j]`. It recursively considers each key as the root and calculates the cost of constructing the left and right subtrees, then selects the root that minimizes the total cost.
4. Defines a function `optimalSearchTree` that serves as a wrapper for `optCost`. It takes an array of keys, an array of frequencies, and the number of keys as input and returns the minimum cost of constructing the optimal BST.
5. In the `main` function:
   - Prompts the user to enter the number of keys.
   - Reads the keys and their corresponding frequencies.
   - Calculates the minimum cost of constructing the optimal BST using the `optimalSearchTree` function.
   - Prints the minimum cost.

The algorithm has a time complexity of O(n^3), where n is the number of keys, due to the nested loops in the `optCost` function. However, by using dynamic programming techniques, this cost can be significantly reduced.
*/