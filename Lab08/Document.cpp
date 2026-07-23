#include <iostream>
#include<fstream>
#include<cstdlib>
#include"Document.h"
#include "String.h"
using namespace std;


//<====================================================>
//                    Constructors
//<====================================================>

Document::Document() : lines(nullptr), tracker(0) {};

Document::Document(String Line)
{
	tracker = 1;
	lines = new String*[1] {};
	lines[0] = new String(Line);
}

Document::Document(String* arr, int count)
{
	tracker = count;
	lines = new String*[tracker];

	for (int i = 0; i < count; i++)
		lines[i] = new String(arr[i]);

}

//<====================================================>
//                    Destructors
//<====================================================>
Document::~Document()
{
	for (int i = 0; i < tracker; i++)
		delete lines[i];
	delete[] lines;
}

//<====================================================>
//                Member Functions
//<====================================================>
void Document::addLine(String _line)
{


	Regrow();

	lines[tracker - 1] = new String(_line);



}

void Document::get_line(int index)
{
	if (index < 0 || index >= tracker)
	{
		cout << "Enter a valid index!" << endl;
		cout << "Enter any key to continue!" << endl;
		cin.get();
		cin.ignore();

		return;
	}
	system("cls");
	cout << *lines[index];
	cout << "\nEnter any key to continue!" << endl;
	cin.get();
	cin.ignore();


}

void Document::Regrow()
{
	String** newptr = new String*[tracker + 1];

	for (int i = 0; i < tracker; i++)
		newptr[i] = lines[i];

	delete[] lines;

	tracker++;

	lines = newptr;
}

void Document::Shrink(int index)
{
	if (tracker == 0 || index < 0 || index >= tracker) return;


	String** newptr = new String*[tracker - 1];

	for (int i = 0; i < tracker; i++)
	{
		if (i == index)continue;
		if (i < index)newptr[i] = lines[i];
		if (i > index)newptr[i - 1] = lines[i];
	}

	delete[] lines;

	tracker--;

	lines = newptr;
}

void Document::removeLine(int idx) { Shrink(idx); }

void Document::insertline(String _line, int idx)
{
	if (idx<0 or idx > tracker + 1) return;
	Regrow();
	for (int i = tracker - 1; i > idx; i--)
		lines[i] = lines[i - 1];

	lines[idx] = new String(_line);

}

void Document::display()
{
	for (int i = 0; i < tracker; i++)
		cout << *lines[i] << "\n";
}

void Document:: Selection_sort()
{
    
	for (int i = 0; i < tracker; i++)
	{
		for (int j = i + 1; j < tracker; j++)
		{
			if (*lines[j] < *lines[i])
				swap(lines[i], lines[j]);
		}
	}
}

void Document::File(const char* inFile, const char* outFile)
{
	char arr[256] = {};
	ifstream Rdr(inFile);
	if (!Rdr)
	{
		cout << "File Not opened: " << inFile << endl;
		cout << "Enter any key to continue!" << endl;
		cin.get();
		cin.ignore();
		return;
	}

	while (Rdr.getline(arr, 256))
	{
		String line(arr);
		line.trim();				// drop leading/trailing spaces
		if (line.empty()) continue;	// skip blank lines

		this->Regrow();
		lines[tracker - 1] = new String(line);
	}
	Rdr.close();

	this->Selection_sort();

	ofstream Wrt(outFile);
	if (!Wrt)
	{
		cout << "File Not opened: " << outFile << endl;
		return;
	}

	for (int i = 0; i < tracker; i++)
		Wrt << *lines[i] << '\n';

	Wrt.close();

	cout << "Sorted " << tracker << " lines -> " << outFile << endl;
}
