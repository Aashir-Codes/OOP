#include <iostream>
#include"Document.h"
#include"String.h"

using namespace std;

void menu()
{
	cout << "\n<================================================================>" << endl;
	cout << "                             MENU" << endl;
	cout << "<================================================================>" << endl;
	cout << "1. INSERT LINE" << endl;
	cout << "2. Remove Line" << endl;
	cout << "3. Add line" << endl;
	cout << "0. Exit" << endl;
	cout << "<================================================================>" << endl;
}
int main()
{
	Document one;
	String Line;
	int Choice=0,index=0;
	
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
		case 0:
			cout << "Exiting!" << endl;
			break;
		default:
			cout << "Invalid Choice Entered!" << endl;
			break;

			cout << "Enter any key to continue!" << endl;
			cin.get();
			cin.ignore();
		}

	
	} while (Choice != 0);




	return 0;
}