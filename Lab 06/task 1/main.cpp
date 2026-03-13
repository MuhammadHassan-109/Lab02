#include "list.cpp"
#include <iostream>


int main()
{
	List<int> L;
	int choice, value;

	do
	{
		system("cls");
		cout << "\n---- MENU ----\n";
		cout << "1. Sorted Insertion\n";
		cout << "2. Deletion\n";
		cout << "3. Traversing\n";
		cout << "4. Searching\n";
		cout << "5. Exit\n";
		cout << "Enter choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			system("cls");
			cout << "Enter value: ";
			cin >> value;
			L.insertSorted(value);
			
			break;

		case 2:
			system("cls");
			cout << "Enter value to delete: ";
			cin >> value;
			L.Deletion(value);

			break;

		case 3:
			system("cls");
			L.Traversing();
			system("pause");

			break;

		case 4:
			system("cls");
			cout << "Enter value to search: ";
			cin >> value;
			L.Search(value);
			system("pause");
			break;

		case 5:
			system("cls");
			cout << "Exiting...\n";
			break;

		default:
			cout << "Invalid choice\n";
		}

	} while (choice != 5);

	return 0;
}