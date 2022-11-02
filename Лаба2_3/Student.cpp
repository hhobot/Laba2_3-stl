#include "Student.h"

string Student::getName()
{
    return this->name;
}

map<string, int> Student::getMarks()
{
    return this->marks;
}

void Student::printMark()
{
    for (auto it = this->marks.begin(); it != this->marks.end(); it++) {
        cout << it->first << ": " << it->second << '\n';
    }
}

Student::Student(string Name, map<string, int> Marks)
{
    this->name = Name;
    this->marks = Marks;
}

