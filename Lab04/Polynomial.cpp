#include <iostream>
#include <cstdlib>
#include <cmath>
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

class Polynomial
{
private:
	int* coeffs;
	int* power;
	int size;
public:

	//<=============================== Constructors  ==============================>
	Polynomial()
	{

		coeffs = nullptr;
		size = 0;
		power = nullptr;

	}

	Polynomial(int Size) : size(Size)
	{

		coeffs = new int[Size] {};
		power = new int [Size] {};

	}

	Polynomial(const Polynomial& other) {

		this->size = other.size;
		delete[] coeffs;
		delete[]power;
		this->coeffs = new int[this->size] {};
		this->power = new int[this->size] {};

		for (int i = 0; i < other.size; i++)
			this->coeffs[i] = other.coeffs[i], this->power[i] = other.power[i];

	}

	//<=============================== Destructors ==============================>
	~Polynomial() {
		delete[] coeffs;
		delete[] power;
	}

	//<================================= Methods ==============================>

	void Set_value(int index, int coeffecint, int exponent)
	{
		coeffs[index] = coeffecint;
		power[index] = exponent;
	}

	void Print(const char msg[])
	{
		cout << msg << " [ ";
		for (int i = 0; i < size; i++)
		{
			if (coeffs[i] >= 0 && i != 0)
			{
				cout << "+ ";
			}
			cout << coeffs[i];

			cout << "x^";
			cout << power[i];


			cout << " ";

		}
		cout << "]" << endl;
	}

	void Regrow()
	{
		int* newCoeffs = new int[size + 1];
		int* newPower = new int[size + 1];

		for (int i = 0; i < size; i++)
		{
			newCoeffs[i] = coeffs[i];
			newPower[i] = power[i];
		}

		delete[] coeffs;
		delete[] power;

		coeffs = newCoeffs;
		power = newPower;

		size++;
	}

	void Shrink(int index)
	{
		int* newCoeffs = new int[size - 1];
		int* newPower = new int[size - 1];

		for (int i = 0; i < size; i++)
		{
			if (i == index)
			{
				continue;
			}
			if (i < index)
			{
				newCoeffs[i] = coeffs[i];
				newPower[i] = power[i];
			}
			if (i > index)
			{
				newCoeffs[i - 1] = coeffs[i];
				newPower[i - 1] = power[i];
			}

		}

		delete[] coeffs;
		delete[] power;

		coeffs = newCoeffs;
		power = newPower;

		size--;
	}

	void remove_duplicate()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (power[i] == power[j])
				{
					coeffs[i] += coeffs[j];
					Shrink(j);
					j--;
				}
			}

			if (coeffs[i] == 0)
			{
				Shrink(i);
				i--;
			}
		}




	}


	Polynomial& operator =(const Polynomial& other)
	{
		if (this == &other) return *this;

		delete[] coeffs;
		delete[] power;

		size = other.size;
		coeffs = new int[size]();
		power = new int[size]();

		for (int i = 0; i < size; i++) {
			coeffs[i] = other.coeffs[i];
			power[i] = other.power[i];
		}

		return *this;
	}

	Polynomial  operator * (const Polynomial& b)const
	{


		Polynomial result(size * b.size);


		int l = 0;

		for (int i = 0; i < size; i++)
		{

			for (int j = 0; j < b.size; j++)
			{

				result.coeffs[l] = coeffs[i] * b.coeffs[j];
				result.power[l] = power[i] + b.power[j];
				l++;

			}


		}
		result.remove_duplicate();
		return result;
	}

	Polynomial operator +(const Polynomial& b)const
	{


		Polynomial result(*this);

		for (int i = 0; i < b.size; i++)
		{
			bool found = false;


			for (int j = 0; j < result.size; j++)
			{
				if (result.power[j] == b.power[i])
				{
					result.coeffs[j] += b.coeffs[i];
					found = true;
					break;
				}
			}


			if (!found)
			{
				result.Regrow();
				result.coeffs[result.size - 1] = b.coeffs[i];
				result.power[result.size - 1] = b.power[i];
			}
		}

		return result;
	}

	Polynomial operator - (const Polynomial& b)const
	{


		Polynomial result(*this);

		for (int i = 0; i < b.size; i++)
		{
			bool found = false;


			for (int j = 0; j < result.size; j++)
			{
				if (result.power[j] == b.power[i])
				{
					result.coeffs[j] -= b.coeffs[i];
					found = true;
					break;
				}
			}


			if (!found)
			{
				result.Regrow();
				result.coeffs[result.size - 1] = b.coeffs[i];
				result.power[result.size - 1] = b.power[i];
			}
		}

		return result;
	}


	Polynomial Differentiate()const
	{


		Polynomial result(*this);

		for (int i = 0; i < size; i++)
		{
			if (power[i] == 0)
			{
				result.coeffs[i] = 0;
				continue;
			}

			result.coeffs[i] *= power[i];
			result.power[i] -= 1;



		}

		return result;
	}

	Polynomial Integration()const
	{


		Polynomial result(*this);

		for (int i = 0; i < size; i++)
		{
			result.coeffs[i] /= (result.power[i] + 1);
			result.power[i] += 1;
		}

		return result;
	}

	bool operator == (const Polynomial& b) const
	{
		if (size != b.size) return false;


		for (int i = 0; i < size; i++)
		{
			if (coeffs[i] != b.coeffs[i]) return false;
			if (power[i] != b.power[i])return false;
		}

		return true;

	}

	bool operator != (const Polynomial& b) const
	{
		if (size != b.size) return true;


		for (int i = 0; i < size; i++)
		{
			if (coeffs[i] != b.coeffs[i]) return true;
			if (power[i] != b.power[i])return true;
		}

		return false;

	}

	friend ostream& operator << (ostream& out, const Polynomial& a);
	friend istream& operator >> (istream& in, Polynomial& a);

	int evaluate(int x) const {

		int result = 0;

		for (int i = 0; i < size; i++)
		{
			int temp = (pow(x, power[i])) * coeffs[i];
			result += temp;
		}

		return result;

	}



};

