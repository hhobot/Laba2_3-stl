#pragma once
#include <map>
#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
	string getName();
	map<string, int> getMarks();
	void printMark();
	Student(string Name, map<string, int> Marks);

private:
	string name;
	map<string, int> marks;
};

