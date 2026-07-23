#pragma once
#include <iostream>
using namespace std;

class String
{
private:

	char*str;
	int size;

public:

	//<====================================================>
	//                    Constructors
	//<====================================================>

	String();

	String(const char* str);

	String(const String& other);

	String(const char& other);

	String(int SIZE, const char ch);

	String(int number);


	//<====================================================>
	//                    Destructors
	//<====================================================>

	~String();

	//<====================================================>
	//                Get Functions
	//<====================================================>

	char* get_str()const;

	//<====================================================>
	//                Member Functions
	//<====================================================>


	String itos(int number);

	String& trim();

	String& operator = (const String& other);

	String& insert(int pos, const char c);

	String& insert(int pos, const char* first);

	void ReplaceFirst(char c);

	int stoi() const;

	void All_substring_searching(int*& arr, int& _size, const String& other);

	int find_first(char ch);

	int find_last(char ch);

	int find_first(const String& other) const;

	int find_last(const String& other) const;

	int* find_all(char ch, int& SIZE);

	int* Regrow1D(int*& arr, int& size);

	void remove_at(int i);

	void remove_first(char ch);

	void remove_last(char ch);

	void remove_all(char ch);

	void clear();

	char& at(int pos);

	char& back();

	char& front();

	int Size() const;

	void Regrow();

	void Shrink(int index);

	//<====================================================>
	//               OPERATOR OVERLOAADING
	//<====================================================>

	bool empty() const;

	void Shifting(int index);


	char& operator[](int pos);

	const char& operator[](int pos) const;


	String& operator+=(const String& str);

	String& operator+=(char c);

	//<====================================================>
	//              NON-Member Functions
	//<====================================================>

	
	friend String operator+(const String& lhs, const String& rhs);

	friend bool operator==(const String& lhs, const String& rhs);

	friend bool operator!=(const String& lhs, const String& rhs);

	friend bool operator < (const String& lhs, const String& rhs);

	friend bool operator > (const String& lhs, const String& rhs);

	friend bool operator <=(const String& lhs, const String& rhs);

	friend bool operator >= (const String& lhs, const String& rhs);

	friend ostream& operator<<(ostream& out, const String& a);

	friend istream& operator>>(istream& in, String& a);


};