ostream& operator << (ostream& out, const Polynomial& a)
{
	out << " [ ";
	for (int i = 0; i < a.size; i++)
	{
		if (a.coeffs[i] >= 0 && i != 0)
		{
			out << "+ ";
		}
		out << a.coeffs[i];

		out << "x^";
		out << a.power[i];


		out << " ";

	}
	out << "]" << endl;

	return out;
}

istream& operator >> (istream& in, Polynomial& a)
{
	int num = 0, exp = 0;
	for (int i = 0; i < a.size; i++)
	{
		cout << "Enter coeffeicent and power: ";
		in >> num >> exp;


		a.coeffs[i] = num;
		a.power[i] = exp;

	}
	a.remove_duplicate();

	return in;

}

void Menu()
{
	cout << "<----------------------------------------->" << endl;
	cout << "-                 Menu                    -" << endl;
	cout << "<----------------------------------------->" << endl;
	cout << "1. Addition         (A + B)" << endl;
	cout << "2. Subtraction      (A - B)" << endl;
	cout << "3. Multiplication   (A * B)" << endl;
	cout << "4. Evaluate         (A at x)" << endl;
	cout << "5. Differentiate    (A')" << endl;
	cout << "6. Integrate        (Integral of A)" << endl;
	cout << "7. Compare          (A == B)" << endl;
	cout << "8. Exit" << endl;
	cout << "<----------------------------------------->" << endl;
}


int main()
{
	int choice = 0;
	Polynomial a, b, Result;

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
			int size1, size2;
			cout << "Enter number of terms in Polynomial A: ";
			cin >> size1;
			a = Polynomial(size1);
			cin >> a;
			cout << "Polynomial A: " << a;

			cout << "Enter number of terms in Polynomial B: ";
			cin >> size2;
			b = Polynomial(size2);
			cin >> b;
			cout << "Polynomial B: " << b;

			Result = a + b;
			cout << "Result (A + B): " << Result;
			break;
		}

		case 2:
		{
			clearScreen();
			int size1, size2;
			cout << "Enter number of terms in Polynomial A: ";
			cin >> size1;
			a = Polynomial(size1);
			cin >> a;
			cout << "Polynomial A: " << a;

			cout << "Enter number of terms in Polynomial B: ";
			cin >> size2;
			b = Polynomial(size2);
			cin >> b;
			cout << "Polynomial B: " << b;

			Result = a - b;
			cout << "Result (A - B): " << Result;
			break;
		}

		case 3:
		{
			clearScreen();
			int size1, size2;
			cout << "Enter number of terms in Polynomial A: ";
			cin >> size1;
			a = Polynomial(size1);
			cin >> a;
			cout << "Polynomial A: " << a;

			cout << "Enter number of terms in Polynomial B: ";
			cin >> size2;
			b = Polynomial(size2);
			cin >> b;
			cout << "Polynomial B: " << b;

			Result = a * b;
			cout << "Result (A * B): " << Result;
			break;
		}

		case 4:
		{
			clearScreen();
			int size1, x;
			cout << "Enter number of terms in Polynomial A: ";
			cin >> size1;
			a = Polynomial(size1);
			cin >> a;
			cout << "Polynomial A: " << a;

			cout << "Enter value of x: ";
			cin >> x;
			cout << "A evaluated at x = " << x << " : " << a.evaluate(x) << endl;
			break;
		}

		case 5:
		{
			clearScreen();
			int size1;
			cout << "Enter number of terms in Polynomial A: ";
			cin >> size1;
			a = Polynomial(size1);
			cin >> a;
			cout << "Polynomial A:  " << a;

			Result = a.Differentiate();
			cout << "Derivative A': " << Result;
			break;
		}

		case 6:
		{
			clearScreen();
			int size1;
			cout << "Enter number of terms in Polynomial A: ";
			cin >> size1;
			a = Polynomial(size1);
			cin >> a;
			cout << "Polynomial A:   " << a;

			Result = a.Integration();
			cout << "Integral of A:  " << Result;
			cout << "+ C " << endl;
			break;
		}

		case 7:
		{
			clearScreen();
			int size1, size2;
			cout << "Enter number of terms in Polynomial A: ";
			cin >> size1;
			a = Polynomial(size1);
			cin >> a;
			cout << "Polynomial A: " << a;

			cout << "Enter number of terms in Polynomial B: ";
			cin >> size2;
			b = Polynomial(size2);
			cin >> b;
			cout << "Polynomial B: " << b;

			if (a == b)
				cout << "Result: A and B are EQUAL" << endl;
			else
				cout << "Result: A and B are NOT equal" << endl;
			break;
		}

		case 8:
		{
			cout << "Exiting!" << endl;
			break;
		}

		default:
			cout << "Invalid choice! Please enter 1-8." << endl;
		}

		if (choice != 8)
		{
			cout << "\nPress Enter to continue...";
			cin.ignore();
			cin.get();
			clearScreen();
		}

	} while (choice != 8);

	return 0;
}