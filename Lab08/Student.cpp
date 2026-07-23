#include <iostream>
#include <fstream>
#include "Student.h"
using namespace std;

//<====================================================>
//                  Constructors
//<====================================================>
Student::Student() : roll_no(0), cgpa(0.0), courses(nullptr) {};

Student::Student(String _name, int _roll_no, float _cgpa, vector* _courses)
	: name(_name), roll_no(_roll_no), cgpa(_cgpa), courses(_courses) {};

// Deep copy so two Students never share (and later double-free) the same vector.
Student::Student(const Student& other)
	: name(other.name), roll_no(other.roll_no), cgpa(other.cgpa)
{
	courses = other.courses ? new vector(*other.courses) : nullptr;
}

//<====================================================>
//                  Destructor
//<====================================================>
Student::~Student()
{
	delete courses;					// single object -> delete, not delete[]
}

//<====================================================>
//                  Operators
//<====================================================>
Student& Student::operator=(const Student& other)
{
	if (this == &other) return *this;

	name = other.name;
	roll_no = other.roll_no;
	cgpa = other.cgpa;

	delete courses;
	courses = other.courses ? new vector(*other.courses) : nullptr;

	return *this;
}

// Sort key = name (alphabetical). Was infinite recursion before.
bool operator > (const Student& LHS, const Student& RHS)
{
	return LHS.name > RHS.name;
}

//<====================================================>
//                  Getters
//<====================================================>
String  Student::get_name()const { return name; }
vector* Student::get_courses()const { return courses; }
int     Student::get_roll_no()const { return roll_no; }
float   Student::get_cgpa()const { return cgpa; }

//<====================================================>
//        Q3: read student.txt -> sorted_student.txt
//   line format:  name, roll, cgpa, m1,m2,m3,...
//<====================================================>

// tiny float parser ("3.5" -> 3.5f) since String has stoi() but no stof()
static float parseFloat(String tok)
{
	char* s = tok.get_str();
	if (!s) return 0.0f;

	float result = 0.0f, div = 1.0f;
	bool dot = false;
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '.') { dot = true; continue; }
		if (s[i] < '0' || s[i] > '9') continue;
		if (!dot) result = result * 10 + (s[i] - '0');
		else { div *= 10; result += (s[i] - '0') / div; }
	}
	return result;
}

void sortStudentFile(const char* inFile, const char* outFile)
{
	ifstream in(inFile);
	if (!in)
	{
		cout << "File Not opened: " << inFile << endl;
		return;
	}

	Student** students = nullptr;		// dynamic array of pointers (Student**)
	int count = 0;

	char line[512];
	while (in.getline(line, 512))
	{
		if (line[0] == '\0') continue;	// skip blank lines

		int n = 0; while (line[n] != '\0') n++;

		String name;
		int roll = 0;
		float cgpa = 0.0f;
		vector* courses = new vector();

		// walk the line, splitting on commas
		int field = 0, start = 0;
		char buf[256];
		for (int p = 0; p <= n; p++)
		{
			if (line[p] == ',' || line[p] == '\0')
			{
				int b = 0;
				for (int k = start; k < p; k++) buf[b++] = line[k];
				buf[b] = '\0';

				String tok(buf);
				tok.trim();

				if (field == 0)      name = tok;
				else if (field == 1) roll = tok.stoi();
				else if (field == 2) cgpa = parseFloat(tok);
				else if (!tok.empty()) courses->PushBack(tok.stoi());

				field++;
				start = p + 1;
			}
		}

		Student* s = new Student(name, roll, cgpa, courses);

		// grow the Student** array by one and append
		Student** grown = new Student * [count + 1];
		for (int k = 0; k < count; k++) grown[k] = students[k];
		delete[] students;
		students = grown;
		students[count++] = s;
	}
	in.close();

	// selection sort by name, swapping only pointers
	for (int i = 0; i < count; i++)
		for (int j = i + 1; j < count; j++)
			if (*students[i] > *students[j])
			{
				Student* t = students[i];
				students[i] = students[j];
				students[j] = t;
			}

	// write back in the same format as the input file
	ofstream out(outFile);
	if (!out)
	{
		cout << "File Not opened: " << outFile << endl;
	}
	else
	{
		for (int k = 0; k < count; k++)
		{
			Student* s = students[k];
			out << s->get_name() << ", " << s->get_roll_no()
				<< ", " << s->get_cgpa() << ", ";

			vector* c = s->get_courses();
			int m = c ? c->Size() : 0;
			for (int j = 0; j < m; j++)
			{
				out << c->At(j);
				if (j + 1 < m) out << ",";
			}
			out << "\n";
		}
		out.close();
		cout << "Sorted " << count << " students -> " << outFile << endl;
	}

	// free every Student (each deletes its own courses vector) then the array
	for (int k = 0; k < count; k++) delete students[k];
	delete[] students;
}
