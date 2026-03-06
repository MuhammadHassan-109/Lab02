#include "List.h"
using namespace std;

LinkedStr::LinkedStr() : ptr(nullptr) {}

LinkedStr::~LinkedStr() 
{
    Node* current = ptr;
    while (current) 
    {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

void LinkedStr::makeStr(int len) 
{
    while (ptr)
    {
        removeFirst();
    }
    Node* tail = nullptr;
    for (int i = 0; i < len; ++i) 
    {
        int value;
        cout << "Enter value for node " << (i + 1) << ": ";
        cin >> value;
        Node* newNode = new Node{ value, nullptr };
        if (!ptr) 
        {
            ptr = newNode;
            tail = newNode;
        }
        else 
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
}

void LinkedStr::displayStr() 
{
    Node* current = ptr;
    cout << "List: ";
    while (current) 
    {
        cout << current->info << " ";
        current = current->next;
    }
    cout << endl;
}

void LinkedStr::removeFirst() 
{
    if (!ptr) return;
    Node* temp = ptr;
    ptr = ptr->next;
    delete temp;
}

void LinkedStr::removeLast() 
{
    if (!ptr) 
    {
        return;
    }
    if (!ptr->next) 
    {
        delete ptr;
        ptr = nullptr;
        return;
    }
    Node* current = ptr;
    while (current->next && current->next->next) 
    {
        current = current->next;
    }
    delete current->next;
    current->next = nullptr;
}

bool LinkedStr::remove(int k) {
    if (!ptr) 
    {
        cout << "Error: List is empty. Nothing to remove." << endl;
        return false;
    }
    if (ptr->info == k) 
    {
        removeFirst();
        return true;
    }
    Node* current = ptr;
    while (current->next && current->next->info != k)
    {
        current = current->next;
    }
    if (current->next && current->next->info == k) 
    {
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
        return true;
    }
    else 
    {
        cout << "Error: Value " << k << " not found in the list." << endl;
        return false;
    }
}

