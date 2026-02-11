#include "Student Class.h"

Student::Student() : average(0.0) {}

void Student::setName(const std::string& first, const std::string& last)
{
    firstName = first;
    lastName = last;
}

void Student::setGrades(const std::vector<int>& g)
{
    grades = g;
}

void Student::computeAverage()
{
    int sum = 0;
    for (int grade : grades)
    {
        sum += grade;
    }
    average = (!grades.empty()) ? (double)sum / grades.size() : 0.0;
}

std::string Student::getFullName() const
{
    return firstName + " " + lastName;
}

void Student::printInfo() const
{
    std::cout << firstName << " " << lastName << " ";
    for (int grade : grades)
    {
        std::cout << grade << " ";
    }
    std::cout << "Average: " << average << std::endl;
}

bool Student::matchesName(const std::string& first, const std::string& last) const
{
    return (firstName == first && lastName == last);
}
