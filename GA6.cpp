/* There are flight paths between cities. If there is a flight between city A and city B then there
is an edge between the cities. The cost of the edge can be the time that flight take to reach
city B from A, or the amount of fuel used for the journey. Represent this as a graph. The
node can be represented by airport name or name of the city. Use adjacency list
representation of the graph or use adjacency matrix representation of the graph. Check
whether the graph is connected or not. Justify the storage representation used.*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 100

struct Graph
{
    int data[MAX][MAX];
    int vertices;

    map<pair<string, string>, int> hash;

    void read()
    {
        for (int i = 0; i < MAX; i++)
        {
            for (int j = 0; j < MAX; j++)
            {
                data[i][j] = 0;
            }
        }
        cout << "Enter the number of cities-\n";
        cin >> vertices;
        string cities[vertices];
        for (int i = 0; i < vertices; i++)
        {
            string city;
            cout << "Enter the name of the city-\n";
            cin >> cities[i];
        }
        int edges;
        cout << "Enter the number of edges-\n";
        cin >> edges;

        for (int i = 0; i < vertices; i++)
        {
            int fuel;
            for (int j = 0; j < vertices; j++)
            {
                if (i != j)
                {
                    cout << "Enter the amount of fuel required for the journey from city " + cities[i] + " to " << cities[j] << endl;
                    cin >> fuel;
                    data[i][j] = fuel;
                    pair<string, string> p = make_pair(cities[i], cities[j]);
                    hash[p] = fuel;
                }
                else
                {
                    pair<string, string> p = make_pair(cities[i], cities[j]);
                    hash[p] = 0;
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

    void check_path(pair<string, string> p)
    {
        if (hash[p] != 0)
        {
            cout << "The fuel required from city " << p.first << " to " << p.second << " is " << hash[p] << endl;
        }
        else
        {
            cout << "There is no path from city " << p.first << " to " << p.second << endl;
        }
    }

    void is_connected(int source, vector<bool> &visited)
    {
        visited[source] = true;
        for (int i = 0; i < vertices; i++)
        {
            if (data[source][i] != 0 and visited[i] != true)
            {
                is_connected(i, visited);
            }
        }
    }
};

int main()
{
    Graph g;
    g.read();
    g.display();
    string source, destination;
    cout << "Enter the source city-\n";
    cin >> source;
    cout << "Enter the destination city-\n";
    cin >> destination;
    pair<string, string> p = make_pair(source, destination);
    g.check_path(p);
    vector<bool> visited(MAX, false);
    g.is_connected(0, visited);
    bool flag = true;
    for (int i = 0; i < g.vertices; i++)
    {
        if (visited[i] == false)
        {
            flag = false;
            break;
        }
    }
    if (flag == true)
    {
        cout << "The graph is connected!" << endl;
    }
    else
    {
        cout << "The graph is not connected!" << endl;
    }
    return 0;
}

/*

Enter the number of cities-
4
Enter the name of the city-
A
Enter the name of the city-
B
Enter the name of the city-
C
Enter the name of the city-
D
Enter the number of edges-
6
Enter the amount of fuel required for the journey from city A to B
5
Enter the amount of fuel required for the journey from city A to C
10
Enter the amount of fuel required for the journey from city A to D
0
Enter the amount of fuel required for the journey from city B to A
5
Enter the amount of fuel required for the journey from city B to C
3
Enter the amount of fuel required for the journey from city B to D
0
Enter the amount of fuel required for the journey from city C to A
10
Enter the amount of fuel required for the journey from city C to B
3
Enter the amount of fuel required for the journey from city C to D
4
Enter the amount of fuel required for the journey from city D to A
0
Enter the amount of fuel required for the journey from city D to B
0
Enter the amount of fuel required for the journey from city D to C
4
Enter the source city-
A
Enter the destination city-
C



explaination - 

This C++ code defines a struct `Graph` representing an undirected graph and provides methods to read graph data, display the adjacency matrix, check the fuel required for a path between two cities, and determine if the graph is connected.

Here's a breakdown of the code:

1. Includes necessary header files for input/output and the standard library.
2. Defines a constant `MAX` for the maximum number of vertices in the graph.
3. Defines a struct `Graph` containing a 2D array `data` to represent the adjacency matrix of the graph, an integer `vertices` to store the number of vertices, and a map `hash` to store the fuel required for each edge between cities.
4. Defines methods to read graph data (`read`), display the adjacency matrix (`display`), check the fuel required for a path between two cities (`check_path`), and determine if the graph is connected (`is_connected`).
5. In the `main` function:
   - Creates an instance `g` of the `Graph` struct.
   - Reads graph data using the `read` method.
   - Displays the adjacency matrix using the `display` method.
   - Prompts the user to input source and destination cities.
   - Checks the fuel required for the path between the source and destination cities using the `check_path` method.
   - Determines if the graph is connected using the `is_connected` method.
   - Prints whether the graph is connected or not.
6. Returns 0 to indicate successful completion.

Overall, this code models an undirected graph representing cities and their connections, allowing users to check fuel requirements for paths and determine if the graph is connected.
*/