
#include <cmath>
#include <iostream>
using namespace std;

//<===================================================================>
//                     Functions Prototypes
//<====================================================================>

int lcm(int a, int b);

int Abs(int a, int b);

int Abs(int a);

int Gcd(int a, int b);

void pause() {
  cout << "Enter any key to continue" << endl;
  cin.ignore();
  cin.get();
}
void System_clear() {
#ifdef WIN32
  system("cls");
#else
  system("clear");
#endif
}
void task1();

void task2();

void task3();

void task4();

void task5();

//<===================================================================>
//                            Classes
//<====================================================================>
class Points {
private:
  int x;
  int y;

public:
  Points(int _x, int _y) : x(_x), y(_y) {}
  Points() {
    x = 0;
    y = 0;
  }

  Points add(Points a, Points b) {

    int _x = a.x + b.x;
    int _y = a.y + b.y;

    return Points(_x, _y);
  }

  Points diff(Points a, Points b) {

    int _x = a.x - b.x;
    int _y = a.y - b.y;

    return Points(_x, _y);
  }

  void Display() {
    cout << "The Point: " << "(" << this->x << "," << this->y << ")" << endl;
  }

  void origin(Points b) {

    float distance = sqrt(pow(this->x, 2) + pow(this->y, 2));
    float distance2 = sqrt(pow(b.x, 2) + pow(b.y, 2));

    cout << "POINT 1 DISTANCE: " << distance << endl;
    cout << "POINT 2 DISTANCE: " << distance2 << endl;
    if (distance > distance2)
      cout << "POINT 1 is farthest" << endl;
    else
      cout << "POINT 2 is the farthest " << endl;
  }
};

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

  void display() {
    cout << real;
    if (img >= 0)
      cout << " + " << img << "i" << endl;
    else
      cout << img << "i" << endl;
  }

  Complex Addition(Complex a, Complex b) {
    int R = a.real + b.real;
    int I = a.img + b.img;

    return Complex(R, I);
  }

  Complex Subtraction(Complex a, Complex b) {
    int R = a.real - b.real;
    int I = a.img - b.img;

    return Complex(R, I);
  }

  Complex Multiplication(Complex a, Complex b) {
    int R = (a.real * b.real) - (a.img * b.img);
    int I = (a.real * b.img) + (a.img * b.real);

    return Complex(R, I);
  }

  void Equality(Complex b) {

    if (real == b.real && img == b.img)
      cout << "Both Complex numbers are equal" << endl;

    else {
      cout << "They are not equal " << endl;
    }
  }
};

class Fraction {
private:
  int numerator;
  int denominator;

public:
  Fraction() {
    numerator = 1;
    denominator = 1;
  }

  Fraction(int n, int d) : numerator(n), denominator(d) {}

  void set_values(int n, int d) {
    numerator = n;
    if (d == 0)
      denominator = 1;
    else
      denominator = d;
  }

  void print() {
    cout << "\nThe fraction is : " << numerator << "/" << denominator << endl;
  }

  Fraction add(Fraction a, Fraction b) {

    int n = (a.numerator * b.denominator) + (b.numerator * a.denominator);
    int d = (a.denominator * b.denominator);

    return Fraction(n, d);
  }
  Fraction subtract(Fraction a, Fraction b) {
    int n = (a.numerator * b.denominator) - (b.numerator * a.denominator);
    int d = (a.denominator * b.denominator);
    return Fraction(n, d);
  }
  Fraction multiplication(Fraction a, Fraction b) {
    int n = (a.numerator * b.numerator);
    int d = (a.denominator * b.denominator);
    return Fraction(n, d);
  }

  Fraction Division(Fraction a, Fraction b) {
    if (b.numerator == 0) {
      cout << "The given Fractions cannot be divided because numerator of "
              "second fraction is zero"
           << endl;
      return Fraction(0, 1);
      ;
    }
    int n = (a.numerator * b.denominator);
    int d = (a.denominator * b.numerator);

    return Fraction(n, d);
  }
  void simplification() {
    if (numerator == 0) {
      denominator = 1;
      return;
    }
    int gcd = Gcd(numerator, denominator);
    numerator = numerator / gcd;
    denominator = denominator / gcd;
  }

  bool Equality(Fraction a, Fraction b) {

    a.simplification();
    b.simplification();
    if ((a.numerator == b.numerator) && (a.denominator == b.denominator))
      return true;

    else
      return false;
  }
};

