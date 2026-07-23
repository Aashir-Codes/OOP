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

class Time
{
	int hour;
	int min;
	int sec;
public:
	Time()
	{
		hour = 0;
		min = 0;
		sec = 0;
	}
	Time(int h, int m, int s)
	{
		hour = h;
		min = m;
		sec = s;
	}
	void input()
	{
		int m = 0, h = 0, s = 0;

		std::cout << "Enter The Hour: ";
		std::cin >> h;

		std::cout << "Enter The Minutes: ";
		std::cin >> m;
		if (m > 59)
		{
			while (m > 59)
			{
				m = m - 59;
				h = h + 1;
			}
		}

		std::cout << "Enter The Seconds: ";
		std::cin >> s;

		if (s > 59)
		{
			while (s > 59)
			{
				s = s - 59;
				m = m + 1;
			}
			if (m > 59)
			{
				m = m - 59;
				h = h + 1;
			}
		}
		min = m;
		hour = h;
		sec = s;
		if (min < 0)
			min = min * -1;
		if (sec < 0)
			sec = sec * -1;
		if (hour < 0)
			hour = hour * -1;
	}
	void display()
	{
		std::cout << hour << " :: " << min << " :: " << sec << '\n';
	}
	Time operator + (const Time& T)
	{
		Time res;
		res.hour = hour;
		res.min = min;
		res.sec = sec;
		res.sec = res.sec + T.sec;
		if (res.sec > 59)
		{
			while (res.sec > 59)
			{
				res.sec = res.sec - 60;
				res.min = res.min + 1;
			}
			if (res.min > 59)
			{
				res.min = res.min - 60;
				res.hour = res.hour + 1;
			}
		}
		res.min = res.min + T.min;
		if (res.min > 59)
		{
			while (res.min > 59)
			{
				res.min = res.min - 60;
				res.hour = res.hour + 1;
			}
		}
		return res;
	}
	Time operator - (const Time& T)
	{
		Time res;
		if ((sec - T.sec) < 0)
		{
			if (min != 0)
			{
				min = min - 1;
				sec = sec + 60;
			}
			else
			{
				min = min + 59;
				hour = hour - 1;
				sec = sec + 60;
			}
		}
		res.sec = sec - T.sec;
		if ((min - T.min) < 0)
		{
			min = min + 60;
			hour = hour - 1;
		}
		res.min = min - T.min;
		res.hour = hour - T.hour;
		return res;
	}
	Time& operator = (const Time& T)
	{
		if (this != &T)
		{
			sec = T.sec;
			min = T.min;
			hour = T.hour;
		}
		return *(this);
	}
	bool operator == (const Time& T)
	{
		if (hour == T.hour && min == T.min && sec == T.sec)
		{
			return true;
		}
		return false;
	}
	bool operator != (const Time& T)
	{
		if (hour == T.hour && min == T.min && sec == T.sec)
		{
			return false;
		}
		return true;
	}
	bool operator < (const Time& T)
	{
		if (T.hour > hour)
		{
			return true;
		}
		if (T.hour < hour)
		{
			return false;
		}
		if (T.min > min)
		{
			return true;
		}
		if (T.min < min)
		{
			return false;
		}
		if (T.sec > sec)
		{
			return true;
		}
		else
		{
			return true;
		}
	}
	bool operator > (const Time& T)
	{
		if (T.hour > hour)
		{
			return false;
		}
		if (T.hour < hour)
		{
			return true;
		}
		if (T.min > min)
		{
			return false;
		}
		if (T.min < min)
		{
			return true;
		}
		if (sec > T.sec)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator <= (const Time& T)
	{
		if (hour == T.hour && min == T.min && sec == T.sec)
		{
			return true;
		}
		if (T.hour > hour)
		{
			return true;
		}
		if (T.hour < hour)
		{
			return false;
		}
		if (T.min > min)
		{
			return true;
		}
		if (T.min < min)
		{
			return false;
		}
		if (T.sec > sec)
		{
			return true;
		}
		else
		{
			return true;
		}
	}
	bool operator >= (const Time& T)
	{
		if (hour == T.hour && min == T.min && sec == T.sec)
		{
			return true;
		}
		if (T.hour > hour)
		{
			return false;
		}
		if (T.hour < hour)
		{
			return true;
		}
		if (T.min > min)
		{
			return false;
		}
		if (T.min < min)
		{
			return true;
		}
		if (sec > T.sec)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};
int main()
{
	int choce = 0;
	while (true)
	{
		std::cout << "1 - Time 1 + Time 2\n";
		std::cout << "2 - Time 1 - Time 2\n";
		std::cout << "3 - Assign Time 1 = Time 2\n";
		std::cout << "4 - Check If Time 1 == Time 2\n";
		std::cout << "5 - Check If Time 1 != Time 2\n";
		std::cout << "6 - Check If Time 1 > Time 2\n";
		std::cout << "7 - Check If Time 1 < Time 2\n";
		std::cout << "8 - Check If Time 1 >= Time 2\n";
		std::cout << "9 - Check If Time 1 <= Time 2\n";
		std::cout << "-1 - Exit\n";
		std::cout << "Your Choice: ";
		std::cin >> choce;
		clearScreen();
		if (choce == -1)
		{
			return 0;
		}
		if (choce == 1)
		{
			Time T1;
			T1.input();
			T1.display();
			Time T2;
			T2.input();
			T2.display();
			Time T;
			T = T1 + T2;
			T.display();
		}
		if (choce == 2)
		{
			Time T1;
			T1.input();
			T1.display();
			Time T2;
			T2.input();
			T2.display();
			Time T;
			T = T1 - T2;
			T.display();
		}
		if (choce == 3)
		{
			Time T1;
			T1.input();
			T1.display();
			Time T2;
			T2.input();
			T2.display();
			T1 = T2;
			std::cout << "T2 Is Assigned To T1\n";
			T1.display();
		}
		if (choce == 4)
		{
			Time T1;
			T1.input();
			T1.display();
			Time T2;
			T2.input();
			T2.display();
			if (T1 == T2)
			{
				std::cout << "True, They Are Equal\n";
			}
			else
			{
				std::cout << "False, They're Not Equal\n";
			}
		}
		if (choce == 5)
		{
			Time T1;
			T1.input();
			T1.display();
			Time T2;
			T2.input();
			T2.display();
			if (T1 != T2)
			{
				std::cout << "True , They Are Not Equal\n";
			}
			else
			{
				std::cout << "False, They're Not Equal\n";
			}
		}
		if (choce == 6)
		{
			Time T1;
			T1.input();
			T1.display();
			Time T2;
			T2.input();
			T2.display();
			if (T1 > T2)
			{
				std::cout << "True\n";
			}
			else
			{
				std::cout << "False\n";
			}
		}
		if (choce == 7)
		{
			Time T1;
			T1.input();
			T1.display();
			Time T2;
			T2.input();
			T2.display();
			if (T1 < T2)
			{
				std::cout << "True\n";
			}
			else
			{
				std::cout << "False\n";
			}
		}
		if (choce == 8)
		{
			Time T1;
			T1.input();
			T1.display();
			Time T2;
			T2.input();
			T2.display();
			if (T1 >= T2)
			{
				std::cout << "True\n";
			}
			else
			{
				std::cout << "False\n";
			}
		}
		if (choce == 9)
		{
			Time T1;
			T1.input();
			T1.display();
			Time T2;
			T2.input();
			T2.display();
			if (T1 <= T2)
			{
				std::cout << "True\n";
			}
			else
			{
				std::cout << "False\n";
			}
		}
	}
}