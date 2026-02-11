#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Stack.cpp"
#include "Student Class.h"
using namespace std;

int main()
{
    string filename;
    cout << "Enter filename: ";
    cin >> filename;

    int numStudents, numGrades;
    cout << "Enter number of students: ";
    cin >> numStudents;
    cout << "Enter number of grades per student: ";
    cin >> numGrades;
    cin.ignore();

    ifstream fin(filename);
    if (!fin)
    {
        cout << "Error opening file." << endl;
        return 1;
    }

    studentStack<Student> students(numStudents);

    for (int i = 0; i < numStudents; i++)
    {
        string line;
        if (!getline(fin, line)) {
            cout << "Not enough lines in file for all students." << endl;
            break;
        }
        istringstream iss(line);
        string first, last;
        iss >> first >> last;
        vector<int> grades(numGrades);
        for (int j = 0; j < numGrades; j++)
        {
            iss >> grades[j];
        }
        Student s;
        s.setName(first, last);
        s.setGrades(grades);
        s.computeAverage();
        students.Push(s);
    }
    fin.close();

    int choice;
    do
    {
        cout << "\nMenu:\n"
            << "1. Print all usernames, all grades, and averages.\n"
            << "2. Find a student and print his/her information.\n"
            << "3. Quit.\n"
            << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            Student* tempArr = new Student[numStudents];
            for (int i = 0; i < numStudents; i++)
            {
                students.Pop(tempArr[i]);
            }
            for (int i = numStudents - 1; i >= 0; i--)
            {
                tempArr[i].printInfo();
            }
            for (int i = 0; i < numStudents; i++)
            {
                students.Push(tempArr[i]);
            }
            delete[] tempArr;
        }
        else if (choice == 2)
        {
            string first, last;
            cout << "Enter student's first name: ";
            cin >> first;
            cout << "Enter student's last name: ";
            cin >> last;

            Student* tempArr = new Student[numStudents];
            for (int i = 0; i < numStudents; i++)
            {
                students.Pop(tempArr[i]);
            }
            bool found = false;
            for (int i = numStudents - 1; i >= 0; i--)
            {
                if (tempArr[i].matchesName(first, last))
                {
                    tempArr[i].printInfo();
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                cout << "Student not found." << endl;
            }
            for (int i = 0; i < numStudents; i++)
            {
                students.Push(tempArr[i]);
            }
            delete[] tempArr;
        }
        else if (choice == 3)
        {
            cout << "Exiting program." << endl;
        }
        else
        {
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
