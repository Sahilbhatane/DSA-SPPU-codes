/*Read the marks obtained by students of second year in an online examination of
particular subject. Find out maximum and minimum marks obtained in that
subject. Use heap data
structure. Analyze the algorithm.*/

#include <bits/stdc++.h>
using namespace std;

struct MinHeap
{
    int *arr;
    int capacity;
    int size;

    MinHeap(int capacity)
    {
        this->capacity = capacity;
        size = 0;
        arr = new int(capacity);
    }

    int left(int i)
    {
        return (2 * i + 1);
    }

    int right(int i)
    {
        return (2 * i + 2);
    }

    int parent(int i)
    {
        return ((i - 1) / 2);
    }

    void insert(int marks)
    {
        if (size == capacity)
        {
            cout << "Overflow" << endl;
            return;
        }
        size++;
        arr[size - 1] = marks;

        int i = size - 1;
        while (i != 0 and arr[parent(i)] > arr[i])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
};

struct MaxHeap
{
    int *arr;
    int capacity;
    int size;

    MaxHeap(int capacity)
    {
        this->capacity = capacity;
        arr = new int(capacity);
        size = 0;
    }

    int left(int i)
    {
        return (2 * i + 1);
    }

    int right(int i)
    {
        return (2 * i + 2);
    }

    int parent(int i)
    {
        return ((i - 1) / 2);
    }

    void insert(int marks)
    {
        if (size == capacity)
        {
            return;
        }
        size++;
        arr[size - 1] = marks;
        int i = size - 1;
        while (i != 0 and arr[parent(i)] < arr[i])
        {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }
};

int main()
{
    int n;
    cout << "Enter the number of students-\n";
    cin >> n;
    MinHeap min_heap(n);
    MaxHeap max_heap(n);
    for (int i = 0; i < n; i++)
    {
        int marks;
        cout << "Enter the marks of the student-\n";
        cin >> marks;
        min_heap.insert(marks);
        max_heap.insert(marks);
    }

    cout << "The minimum marks are- " << min_heap.arr[0] << endl;
    cout << "The maximum marks are- " << max_heap.arr[0] << endl;
}

/*Enter the number of students-
5
Enter the marks of the student-
78
Enter the marks of the student-
92
Enter the marks of the student-
65
Enter the marks of the student-
85
Enter the marks of the student-
77




EXPLANATION - 
This C++ program implements two heap data structures, namely MinHeap and MaxHeap, to store and retrieve the minimum and maximum marks of students, respectively. Let's dissect the code:

1. **MinHeap Struct**:
   - It has data members for the heap array (`arr`), capacity (`capacity`), and current size (`size`).
   - Provides member functions for left child index (`left(i)`), right child index (`right(i)`), parent index (`parent(i)`), and insertion (`insert(marks)`).

2. **MaxHeap Struct**:
   - Similar to MinHeap, it stores the maximum marks.
   - Provides the same member functions as MinHeap, with slight modifications in the insertion logic to maintain the max-heap property.

3. **Main Function**:
   - Reads the number of students (`n`) from the user.
   - Creates instances of MinHeap and MaxHeap with capacity `n`.
   - Enters a loop to input marks for each student and inserts them into both the MinHeap and MaxHeap.
   - Prints the minimum marks (root of MinHeap) and maximum marks (root of MaxHeap).

The program efficiently handles the input of student marks and provides quick access to both the minimum and maximum marks using the heap data structures.
*/