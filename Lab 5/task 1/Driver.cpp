#include <iostream>
#include <conio.h>
#include "LinkList.cpp"

int main()
{
	List<int> L;
	int choice, val, newval, oldval; 
	bool check;
	do {
		system("cls");
		cout << "Linked List Implementation ";
		cout << "\n1. Push Item"
			<< "\n2. Insert after a value"
			<< "\n3. Delete a value"
			<< "\n4. Pop Item"
			<< "\n5. Display List"
			<< "\n6. Check if empty"
			<< "\n7. exit"
			<< "\nYour choice : ";
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
			system("cls");
			cout << "Enter Value you want to push : ";
			cin >> val;
			L.push(val);
			break;
		case 2:
			system("cls");
			while (true) {
				cout << "Enter Value you want to insert : ";
				cin >> newval;
				cout << "\nEnter Value you want to insert after : ";
				cin >> oldval;
				if (L.insertafter(oldval, newval)) 
				{
					cout << "Insertion successful." << endl;
					break;
				}
				else 
				{
					cout << "Value not found. Try again? (y/n): ";
					char retry;
					cin >> retry;
					if (retry != 'y' && retry != 'Y') 
					{
						cout << "Insertion cancelled." << endl;
						break; 
					}
					system("cls");
				}
			}
			system("pause");
			break;
		
		case 3:
			system("cls");
			while (true) 
			{
				cout << "Enter value you want to delete : ";
				cin >> val;
				if (L.deleteItem(val))
				{
					cout << "Deletion successful." << endl;
					break;
				}
				else
				{
					cout << "Value not found. Try again? (y/n): ";
					char retry;
					cin >> retry;
					if (retry != 'y' && retry != 'Y') 
					{
						cout << "Deletion cancelled." << endl;
						break;
					}
					system("cls");
				}
			}
			system("pause");
			break;

		case 4:
			system("cls");
			cout << "Popped " << L.pop();
			cout << endl;
			system("pause");
			break;
		case 5:
			system("cls");
			cout << "Displaying the whole list : " << endl;
			L.displayList();
			system("pause");
			break;
		case 6:
			system("cls");
			check = L.emptyList();
			if (check)
			{
				cout << "The list is empty";
			}
			else
			{
				cout << "The list is not empty";
			}
			cout << endl;
			system("pause");
			break;
		case 7:
			exit(1);
		default:
			cout << "\nInvalid Input";
		}
	} 
	while (choice != 7);
	return 0;
}
