#pragma once
#include"String.h"

class Document {
private:
	String* lines;
	int tracker;

public:

	Document();

	Document(String Line);

	Document(String* arr, int count);

	~Document();

	void addLine(String _line);

	void Regrow();

	void Shrink(int index);

	void removeLine(int idx);

	void insertline(String _line, int idx);

	void display();

};