#include <iostream>
#include <cstdlib>
using namespace std;

// Cross-platform screen clear (Windows: cls, Linux/macOS: clear)
void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

class Complex {
private:
    int real;
    int img;
public:
    Complex() {
        real = 0;
        img = 0;
    }

    Complex(int a, int b) : real(a), img(b) {}

    Complex(const Complex& other) : real(other.real), img(other.img) {}

    Complex& operator =(const Complex& other) {
        if (this == &other) return *this;
        real = other.real;
        img = other.img;
        return *this;
    }

    Complex operator +(const Complex& b) const {
        return Complex(real + b.real, img + b.img);
    }

    Complex operator -(const Complex& b) const {
        return Complex(real - b.real, img - b.img);
    }

    Complex operator *(const Complex& b) const {
        int R = (real * b.real) - (img * b.img);
        int I = (real * b.img) + (img * b.real);
        return Complex(R, I);
    }

    bool operator ==(const Complex& b) const {
        return (real == b.real && img == b.img);
    }

    bool operator !=(const Complex& b) const {
        return !(real == b.real && img == b.img);
    }

    friend ostream& operator<<(ostream& out, const Complex& a);
    friend istream& operator>>(istream& in, Complex& a);
};

ostream& operator<<(ostream& out, const Complex& a)
{
    out << a.real;
    if (a.img >= 0)
        out << " + " << a.img << "i";
    else
        out << " - " << abs(a.img) << "i";   // ✅ cleaner: shows "3 - 2i" not "3-2i"
    out << endl;
    return out;
}

istream& operator>>(istream& in, Complex& a)
{
    cout << "  Real part: ";
    in >> a.real;
    cout << "  Imaginary part: ";
    in >> a.img;
    return in;
}

void Menu()
{
    cout << "<----------------------------------------->" << endl;
    cout << "-            Complex Numbers              -" << endl;
    cout << "<----------------------------------------->" << endl;
    cout << "1. Addition         (A + B)" << endl;
    cout << "2. Subtraction      (A - B)" << endl;
    cout << "3. Multiplication   (A * B)" << endl;
    cout << "4. Compare          (A == B)" << endl;
    cout << "5. Exit" << endl;
    cout << "<----------------------------------------->" << endl;
}

int main()
{
    int choice = 0;
    Complex a, b, Result;

    do
    {
        Menu();
        cout << "Choice: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
        {
            clearScreen();
            cout << "Enter Complex Number A:" << endl;
            cin >> a;
            cout << "Enter Complex Number B:" << endl;
            cin >> b;

            cout << "\nA: " << a;
            cout << "B: " << b;

            Result = a + b;
            cout << "Result (A + B): " << Result;
            break;
        }

        case 2:
        {
            clearScreen();
            cout << "Enter Complex Number A:" << endl;
            cin >> a;
            cout << "Enter Complex Number B:" << endl;
            cin >> b;

            cout << "\nA: " << a;
            cout << "B: " << b;

            Result = a - b;
            cout << "Result (A - B): " << Result;
            break;
        }

        case 3:
        {
            clearScreen();
            cout << "Enter Complex Number A:" << endl;
            cin >> a;
            cout << "Enter Complex Number B:" << endl;
            cin >> b;

            cout << "\nA: " << a;
            cout << "B: " << b;

            Result = a * b;
            cout << "Result (A * B): " << Result;
            break;
        }

        case 4:
        {
            clearScreen();
            cout << "Enter Complex Number A:" << endl;
            cin >> a;
            cout << "Enter Complex Number B:" << endl;
            cin >> b;

            cout << "\nA: " << a;
            cout << "B: " << b;

            if (a == b)
                cout << "Result: A and B are EQUAL" << endl;
            else
                cout << "Result: A and B are NOT equal" << endl;
            break;
        }

        case 5:
        {
            cout << "Exiting!" << endl;
            break;
        }

        default:
            cout << "Invalid choice! Please enter 1-5." << endl;
        }

        if (choice != 5)
        {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
            clearScreen();
        }

    } while (choice != 5);

    return 0;
}