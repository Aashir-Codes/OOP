#include "String.h"
#include<iostream>
using namespace std;
	

//<====================================================>	
//                    Constructors
//<====================================================>


String:: String()
	{
		str = nullptr;
		size = 0;
	}

String::String(const char* str)
	{
		int iterator = 0;
		for (iterator = 0; str[iterator] != '\0'; iterator++);
		size = iterator;

		this->str = new char[size + 1] {};
		for (int i = 0; i < size; i++)
			this->str[i] = str[i];


		this->str[size] = '\0';
	}

String:: String(const String& other)
	{

		size = other.size;

		str = new char [size + 1] {};

		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];

		str[size] = '\0';

	}

String:: String(const char& other)
	{
		this->size = 1;
		str = new char[size+1];

		str[0] = other;
		str[1] = '\0';
	}

String:: String(int SIZE, const char ch)
	{

		this->size = SIZE;
		str = new  char[size + 1];

		for (int i = 0; i < size; i++)
			str[i] = ch;

		str[size] = '\0';
	}

String:: String(int number)
	{
		int temp = number;
		size = 0;
		do
		{
			temp /= 10;
			size++;
		} while (temp != 0);

		str = new char[size + 1];

		for (int i = size - 1; i >= 0; i--)
		{
			str[i] = number % 10 + '0';
			number /= 10;
		}

		str[size] = '\0';


	}


//<====================================================>
//                    Destructors
//<====================================================>


String::  ~String()
{
	delete[] str;
}

//<====================================================>
//                Member Functions
//<====================================================>
    

	String& String::trim()
	{

		for (int i = 0; i < size; i++)
		{
			if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			{
				Shrink(i);
				i--;
			}
			else {
				break;
			}
		}


		for (int i = size - 1; i >= 0; i--)
		{
			if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			{
				Shrink(i);
			}
			else {
				break;
			}
		}


		return *this;
	}

	String String::itos(int number)
	{
		String Temp;
		int temp = number;
		Temp.size = 0;
		do
		{
			temp /= 10;
			Temp.size++;
		} while (temp != 0);

		Temp.str = new char[Temp.size + 1] {};

		for (int i = Temp.size - 1; i >= 0; i--)
		{
			Temp.str[i] = (number % 10) + '0';
			number /= 10;
		}

		Temp.str[Temp.size] = '\0';

		return Temp;
	}

	int String::stoi() const
	{
		int num = 0;
		for (int i = 0; i < size; i++)
			num = (str[i] - '0') + (num * 10);

		return num;
	}

	void String::ReplaceFirst(char c)
	{
		if (size == 0)
		{
			cout << "String is empty" << endl;
			return;
		}

		str[0] = c;
	}
	
	void String::All_substring_searching(int*& arr, int& _size, const String& other)
	{
		for (int i = 0; i < size; i++)
		{
			bool found = 0;


			if (str[i] == other.str[0])
			{

				for (int j = 0; j < other.size; j++)
				{
					if (str[i + j] != other.str[j])
					{
						found = 0;
						break;
					}
					found = 1;
				}

			}
			if (found)
			{
				arr = Regrow1D(arr, _size);
				arr[_size - 1] = i;
			}






		}




	}

	int String:: find_first(char ch)
	{
		for (int i = 0; i < size; i++)
			if (str[i] == ch) return i;

		return -1;
	}

	int String:: find_last(char ch)
	{
		for (int i = size - 1; i >= 0; i--)
			if (str[i] == ch) return i;

		return -1;
	}

	int String::find_first(const String& other) const
	{
		for (int i = 0; i < size; i++)
		{
			bool found = 0;


			if (str[i] == other.str[0])
			{

				for (int j = 0; j < other.size; j++)
				{
					if (str[i + j] != other.str[j])
					{
						found = 0;
						break;
					}
					found = 1;
				}

			}
			if (found)
			{
				return i;
			}


		}


		return -1;


	}

	int String::find_last(const String& other) const
	{
		for (int i = size - 1; i >= 0; i--)
		{
			bool found = 0;


			if (str[i] == other.str[other.size - 1])
			{

				for (int j = other.size - 1; j >= 0; j--)
				{
					if (str[i - j] != other.str[j])
					{
						found = 0;
						break;
					}
					found = 1;


				}

			}
			if (found)
			{
				return i - (other.size - 1);
			}


		}


		return -1;


	}

	int* String::find_all(char ch, int& SIZE)
	{
		int* indexes = nullptr;
		for (int i = 0; i < size; i++)
		{
			if (str[i] == ch)
			{
				indexes = Regrow1D(indexes, SIZE);
				indexes[SIZE - 1] = i;
			}
		}

		return indexes;


	}

	int* String::Regrow1D(int*& arr, int& size)
	{

		int* ptr = new int[size + 1];

		for (int i = 0; i < size; i++)
			ptr[i] = arr[i];
		if (size != 0)
			delete[] arr;

		size++;

		return ptr;

	}

	void String::remove_at(int i)
	{
		Shrink(i);
	}

	void String::remove_first(char ch)
	{
		for (int i = 0; i < size; i++)
			if (str[i] == ch)
			{
				Shrink(i);
				break;
			}

	}

	void String::remove_last(char ch)
	{
		for (int i = size - 1; i >= 0; i--)
			if (str[i] == ch)
			{
				Shrink(i);
				break;
			}

	}

	void String:: remove_all(char ch)
	{

		for (int i = 0; i < size; i++)
			if (str[i] == ch)
			{
				Shrink(i);
				i--;
			}

	}

	void String:: clear()
	{
		delete[] str;

		str = nullptr;
		size = 0;

	}

	char& String::at(int pos)
	{
		if (pos < 0 || pos >= size) {
			cout << "Out of bound" << endl;
			return str[size];
		}
		return str[pos];
	}

	char& String::back()
	{

		return str[size - 1];
	}

	char& String::front()
	{

		return str[0];
	}

	int String::Size() const
	{
		int iterator = 0;
		for (iterator = 0; str[iterator] != '\0'; iterator++);

		return iterator;
	}

	String& String::  operator = (const String& other)
	{
		if (this == &other) return *this;

		size = other.size;
		delete[] str;

		str = new char[size + 1] {};


		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];

		str[size] = '\0';

		return *this;
	}

	void String::Regrow()
	{

		char* newptr = new char[size + 2];

		for (int i = 0; i < size; i++)
		{
			newptr[i] = str[i];
		}

		delete[] str;


		str = newptr;

		size++;
		str[size] = '\0';
	}

	void String::Shrink(int index)
	{
		if (size == 0 || index < 0 || index >= size) return;
		char* newptr = new char[size];

		for (int i = 0; i < size; i++)
		{
			if (i == index)
			{
				continue;
			}
			if (i < index)
			{
				newptr[i] = str[i];
			}
			if (i > index)
			{
				newptr[i - 1] = str[i];

			}

		}
		newptr[size - 1] = '\0';

		delete[] str;
		str = newptr;

		size--;
	}

	bool String::empty() const
	{
		return size == 0;
	}

	void String::Shifting(int index)
	{

		for (int i = size - 1; i > index; i--)
			str[i] = str[i - 1];


	}

	String& String::insert(int pos, const char c)
	{
		Regrow();
		Shifting(pos);
		str[pos] = c;
		return *this;
	}

	String& String::insert(int pos, const char* first)
	{
		int iterator = 0;
		for (iterator = 0; first[iterator] != '\0'; iterator++);

		for (int i = pos, j = 0; j < iterator; i++, j++)
		{

			Regrow();
			Shifting(i);
			str[i] = first[j];
		}

		return *this;
	}


