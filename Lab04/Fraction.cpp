
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

void Pause()
{

    cout << "Enter Any key to continue..." << endl;
    cin.ignore();
    cin.get();
}

class Fraction {
private:
    int numerator;
    int denominator;


public:

    Fraction()
    {
        numerator = 0;
        denominator = 1;
    }

    Fraction(int n, int d) : numerator(n) {
        if (d == 0)  denominator = 1;
        else denominator = d;
        simplification();
    }

    Fraction(Fraction const& other) {
        this->numerator = other.numerator;
        this->denominator = other.denominator;
    }

    Fraction(int value)
    {
        numerator = value;
        denominator = 1;
    }

    void set_values(int n, int d) {
        numerator = n;
        if (d == 0) denominator = 1;
        else denominator = d;
    }

    void print(const char msg[]) {
        cout << msg << numerator << "/" << denominator << endl;
    }

    friend ostream& operator << (ostream& out, Fraction& other);
    friend istream& operator >> (istream& in, Fraction& other);



    Fraction  operator+(const  Fraction& b) const {

        int n = (numerator * b.denominator) + (b.numerator * denominator);
        int d = (denominator * b.denominator);

        return  Fraction(n, d);


    }

    Fraction operator-(const  Fraction& b) const {
        int n = (numerator * b.denominator) - (b.numerator * denominator);
        int d = (denominator * b.denominator);
        return   Fraction(n, d);
    }

    Fraction operator*(const   Fraction& b) const {
        int n = (numerator * b.numerator);
        int d = (denominator * b.denominator);
        return Fraction(n, d);
    }


    Fraction operator+(int Scalar) const {

        Fraction a(Scalar);

        int n = a.numerator * this->denominator + this->numerator;
        int d = denominator;
        return Fraction(n, d);

    }


    Fraction operator/(const  Fraction& b) const {

        int n = (numerator * b.denominator);
        int d = (denominator * b.numerator);

        return Fraction(n, d);

    }

    void simplification() {
        if (numerator == 0) {

            denominator = 1;
            return;
        }
        int gcd = Gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;

        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
    }

    friend Fraction operator+(int value, Fraction const& f);


    Fraction& operator = (const Fraction& other) {
        if (this != &other) {
            numerator = other.numerator;
            denominator = other.denominator;
        }
        return *this;
    }
    bool operator != (Fraction& b) {
        simplification();
        b.simplification();
        if ((numerator != b.numerator) || (denominator != b.denominator))
            return true;

        else
            return false;

    }
    bool operator==(Fraction& b) {

        simplification();
        b.simplification();
        if ((numerator == b.numerator) && (denominator == b.denominator))
            return true;

        else
            return false;

    }
    bool operator<(const Fraction& other) const {
        return numerator * other.denominator <
            other.numerator * denominator;
    }

    bool operator > (const Fraction& other) const {
        return other < *this;
    }

    bool operator<=(const Fraction& other) const {
        return !(*this > other);
    }

    bool operator>=(const Fraction& other) const {
        return !(*this < other);
    }

    int lcm(int a, int b) {

        int i = (a > b) ? a : b;
        while (true) {
            if (i % a == 0 && i % b == 0)return i;
            i++;
        }


    }

    int Abs(int a, int b) {
        int product = a * b;
        return (product < 0) ? -product : product;
    }

    int Gcd(int a, int b) {

        return (Abs(a, b)) / (lcm(a, b));
    }

    int Abs(int a) {

        return (a < 0) ? -a : a;
    }

};

ostream& operator << (ostream& out, Fraction& other)
{
    out << other.numerator << "/" << other.denominator << endl;
    return out;
}

istream& operator >> (istream& in, Fraction& other)
{
    in >> other.numerator;
    in >> other.denominator;
    return in;
}

Fraction operator+(int value, Fraction const& f) {

    Fraction Result;
    Result.numerator = (value * f.denominator) + f.numerator;
    Result.denominator = f.denominator;
    return Result;


}

void Menu()
{
    cout << "\n<--------------------------- MENU ----------------------------->" << endl;
    cout << "0. Addition (int + fraction)" << endl;
    cout << "1. Addition (FRACTION + FRACTION or int)" << endl;
    cout << "2. Subtraction -" << endl;
    cout << "3. Multiply *" << endl;
    cout << "4. Divide /" << endl;
    cout << "5. Friend Function " << endl;
    cout << "6. Check Equality ==" << endl;
    cout << "7. Check not Equal !=" << endl;
    cout << "8. Check Greater >" << endl;
    cout << "9. Check Lower <" << endl;
    cout << "10. Check lesser than or equal to >=" << endl;
    cout << "11. Check greater than or equal to >=" << endl;
    cout << "12. Assignment =" << endl;
    cout << "13. Exit" << endl;
    cout << "<---------------------------------------------------------------->" << endl;

}


//============================  Main ============================

