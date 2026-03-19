#include <iostream>
#include "list.h"
using namespace std;


int main()
{
	Polynomial p1;
	char filename[100];

	cout << "Enter the name of the polynomial file : ";
	cin >> filename;

	p1.readFromFile(filename);

	if (p1.isEmpty())
	{
		cout << "Polynomial is empty or file not found. Exiting." << endl;
		return 1;
	}

	cout << filename << " ";
	p1.display();

	system("pause");
	system("cls");

	int choice;
	do
	{
		cout << "\n1. ADD polynomial" << endl;
		cout << "2. MULTIPLY polynomial" << endl;
		cout << "3. EVALUATE polynomial" << endl;
		cout << "4. QUIT" << endl;
		cout << "Enter choice : ";
		cin >> choice;

		if (choice == 1)
		{
			system("cls");
			char file2[100];
			cout << "Enter the file containing the polynomial to add => ";
			cin >> file2;

			Polynomial p2;
			p2.readFromFile(file2);

			if (!p2.isEmpty())
			{
				cout << file2 << " ";
				p2.display();

				Polynomial sum = p1.add(p2);
				cout << "Sum: ";
				sum.display();

			}
			system("pause");
		}
		else if (choice == 2)
		{
			system("cls");
			char file2[100];
			cout << "Enter the file containing the polynomial to multiply => ";
			cin >> file2;

			Polynomial p2;
			p2.readFromFile(file2);

			if (!p2.isEmpty())
			{
				cout << file2 << " ";
				p2.display();

				Polynomial product = p1.multiply(p2);
				cout << "Product: ";
				product.display();
			}
			system("pause");
		}
		else if (choice == 3)
		{
			system("cls");
			float x;
			cout << "Enter the value of x => ";
			cin >> x;

			float result = p1.evaluate(x);
			cout << "P(" << x << ") = " << result << endl;
			system("pause");
		}
		else if (choice == 4)
		{
			system("cls");
			cout << "Exiting..." << endl;
		}
		else
		{
			system("cls");
			cout << "Invalid choice. Please enter 1-4." << endl;
			system("pause");
		}

	} while (choice != 4);

	return 0;
}


