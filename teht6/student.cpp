#include "student.h"
#include <iostream>


Student::Student(string n, int a)
{
    setAge(a);
    setName(n);
}

void Student::setAge(int a)
{
    Age = a;
}

void Student::setName(string n)
{
    Name = n;
}

int Student::getAge()
{
    return Age;
}

string Student::getName()
{
    return Name;
}

void Student::printStudentinfo()
{
    cout << "Name: " << getName();
    cout << " Age: " <<getAge() << endl;
}