int main()
{




    int Choice = 0;

    int num = 0, den = 0, value = 0;
    Fraction a;
    Fraction b;
    Fraction Result;

    do {

        Menu();

        cout << "Choice: ";
        cin >> Choice;

        cout << endl;



        switch (Choice)
        {
        case 0:
            clearScreen();
            cout << " \nEnter the integer: ";
            cin >> value;
            cout << "\n        -= Enter First Fraction =- \n";
            cin >> a;
            Result = value + a;
            cout << "\nAddition of Two Fraction : ";
            cout << Result;
            Pause();
            break;
        case 1:
            clearScreen();

            cout << "\n        -= Enter First Fraction =-  \n";
            cin >> a;
            cout << "\n        -= Enter  Second  Fraction =-  \n";
            cin >> b;
            Result = a + b;
            cout << "\nAddition of Two Fraction : ";
            cout << Result;

            Pause();
            break;
        case 2:
            clearScreen();
            cout << "\n        -= Enter First Fraction =-  \n";
            cin >> a;
            cout << "\n        -= Enter  Second  Fraction =-  \n";
            cin >> b;
            Result = a - b;
            cout << "\nSubtraction of Two Fraction : ";
            cout << Result;

            Pause();
            break;

        case 3:
            clearScreen();
            cout << "\n        -= Enter First Fraction =-  \n";
            cin >> a;
            cout << "\n        -= Enter  Second  Fraction =-  \n";
            cin >> b;
            Result = a * b;
            cout << "\nThe Result : ";
            cout << Result;
            Pause();
            break;
        case 4:

            clearScreen();
            cout << "\n        -= Enter First Fraction =-  \n";
            cin >> a;
            cout << "\n        -= Enter  Second  Fraction =-  \n";
            cin >> b;
            Result = a / b;
            cout << "\nThe Result : ";
            cout << Result;
            Pause();
            break;
        case 5:
            clearScreen();
            cout << " \nEnter the integer: ";
            cin >> value;
            cout << "\n        -= Enter First Fraction =-  \n";
            cin >> a;
            Result = value + a;
            cout << "\nAddition of Two Fraction : ";
            cout << Result;
            Pause();
            break;
        case 6:
            clearScreen();
            cout << "\n        -= Enter First Fraction =-  \n";
            cin >> a;
            cout << "\n        -= Enter  Second  Fraction =-  \n";
            cin >> b;
            if (a == b)
            {
                cout << "Both are Equal" << endl;
            }
            else {
                cout << "Both are not Equal" << endl;
            }
            Pause();
            break;
        case 7:
            clearScreen();
            cout << "\n        -= Enter First Fraction =-  \n";
            cin >> a;
            cout << "\n        -= Enter  Second  Fraction =-  \n";
            cin >> b;
            if (a != b)
            {
                cout << "Both are not Equal" << endl;
            }
            else {
                cout << "Both are Equal" << endl;
            }
            Pause();
            break;
        case 8:
            clearScreen();
            cout << "\n        -= Enter First Fraction =-  \n";
            cin >> a;
            cout << "\n        -= Enter  Second  Fraction =-  \n";
            cin >> b;
            if (a > b)
            {
                a.print(" The Greater Fraction: ");
            }
            else {
                b.print(" The Greater Fraction: ");
            }
            Pause();
            break;
        case 9:
            clearScreen();
            cout << "\n        -= Enter First Fraction =-  \n";
            cin >> a;
            cout << "\n        -= Enter  Second  Fraction =-  \n";
            cin >> b;
            if (a < b)
            {
                a.print(" The Smaller Fraction: ");
            }
            else {
                b.print(" The Smaller Fraction: ");
            }
            Pause();
            break;

        case 10:
            clearScreen();
            cout << "\n        -= Enter First Fraction =-  \n";
            cin >> a;
            cout << "\n        -= Enter  Second  Fraction =-  \n";
            cin >> b;
            if (a <= b)
            {
                cout << "First Fraction is less then or equal to Second Fraction" << endl;
            }
            else {
                cout << "First Fraction is not less then or equal to Second Fraction" << endl;
            }
            Pause();
            break;

        case 11:
            clearScreen();
            cout << "\n        -= Enter First Fraction =-  \n";
            cin >> a;
            cout << "\n        -= Enter  Second  Fraction =-  \n";
            cin >> b;
            if (a >= b)
            {
                cout << "First Fraction is greater then or equal to Second Fraction" << endl;
            }
            else {
                cout << "First Fraction is not greater then or equal to Second Fraction" << endl;
            }
            Pause();
            break;
        case 12:
            clearScreen();
            cout << "\n        -= Enter First Fraction =-  \n";
            cin >> a;
            cout << "\n        -= Enter  Second  Fraction =-  \n";
            cin >> b;
            a = b;
            a.print("First Fraction: ");
            Pause();
            break;
        case 13:
            cout << "Exiting!" << endl;
            break;
        default:
            cout << "Faaaaaaaaaaaaaaaaaaaaaaah" << endl;
            break;

        }








    } while (Choice != 13);







}