class Dates {

private:
  int day = 0;
  int month = 0;
  int year = 0;

  bool is_month_valid(Dates a) {
    if (a.month < 1 || a.month > 12)
      return false;
    return true;
  }

  bool is_days_valid(Dates a) {
    switch (a.month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return (a.day >= 1 && a.day <= 31);
    case 4:
    case 6:
    case 9:
    case 11:
      return (a.day >= 1 && a.day <= 30);
    case 2:
      if (a.is_leap())
        return (a.day >= 1 && a.day <= 29);
      else
        return (a.day >= 1 && a.day <= 28);
    default:
      return false;
    }
  }

public:
  Dates() : day{0}, month{0}, year{0} {}

  Dates(int x, int y, int z) : day{x}, month{y}, year{z} {}

  void Display_Dates() {

    cout << day << " / " << month << " / " << year << endl;
  }

  bool is_leap() {

    if (year % 400 == 0)
      return true;
    else if (year % 100 == 0)
      return false;
    else if (year % 4 == 0)
      return true;
    else
      return false;
  }

  int Compare_date(Dates b) {
    if (year > b.year)
      return true;
    else if (year == b.year) {
      if (month > b.month)
        return true;
      else if (month == b.month) {
        if (day > b.day)
          return true;
        else if (day == b.day)
          return 2;
        return false;
      }
      return false;
    }
    return false;
  }

  int count_dates() {

    int Days = 0;

    Days = (year - 1) * 365;

    int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int leap = (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
    Days += leap;

    for (int i = 0; i < month - 1; i++) {
      Days += monthDays[i];
    }

    if (month > 2 && this->is_leap()) {
      Days += 1;
    }

    Days += day;

    return Days;
  }
};

class Employee {

private:
  int id;
  int salary;
  int hour;
  int bonus;
  int deductions;
  int netsalary = 0;
  float tax;
  int overtimepay;

public:
  Employee() : id(0), salary(0), hour(0), bonus(0), deductions(0) {}

  Employee(int a, int b, int c, int d, int e)
      : id{a}, salary{b}, hour{c}, bonus{d}, deductions{e} {}

  void Overtimepay() { overtimepay = hour * 500; }

  void Tax() {
    if (salary <= 50000)
      tax = (5 * salary) / 100;
    else if (salary <= 100000)
      tax = (10 * salary) / 100;
    else
      tax = (15 * salary) / 100;
  }

  void NetSalary() {
    netsalary = (salary - deductions - tax) + overtimepay + bonus;
  }

