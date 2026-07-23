#include <iostream>
#include <cstdlib>
using namespace std;

void clear_screen()
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
	int* coeffs ;
	int* power ;
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

		coeffs = new int[Size]{};
		power = new int [Size] {};

	}

	Polynomial(const Polynomial& other) {

	this->size = other.size;
	this->coeffs = new int[this->size] {};
	this->power = new int[this->size] {};

	for (int i = 0; i < other.size; i++)
		this->coeffs[i] = other.coeffs[i], this->power[i] = other.power[i];

	}
	Polynomial& operator=(const Polynomial& other)
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
		cout << "]"<< endl;
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
				newCoeffs[i-1] = coeffs[i];
				newPower[i-1] = power[i];
			}

		}

		delete[] coeffs;
		delete[] power;

		coeffs = newCoeffs;
		power = newPower;

		size--;
	}


	int find_same_power(int target, Polynomial& const b) const
	{

		for (int i = 0; i < b.size; i++)
		{
			if (b.power[i] == target)
				return i;
		}

		return -1;



	}

	void remove_duplicate()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = i+1; j < size; j++)
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



	Polynomial add(const Polynomial& a, const Polynomial& b)
	{
		

		Polynomial result(a);   

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





	Polynomial subtract(const Polynomial& a, const Polynomial& b)
	{


		Polynomial result(a);

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

	int evaluate(int x) const {

		int result = 0;

		for (int i = 0; i < size; i++)
		{
			int temp = (pow(x, power[i])) * coeffs[i];
			result += temp;
		}

		return result;

	}

	Polynomial multiply(const Polynomial& a, const Polynomial& b)
	{


		Polynomial result(a.size*b.size);
	
		
		int l = 0;

		for (int i = 0; i < a.size; i++)
		{

			for (int j = 0; j < b.size; j++)
			{

				result.coeffs[l] = a.coeffs[i] * b.coeffs[j];
				result.power[l] = a.power[i] + b.power[j];
				l++;

			}
		

		}
		result.remove_duplicate();
		return result;
	}



};


void Menu()
{
	cout << "<----------------------------------------->" << endl;
	cout << "-                 Menu                    -" << endl;
	cout << "<----------------------------------------->" << endl;
	cout << "1. Addition" << endl;
	cout << "2. Subtraction" << endl;
	cout << "3. Multiply" << endl;
	cout << "4. Evaluate" << endl;
	cout << "5. Exiting" << endl;
	cout << "<----------------------------------------->" << endl;
}

int main()
{

	int choice = 0;



	int num, exp;
	int Size;
	int size2;

	cout << "Enter the Size of Polynomial A: ";
	cin >> Size;
	cout << endl;

	Polynomial Result;

	Polynomial a(Size);
	//============================== A polynomial ==============================
	for (int i = 0; i < Size; i++)
	{
		cout << "Enter coeffeicent and power: ";
		cin >> num >> exp;
		cout << endl;
		a.Set_value(i, num, exp);

	}
	a.remove_duplicate();
	a.Print("A polynomial: ");

	
	//============================== B polynomial ==============================
	cout << "Enter the Size of Polynomial B: ";
	cin >> size2;
	cout << endl;
	Polynomial b(size2);
	for (int i = 0; i < size2; i++)
	{
		cout << "Enter coeffeicent and power: ";
		cin >> num >> exp;
		cout << endl;
		b.Set_value(i, num, exp);

	}
	b.remove_duplicate();
	b.Print("B polynomial: ");


	do {
	
		Menu();

		cout << "Choice: ";
		cin >> choice;
		cout << endl;




		switch (choice)
		{

		case 1:
			clear_screen();
			a.Print("A polynomial: ");
			b.Print("B polynomial: ");
		    Result = a.add(a, b);
			Result.Print("Addition of two polynomials: ");
			break;

		case 2:
			clear_screen();
			a.Print("A polynomial: ");
			b.Print("B polynomial: ");
	        Result = a.subtract(a, b);
			Result.Print("Subtraction of two polynomials: ");
			break;

		case 3:
			clear_screen();
			a.Print("A polynomial: ");
			b.Print("B polynomial: ");
		    Result = a.multiply(a, b);
			Result.Print("Multiplication of two polynomials: ");
			break;

		case 4:
			clear_screen();
			a.Print("A polynomial: ");
			b.Print("B polynomial: ");
			cout << "Enter the evaulater: ";
            int x;
            cin >> x;
			cout << "Evaluate a or b:  " << endl;
			char A;
			cin >> A;
			if (A == 'a')
				cout << a.evaluate(x)<<endl;
			else
				cout << b.evaluate(x);
			break;

		case 5:
			cout << "Exiting!" << endl;
		

			break;
		default:
			cout << "Invalid Choice !" << endl;


		}

	
	
	
	
	
	
	} while (choice != 5);



	return 0;



}


