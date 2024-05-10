/*
You have a business with several offices; you want to lease phone lines to connect
them up with each other; and the phone company charges different amounts of money
to connect different pairs of cities. You want a set of lines that connects
all your offices. with a minimum total cost. Solve the problem by suggesting
appropriate data structures.
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 100

struct Graph
{
    int data[MAX][MAX];
    int vertices;
    int edges;

    void read()
    {
        cout << "Enter the number of vertices in the graph-\n";
        cin >> vertices;

        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                if (i != j)
                {
                    cout << "Enter the weight between vertex " + to_string(i) + " and " + to_string(j) + "\n";
                    cin >> data[i][j];
                }
                else
                {
                    data[i][j] = 0;
                }
            }
        }
    }

    void display()
    {
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    int minKey(int key[], bool mstSet[])
    {
        int min = INT_MAX, min_index;
        for (int v = 0; v < vertices; v++)
        {
            if (mstSet[v] == false && key[v] < min)
            {
                min = key[v], min_index = v;
            }
        }
        return min_index;
    }

    void printMST(int parent[])
    {
        int cost = 0;
        cout << "Edge \tWeight\n";
        for (int i = 1; i < vertices; i++)
        {
            cout << parent[i] << " - " << i << " \t" << data[i][parent[i]] << " \n";
        }
        for (int i = 1; i < vertices; i++)
        {
            cost += data[i][parent[i]];
        }
        cout << cost << endl;
    }

    void primMST()
    {
        int parent[vertices];
        int key[vertices];
        bool mstSet[vertices];

        for (int i = 0; i < vertices; i++)
        {
            key[i] = INT_MAX, mstSet[i] = false;
        }
        key[0] = 0;
        parent[0] = -1;
        for (int count = 0; count < vertices - 1; count++)
        {
            int u = minKey(key, mstSet);
            mstSet[u] = true;
            for (int v = 0; v < vertices; v++)
            {
                if (data[u][v] && mstSet[v] == false && data[u][v] < key[v])
                {
                    parent[v] = u, key[v] = data[u][v];
                }
            }
        }
        printMST(parent);
    }
};

int main()
{
    Graph g;
    g.read();
    g.display();
    g.primMST();
    return 0;
}

/*Enter the number of vertices in the graph-
4
Enter the weight between vertex 0 and 1
2
Enter the weight between vertex 0 and 2
0
Enter the weight between vertex 0 and 3
4
Enter the weight between vertex 1 and 0
2
Enter the weight between vertex 1 and 2
5
Enter the weight between vertex 1 and 3
3
Enter the weight between vertex 2 and 0
0
Enter the weight between vertex 2 and 1
5
Enter the weight between vertex 2 and 3
1
Enter the weight between vertex 3 and 0
4
Enter the weight between vertex 3 and 1
3
Enter the weight between vertex 3 and 2
1




EXPLANATION - 
This C++ code implements Prim's algorithm to find the Minimum Spanning Tree (MST) of a weighted undirected graph.

Here's a breakdown of the code:

1. Includes necessary header files for input/output and the standard library.
2. Defines a constant `MAX` for the maximum number of vertices in the graph.
3. Defines a struct `Graph` containing a 2D array `data` to represent the weighted adjacency matrix of the graph, integers `vertices` and `edges` to store the number of vertices and edges respectively, and methods to read graph data (`read`), display the adjacency matrix (`display`), find the minimum key vertex (`minKey`), print the MST (`printMST`), and find the MST using Prim's algorithm (`primMST`).
4. In the `read` method:
   - Prompts the user to enter the number of vertices in the graph.
   - Reads the weights between each pair of vertices except for self-loops.
5. In the `display` method:
   - Displays the weighted adjacency matrix of the graph.
6. The `minKey` method finds the vertex with the minimum key value among the vertices not yet included in the MST.
7. The `printMST` method prints the edges and their weights in the MST along with the total cost of the MST.
8. The `primMST` method finds the MST using Prim's algorithm:
   - Initializes arrays `parent`, `key`, and `mstSet`.
   - Sets the key values of all vertices to infinity and marks all vertices as not included in the MST.
   - Initializes the key value of the first vertex as 0 to include it in the MST.
   - Iteratively selects the vertex with the minimum key value, includes it in the MST, and updates the key values of its adjacent vertices if they are not already included in the MST and have smaller weights.
   - Prints the MST using the `printMST` method.
9. In the `main` function:
   - Creates an instance `g` of the `Graph` struct.
   - Reads graph data using the `read` method.
   - Displays the adjacency matrix using the `display` method.
   - Finds and prints the MST using the `primMST` method.

Overall, this code efficiently finds the MST of a weighted undirected graph using Prim's algorithm.
*/