#pragma once
#include"String.h"

class Document {
private:
	String** lines;
	int tracker;

public:


	//<====================================================>
	//                    Constructors
	//<====================================================>
	Document();

	Document(String Line);

	Document(String* arr, int count);

	//<====================================================>
	//                    Destructors
	//<====================================================>
	~Document();

	//<====================================================>
	//                Member Functions
	//<====================================================>
	void addLine(String _line);

	void insertline(String _line, int idx);

	void File(const char* inFile, const char* outFile);

	void get_line(int index);

	void Regrow();

	void Shrink(int index);

	void removeLine(int idx);

	void Selection_sort();

	void display();

};