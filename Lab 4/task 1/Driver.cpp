#include <iostream>
#include "DynamicQueue.h"

using namespace std;

int main()
{
    int initialSize;
    cout << "Enter initial queue size: ";
    cin >> initialSize;

    DynamicQueue<int> queue(initialSize);

    int n;
    cout << "How many numbers do you want to enqueue? ";
    cin >> n;
    if (n > initialSize)
    {
        cout << "\nQueue not capable to store this many numbers "
            <<"\nResizing it to "<<n;
    }
    cout << "\n\nEnter " << n << " numbers:\n";
    for (int i = 0; i < n; ++i)
    {
        int value;
        cin >> value;
        queue.Enqueue(value);
    }

    cout << "Dequeuing all elements:\n";
    while (!queue.IsEmpty()) 
    {
        cout << queue.Dequeue() << "  ";
    }

    cout << "\nQueue size: " << n << endl;

    return 0;
}
