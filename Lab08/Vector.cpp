#include <iostream>
#include "Vector.h"
using namespace std;

    //<==========================================================>
    //                      Constructors
    //<==========================================================>
  vector:: vector() : size(0), capacity(0), arr(nullptr) {};

  vector:: vector(int CAPACITY) : capacity(CAPACITY), size(0)
    {
        arr = new int [CAPACITY] {};
    }    

  vector:: vector(const vector& other)
    {
        /* SHALLOW COPY (VERY DANGEROUS)
        *  this->size =other.size;
        * this->capacity=other.capacity;
        * this-arr=other.arr;
        
        */

        /* NOW DEEP COPY */

        this->size = other.size;
        this->capacity = other.capacity;
        arr = new int[capacity];
        for (int i = 0; i < size; i++)
            arr[i] = other.arr[i];

    }

    //<==========================================================>
    //                       Destructor
    //<==========================================================>
    vector:: ~vector()
    {
        delete[] arr;
        size = 0;
        arr = nullptr;
    }

    //<==========================================================>
    //                       Operators
    //<==========================================================>

    vector& vector:: operator = (const vector& other)
    {
        if (this == &other) return *this;

        delete[] arr;
        this->size = other.size;
        this->capacity = other.capacity;
        arr = new int[capacity];
        for (int i = 0; i < size; i++)
            arr[i] = other.arr[i];

        return *this;


    }

    int& vector:: operator [](const int& index) { return arr[index]; }

    const int& vector::operator[](int index) const { return arr[index]; }




    //<==========================================================>
    //                    MEMBER FUNCTIIONS
    //<==========================================================>
    void   vector:: Reserve(const int& amt)
    {
        if (amt <= capacity) return;

        int* newptr = new int[amt] {};
        for (int i = 0; i < size; i++)
            newptr[i] = arr[i];

        delete[] arr;
        arr = newptr;
        capacity = amt;
    }

    void vector::Assign(const int& count, const int& value)
    {
        Reserve(count);

        for (int i = 0; i < count; i++)
            arr[i] = value;

        size = count;
    }

    bool vector:: Empty() { return size == 0; }

    int  vector:: Size() { return this->size; }

    int  vector::Capacity() { return capacity; }

    void vector::ShrinkToFit()
    {
        if (size == 0)
        {
            capacity = 0;
            delete[] arr;
            arr = nullptr;
            return;
        }

        if (size == capacity) return;

        if (capacity > size)
        {
            int* newptr = new int[size] {};
            for (int i = 0; i < size; i++)
                newptr[i] = arr[i];

            delete[] arr;

            arr = newptr;
            capacity = size;

        }

    }

    void vector::clear() {

        size = 0;
        delete[] arr;
        capacity = 0;
        arr = nullptr;
    }

    void vector::Erase(int index)
    {
        if (index < 0 || index >= size) return;

        for (int i = index; i < size - 1; i++)
            arr[i] = arr[i + 1];
        size--;
    }

    void vector::PushBack(int val)
    {
        if (size == capacity)
        {
            int newCap = (capacity == 0) ? 1 : capacity * 2;
            Reserve(newCap);
        }
        arr[size++] = val;
    }

    void vector::PopBack()
    {
        if (size > 0) size--;
    }

    int  vector::At(int index) const
    {
        if (index < 0 || index >= size)
            return -1;

        return arr[index];
    }

    int  vector::Front()  const {

        return (size == 0) ? -1 : arr[0];
    }

    int   vector:: Back() const
    {

        return (size == 0) ? -1 : arr[size - 1];
    }

    void  vector:: Swap(vector& other)
    {
        vector temp = *this;
        *this = other;
        other = temp;
    }

    void vector:: Append_Range(const vector& other)
    {

        int SIZE = size + other.size;
        if (SIZE > capacity)
        {
            Reserve(SIZE);
        }


        for (int i = 0; i < other.size; i++)
            arr[size + i] = other.arr[i];
        size += other.size;
    }
    




//<==========================================================>
//             FRIEND FUNCTIIONS IMPLEMENTATION
//<==========================================================>

bool operator == (const vector& Lhs, const vector& Rhs)
{
    if (Lhs.size != Rhs.size) return false;

    for (int i = 0; i < Lhs.size; i++)
        if (Lhs.arr[i] != Rhs.arr[i]) return false;

    return true;

}

bool operator < (const vector& Lhs, const vector& Rhs)
{
    int MIN_SIZE = (Lhs.size < Rhs.size) ? Lhs.size : Rhs.size;


    for (int i = 0; i < MIN_SIZE; i++)
    {
        if (Lhs.arr[i] < Rhs.arr[i]) return true;
        if (Lhs.arr[i] > Rhs.arr[i]) return false;
    }

    return Lhs.size < Rhs.size;
}

bool operator != (const vector& Lhs, const vector& Rhs)
{
    return !(Lhs == Rhs);
}

bool operator > (const vector& Lhs, const vector& Rhs)
{
    return (Rhs < Lhs);
}

bool operator <= (const vector& Lhs, const vector& Rhs)
{
    return (Lhs < Rhs || Lhs == Rhs);
}

bool operator >= (const vector& Lhs, const vector& Rhs)
{
    return (Lhs > Rhs || Lhs == Rhs);
}

ostream& operator <<(ostream& out, const vector& v)
{
    for (int i = 0; i < v.size; i++)
        out << v.arr[i] << " ";
    return out;
}

istream& operator >>(istream& in, vector& v)
{
    for (int i = 0; i < v.capacity; i++)
        in >> v.arr[i], v.size++;


    return in;
}