  void display() {
    cout << "\n<==============================================================="
            "=====================>"
         << endl;
    cout << "                                Employee Details " << endl;
    cout << "<================================================================="
            "===================>"
         << endl;

    cout << "Employee id: " << id;
    cout << "\nSalary: " << salary;
    cout << "\nOvertime (H)ours: " << hour;
    cout << "\nBonus: " << bonus;
    cout << "\nDeductions: " << deductions;
    cout << "\nTax: " << tax;
    cout << "\nOvertime Pay: " << overtimepay;
    cout << "\nNet SALARY: " << netsalary << endl;

    cout << "<================================================================="
            "===================>"
         << endl;
  }
};

void menu() {

  cout << "\n<===========================================>" << endl;
  cout << "1. Points" << endl;
  cout << "2. Complex" << endl;
  cout << "3. Fraction" << endl;
  cout << "4. Dates" << endl;
  cout << "5. Employee" << endl;
  cout << "6.exit" << endl;
  cout << "<===========================================>" << endl;
}

//<===================================================================>
//                            Main
//<====================================================================>

int main() {
  int choice = 0;
  do {
    menu();
    cout << "Choice: ";
    cin >> choice;
    cout << endl;

    switch (choice) {

    case 1:
      System_clear();
      task1();
      pause();
      break;

    case 2:
      System_clear();
      task2();
      pause();
      break;

    case 3:
      System_clear();
      task3();
      pause();
      break;

    case 4:
      System_clear();
      task4();
      pause();
      break;

    case 5:
      System_clear();
      task5();
      pause();
      break;
    default:
      cout << "Invalid Choice" << endl;
    }
  } while (choice != 6);
}

//<===================================================================>
//                          Functions
//<====================================================================>

int Abs(int a) { return (a < 0) ? -a : a; }

int lcm(int a, int b) {

  int i = (a > b) ? a : b;
  while (true) {
    if (i % a == 0 && i % b == 0)
      return i;
    i++;
  }
}

int Abs(int a, int b) {
  int product = a * b;
  return (product < 0) ? -product : product;
}

int Gcd(int a, int b) { return (Abs(a, b)) / (lcm(a, b)); }

void task1() {
  cout << "Enter x and y component of first point: ";
  int c, d;
  cin >> c >> d;
  cout << endl;
  Points one(c, d);
  cout << "Enter x and y component of second point: ";
  cin >> c >> d;
  Points two(c, d);
  cout << endl;

  Points result = one.add(two, one);
  result.Display();

  Points sub = one.diff(one, two);
  sub.Display();

  one.origin(two);
}

void task2() {
  cout << "Enter real and imaginary component of first complex numbers: ";
  int c, d;
  cin >> c >> d;
  cout << endl;
  Complex one(c, d);
  cout << "Enter real and imaginary component of second complex numbers: ";
  cin >> c >> d;
  Complex two(c, d);
  cout << endl;

  Complex result = one.Addition(one, two);
  cout << "The Addition: ";
  result.display();
  cout << endl;

  Complex sub = one.Subtraction(one, two);
  cout << "The Subtraction: ";
  sub.display();
  cout << endl;

  Complex mul = one.Multiplication(one, two);
  cout << "The Multiplication: ";
  mul.display();
  cout << endl;

  cout << "Checking Equlaity: " << endl;

  one.Equality(two);
}

void task3() {
  cout << "Creating two fractions" << endl;

  int n = 0, d = 0;
  cout << "Enter numerator and denominator: ";
  cin >> n >> d;
  cout << endl;

  Fraction one(n, d);

  cout << "Enter numerator and denominator: ";
  cin >> n >> d;
  cout << endl;

  Fraction two(n, d);

  cout << "Displaying Fractions" << endl;
  one.print();
  two.print();

  cout << "Simplification" << endl;

  one.simplification();
  one.print();
  two.simplification();
  two.print();

  cout << "Addition: ";
  Fraction add_res = one.add(one, two);
  cout << "\nBefore Simplification: ";
  add_res.print();
  cout << "\nSimplification" << endl;
  add_res.simplification();
  add_res.print();

  cout << "\nSubtraction: ";
  Fraction sub_res = one.subtract(one, two);
  cout << "\nBefore Simplification: ";
  sub_res.print();
  cout << "\nSimplification" << endl;
  sub_res.simplification();
  sub_res.print();

  cout << "\nMultiplication: " << endl;
  Fraction mul_res = one.multiplication(one, two);
  cout << "\nBefore Simplification: ";
  mul_res.print();
  cout << "\nSimplification" << endl;
  mul_res.simplification();
  mul_res.print();

  cout << "\nDivision: " << endl;
  Fraction div_res = one.Division(one, two);
  cout << "\nBefore Simplification: ";
  div_res.print();
  cout << "\nSimplification" << endl;
  div_res.simplification();
  div_res.print();

  cout << "The Equality of two  fractions" << endl;
  if (one.Equality(one, two)) {
    cout << "They are equal" << endl;
  } else {
    cout << "They are not equal" << endl;
  }
}

void task4() {
  cout << "Enter first date Date/Month/Year" << endl;
  int a, b, c;
  cin >> a >> b >> c;
  Dates one(a, b, c);

  cout << "Enter seconf date Date/Month/Year" << endl;

  cin >> a >> b >> c;
  Dates two(a, b, c);

  one.Display_Dates();
  two.Display_Dates();

  if (one.is_leap())
    cout << "it is leap year" << endl;
  else
    cout << "it is not a leap year" << endl;

  if (two.is_leap())
    cout << "it is leap year" << endl;
  else
    cout << "it is not a leap year" << endl;

  cout << "The days between two days: ";
  cout << Abs(one.count_dates() - two.count_dates());
}

void task5() {
  cout << "Enter Details of Employee (id) (salary) (hours) (bonus) "
          "(deductions): ";
  int a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  Employee hadi(a, b, c, d, e);
  cout << endl;

  hadi.Overtimepay();
  hadi.Tax();
  hadi.NetSalary();
  hadi.display();
}
