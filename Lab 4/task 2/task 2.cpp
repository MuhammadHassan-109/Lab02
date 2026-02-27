#include <iostream>
#include "DynamicQueue.h"
using namespace std;

int main()
{
    int n, k, x;
    cout << "Enter number of elements : ";
    cin >> n;
    cout << "\n\nEnter number of elements you want to reverse : ";
    cin >> k;
    cout << "\nEnter "<<n<<" numbers : ";
    DynamicQueue<int>dq;
    for (int i = 0; i < n; ++i) 
    {
        cin >> x;
        dq.enqueue(x);
    }
    dq.reverseFirstK(k);
    for (int i = 0; i < n; ++i) {
        cout << dq.dequeue() << " ";
    }
    cout << endl;
    return 0;
}