//<====================================================>
//               OPERATOR OVERLOAADING
//<====================================================>


	char& String:: operator[](int pos)
	{
		if (pos < 0 || pos >= size) {
			cout << "Out of bound" << endl;
			return str[size];
		}
		return str[pos];
	}

	const char& String::  operator[](int pos) const
	{
		if (pos < 0 || pos >= size) {
			cout << "Out of bound" << endl;
			return str[size];
		}
		return str[pos];

	}

	String& String:: operator+=(const String& str)
	{
		*this = *this + str;
		return *this;
	}

	String& String::  operator+=(char c)
	{
		Regrow();
		str[size - 1] = c;
		str[size] = '\0';
		return *this;
	}


//<====================================================>
//              NON-Member Functions
//<====================================================>


	String operator+(const String& lhs, const String& rhs)
	{
		int leftLen = lhs.Size();

		int rightLen = rhs.Size();


		int totalLen = leftLen + rightLen;

		char* newStr = new char[totalLen + 1];
		for (int i = 0; i < leftLen; i++)
			newStr[i] = lhs.str[i];


		for (int i = 0; i < rightLen; i++)
			newStr[i + leftLen] = rhs.str[i];

		newStr[totalLen] = '\0';

		String result(newStr);
		delete[] newStr;

		return result;
	}

	bool operator==(const String& lhs, const String& rhs)
	{
		if (lhs.size != rhs.size) return false;

		for (int i = 0; i < lhs.size; i++)
			if (lhs.str[i] != rhs.str[i]) return false;

		return true;
	}

	bool operator!=(const String& lhs, const String& rhs)
	{
		return !(lhs == rhs);
	}

	bool operator < (const String& lhs, const String& rhs)
	{
		int minLen = (lhs.size < rhs.size) ? lhs.size : rhs.size;
		for (int i = 0; i < minLen; i++)
		{
			if (lhs.str[i] < rhs.str[i]) return true;
			if (lhs.str[i] > rhs.str[i]) return false;
		}
		return lhs.size < rhs.size;
	}

	bool operator > (const String& lhs, const String& rhs) { return rhs < lhs; }

	bool operator <= (const String& lhs, const String& rhs) { return (lhs < rhs || rhs==lhs); }

	bool operator >= (const String& lhs, const String& rhs) { return (lhs > rhs || rhs == lhs); }


ostream& operator << (ostream& out, const String& a)
{

	for (int i = 0; i < a.size; i++)
		out << a.str[i];

	return out;
}

istream& operator >> (istream& in, String& a)
{
	char array[1024] = {};
	in.ignore();
	in.getline(array, 1024);
	int size = 0;
	for ( size = 0; array[size] != '\0'; size++);

	a.str = new char[size];
	for (int i = 0; i < size; i++)
		a.str[i] = array[i];

	a.size = size;

	return in;
}

