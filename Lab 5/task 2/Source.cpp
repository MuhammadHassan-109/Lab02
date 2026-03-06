#include "List.h"
using namespace std;

void clearScreen() 
{
    system("cls");
}

int main() {
    LinkedStr list;
    int choice;
    int len, k;

    do {
        cout << "\n--- Linked List Menu ---\n";
        cout << "1. Create new list\n";
        cout << "2. Display list\n";
        cout << "3. Remove first element\n";
        cout << "4. Remove last element\n";
        cout << "5. Remove element by value\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            clearScreen();
            cout << "Enter length of linked list: ";
            cin >> len;
            list.makeStr(len);
            break;
        case 2:
            clearScreen();
            list.displayStr();
            break;
        case 3:
            clearScreen();
            list.removeFirst();
            cout << "First element removed.\n";
            list.displayStr();
            break;
        case 4:
            clearScreen();
            list.removeLast();
            cout << "Last element removed.\n";
            list.displayStr();
            break;
        case 5:
            clearScreen();
            cout << "Enter value to remove: ";
            cin >> k;
            if (list.remove(k)) 
            {
                cout << "Element " << k << " removed.\n";
            }
            else 
            {
                cout << "Element " << k << " not found or list is empty.\n";
            }
            list.displayStr();
            break;

        case 6:
            clearScreen();
            cout << "Exiting program.\n";
            break;
        default:
            clearScreen();
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
