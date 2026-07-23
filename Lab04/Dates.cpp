#include <iostream>
#include <cstdlib>

// Cross-platform screen clear (Windows: cls, Linux/macOS: clear)
void clearScreen()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

class Date
{
	int day;
	int mon;
	int year;
public:
	Date()
	{
		day = 1;
		mon = 1;
		year = 2000;
	}
	bool check_leap(int ye)
	{
		if (ye % 4 == 0 && ye % 100 != 0)
		{
			return true;
		}
		else if (ye % 400 == 0)
		{
			return true;
		}
		else
			return false;
	}
	Date(int d, int m, int y)
	{
		day = d;
		mon = m;
		year = y;
	}
	void input()
	{
		int d, m, y;
		int is_val;
		int leep;
		while (true)
		{
			while (true)
			{
				std::cout << "Enter The Day: ";
				std::cin >> d;
				if (d > 0 && d < 32)
				{
					break;
					is_val = 1;
				}
				else
				{
					printf("Invalid Date , Try Again");
				}
			}

			while (true)
			{
				std::cout << "Enter The Month: ";
				std::cin >> m;
				if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && d > 31)
				{
					std::cout << "Invalid Date , Try Again \n";
					is_val = 0;
					break;
				}
				else if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
				{
					std::cout << "Invalid Date , Try Again \n";
					is_val = 0;
					break;
				}
				if (m > 0 && m < 13)
				{
					is_val = 1;
					break;

				}
			}
			if (is_val == 1)
			{
				while (true)
				{
					std::cout << "Enter The Year: ";
					std::cin >> y;
					if ((y % 400 == 0) || (y % 100 != 0 && y % 4 == 0))
					{
						leep = 1;
					}
					else {
						leep = 0;
					}
					if (y < 0)
					{
						std::cout << "Invalid Selection of Year, Try Again \n";
						is_val = 0;
						break;
					}
					if (leep == 1 && m == 2 && d > 29)
					{
						std::cout << "Invalid Selection Of Date. Try Again \n";
						is_val = 0;
						break;
					}
					else if (leep == 0 && m == 2 && d > 28)
					{
						std::cout << "Invalid Selection Of Date. Try Again \n";
						is_val = 0;
						break;
					}
					is_val = 1;
					break;
				}
			}
			if (is_val == 1)
			{
				break;
			}
		}
		year = y;
		mon = m;
		day = d;
	}
	void display()
	{
		std::cout << day << " - " << mon << " - " << year << "\n";
	}
	Date operator - (Date d_2)
	{
		{
			int d, m, y;
			if (day >= d_2.day)
			{
				d = day - d_2.day;
			}
			else
			{
				mon = mon - 1;
				if (mon != 0)
				{
					if (mon == 1 || mon == 3 || mon == 5 || mon == 7 || mon == 8 || mon == 10 || mon == 12)
					{
						d = day + 31 - d_2.day;
					}
					if (mon == 4 || mon == 6 || mon == 9 || mon == 11)
					{
						d = day + 30 - d_2.day;
					}
					if (mon == 2)
					{
						if (check_leap(year) == 1)
						{
							d = day + 29 - d_2.day;
						}
						else
						{
							d = day + 28 - d_2.day;
						}
					}
				}
				else
				{
					year = year - 1;
					mon = mon + 12;
					d = day + 31 - d_2.day;
				}
			}
			if (mon >= d_2.mon)
			{
				m = mon - d_2.mon;
			}
			else
			{
				year = year - 1;
				mon = mon + 12;
				m = mon - d_2.mon;
			}
			y = year - d_2.year;
			Date dif(d, m, y);
			return dif;
		}
	}
	bool operator > (const Date& d)
	{
		if (d.year > year)
		{
			return true;
		}
		if (d.year < year)
			return false;
		else
		{
			if (d.mon > mon)
				return true;

			if (d.mon < mon)
				return false;

			else
			{
				if (d.day > day)
					return true;
				else
					return false;
			}
		}
	}
	bool operator < (const Date& d)
	{
		if (d.year < year)
		{
			return true;
		}
		if (d.year > year)
			return false;
		else
		{
			if (d.mon < mon)
				return true;

			if (d.mon > mon)
				return false;

			else
			{
				if (d.day < day)
					return true;
				else
					return false;
			}
		}
	}
	bool operator == (const Date& d)
	{
		if (d.day == day && d.mon == mon && d.year == year)
		{
			return true;
		}
		else
			return false;
	}
	bool operator <= (const Date& d)
	{
		if (d.year > year)
		{
			return true;
		}
		if (d.year < year)
			return false;
		else
		{
			if (d.mon > mon)
				return true;

			if (d.mon < mon)
				return false;

			else
			{
				if (d.day > day)
					return true;
				else if (d.day < day)
					return false;
				else
				{
					return true;
				}
			}
		}
	}
	bool operator >= (const Date& d)
	{
		if (d.year < year)
		{
			return true;
		}
		if (d.year > year)
			return false;
		else
		{
			if (d.mon < mon)
				return true;

			if (d.mon > mon)
				return false;

			else
			{
				if (d.day < day)
					return true;
				else if (d.day > day)
					return false;
				else
				{
					return true;
				}
			}
		}
	}
	bool operator != (const Date& d)
	{
		if (d.day == day && d.mon == mon && d.year == year)
		{
			return false;
		}
		else
			return true;
	}
	Date operator + (const Date& d)
	{
		int da = 0, m = 0, y = 0;
		y = year + d.year;

		if ((mon + d.mon) > 12)
		{
			y = y + 1;
		}
		m = mon + d.mon;
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		{
			if ((day + d.day) > 31)
			{
				m = m + 1;
			}
			da = d.day + day;
		}
		else if (m != 2)
		{
			if ((day + d.day) > 30)
			{
				m = m + 1;
			}
			da = d.day + day;
		}
		else if (m == 2 && check_leap(y))
		{
			if ((day + d.day) > 29)
			{
				m = m + 1;
			}
			da = d.day + day;
		}
		else if (m == 2 && !check_leap(y))
		{
			if ((day + d.day) > 28)
			{
				m = m + 1;
			}
			da = d.day + day;
		}
		Date res(da, m, y);
		return res;
	}
	Date& operator = (const Date& d)
	{
		if (this != &d)
		{
			day = d.day;
			mon = d.mon;
			year = d.year;
		}
		return *(this);
	}
};
int main()
{
	Date d1;
	std::cout << "Enter The Date D1\n";
	d1.input();
	Date d2;
	std::cout << "Enter The Date D2\n";
	d2.input();
	std::cout << "Date 1\n";
	d1.display();
	std::cout << "Date 2 \n";
	d2.display();
	int choice = 0;
	while (true)
	{
		std::cout << "1 - Add Dates\n";
		std::cout << "2 - Substract Dates\n";
		std::cout << "3 - Check D1 > D2\n";
		std::cout << "4 - Check D1 < D2\n";
		std::cout << "5 - Check D1 >= D2\n";
		std::cout << "6 - Check D1 <= D2\n";
		std::cout << "7 - Assign D1 = D2\n";
		std::cout << "8 - Check if D1 == D2\n";
		std::cout << "9 - Check if D1 != D2\n";
		std::cout << "-1 - Exit\n";
		std::cout << "Your Choice: ";
		std::cin >> choice;
		clearScreen();
		if (choice == -1)
			return 0;
		if (choice == 1)
		{
			Date res;
			res = d1 + d2;
			res.display();
		}
		if (choice == 2)
		{
			Date res;
			res = d1 - d2;
			res.display();
		}
		if (choice == 3)
		{
			if (d1 > d2)
			{
				std::cout << "True\n";
			}
			else
			{
				std::cout << "False\n";
			}
		}
		if (choice == 4)
		{
			if (d1 < d2)
			{
				std::cout << "True\n";
			}
			else
			{
				std::cout << "False\n";
			}
		}
		if (choice == 5)
		{
			if (d1 >= d2)
			{
				std::cout << "True\n";
			}
			else
			{
				std::cout << "False\n";
			}
		}
		if (choice == 6)
		{
			if (d1 <= d2)
			{
				std::cout << "True\n";
			}
			else
			{
				std::cout << "False\n";
			}
		}
		if (choice == 7)
		{
			d1 = d2;
			std::cout << "D2 Is Assigned To D1\n";
			d1.display();
		}
		if (choice == 8)
		{
			if (d1 == d2)
			{
				std::cout << "true\n";
			}
			else
			{
				std::cout << "False\n";
			}
		}
		if (choice == 9)
		{
			if (d1 != d2)
			{
				std::cout << "true\n";
			}
			else
			{
				std::cout << "False\n";
			}
		}
	}
}