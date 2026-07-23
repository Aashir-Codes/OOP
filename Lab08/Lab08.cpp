#include <iostream>
#include <cstdlib>
#include "Document.h"
#include "String.h"
#include "Student.h"
using namespace std;

void menu()
{
	cout << "\n<================================================================>" << endl;
	cout << "                             MENU" << endl;
	cout << "<================================================================>" << endl;
	cout << "1. Insert Line (at index)" << endl;
	cout << "2. Remove Line (at index)" << endl;
	cout << "3. Add Line (append)" << endl;
	cout << "4. Get Line (at index)" << endl;
	cout << "5. Sort Names File   (Q2: names.txt   -> sorted_names.txt)" << endl;
	cout << "6. Sort Students File(Q3: student.txt  -> sorted_student.txt)" << endl;
	cout << "0. Exit" << endl;
	cout << "<================================================================>" << endl;
}

int main()
{
	Document one;					// Q1: text editor backed by String**
	String Line;
	int Choice = 0, index = 0;

	do {
		system("cls");
		cout << "\n-----------------------------------------------------------------" << endl;
		cout << "                           Text" << endl;
		cout << "-----------------------------------------------------------------" << endl;
		one.display();
		menu();
		cout << "Choice: ";
		cin >> Choice;

		switch (Choice)
		{
		case 1:
			cout << "Enter the line: ";
			cin >> Line;
			cout << "\nEnter the Index: ";
			cin >> index;
			one.insertline(Line, index);
			break;
		case 2:
			cout << "\nEnter the Index: ";
			cin >> index;
			one.removeLine(index);
			break;
		case 3:
			cout << "Enter the line: ";
			cin >> Line;
			one.addLine(Line);
			break;
		case 4:
			cout << "Enter the index: ";
			cin >> index;
			one.get_line(index);
			break;
		case 5: {
			Document names;								// Q2 uses its own document
			names.File("names.txt", "sorted_names.txt");
			cout << "Enter any key to continue!" << endl;
			cin.get();
			cin.ignore();
			break;
		}
		case 6:
			sortStudentFile("student.txt", "sorted_student.txt");	// Q3
			cout << "Enter any key to continue!" << endl;
			cin.get();
			cin.ignore();
			break;
		case 0:
			cout << "Exiting!" << endl;
			break;
		default:
			cout << "Invalid Choice Entered!" << endl;
			cout << "Enter any key to continue!" << endl;
			cin.get();
			cin.ignore();
			break;
		}

	} while (Choice != 0);

	return 0;
}
