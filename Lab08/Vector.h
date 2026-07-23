#pragma once
#include <iostream>
using namespace std;

class vector
{
private:
    int size;
    int capacity;
    int* arr;
public:
    //<==========================================================>
    //                      Constructors
    //<==========================================================>


    vector();  

    vector(int CAPACITY);

    vector(const vector& other);

    //<==========================================================>
    //                       Destructor
    //<==========================================================>
    ~vector();

    //<==========================================================>
    //                       Operators
    //<==========================================================>
    vector& operator = (const vector& other);
    int& operator [](const int& index) ;
    const int& operator[](int index) const;
    //<==========================================================>
    //                    MEMBER FUNCTIIONS
    //<==========================================================>
    void Reserve(const int& amt);
    void Assign(const int& count, const int& value);
    bool Empty();
    int Size();
    int Capacity();
    void ShrinkToFit();
    void clear();
    void Erase(int index);
    void PushBack(int val);
    void PopBack();
    int At(int index) const;
    int Front() const;
    int Back() const;
    void Swap(vector& other);
    void Append_Range(const vector& other);

    //<==========================================================>
    //                     FRIEND FUNCTIIONS
    //<==========================================================>

    friend bool operator == (const vector& Lhs, const vector& Rhs);
    friend bool operator != (const vector& Lhs, const vector& Rhs);
    friend bool operator < (const vector& Lhs, const vector& Rhs);
    friend bool operator > (const vector& Lhs, const vector& Rhs);
    friend bool operator <= (const vector& Lhs, const vector& Rhs);
    friend bool operator >= (const vector& Lhs, const vector& Rhs);
    friend ostream& operator <<(ostream& out, const vector& v);
    friend istream& operator >> (istream& in, vector& v);

};


//<==========================================================>
//             FRIEND FUNCTIIONS IMPLEMENTATION
//<==========================================================>

