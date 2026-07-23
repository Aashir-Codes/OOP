#pragma once
#include <iostream>
#include"String.h"
#include"Vector.h"
using namespace std;

class Student
{
private:

    String  name;
	int roll_no;
	float cgpa;
	vector* courses;


public: 

	Student();
	Student(String _name, int _roll_no, float _cgpa, vector* _courses);
	Student(const Student& other);				// deep copy (rule of three)

	String get_name()const;
	vector* get_courses()const;
	int get_roll_no()const;
	float get_cgpa()const;

	~Student();

	Student & operator= (const Student& other);

	friend bool operator > (const Student& LHS, const Student& RHS);

};

//<====================================================>
//        Q3 driver: student.txt -> sorted_student.txt
//<====================================================>
void sortStudentFile(const char* inFile, const char* outFile);
