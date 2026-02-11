#pragma once
#include <vector>
#include <iostream>
#include <string>

class Student
{
private:
    std::string firstName;
    std::string lastName;
    std::vector<int> grades;
    double average;
public:
    Student();

    void setName(const std::string& first, const std::string& last);

    void setGrades(const std::vector<int>& g);

    void computeAverage();

    std::string getFullName() const;

    void printInfo() const;

    bool matchesName(const std::string& first, const std::string& last) const;
};
