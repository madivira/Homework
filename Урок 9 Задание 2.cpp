//Маслякова Диана
/*Урок 9 Задание 2.  Написать перегруженные шаблоны 
функций для нахождения корней линейного(a*x + b = 0)
и квадратного (a*x2 + b * x + c = 0) уравнений.
Замечание: в функции передаются коэффициенты уравнений.*/


#include<math.h>
#include <iostream>
using namespace std;

template <typename T> void Equation(T a, T b);//линейное уравнение
template <typename T> void Equation(T a, T b, T c);//квадратное уравнение


int main()
{
	setlocale(LC_ALL, "ru");

	 Equation(-9, 81);
	 Equation(1, -5, 6);
	 Equation(1, -5, 7);
	 Equation(1, -10, 25) ;
	 Equation(1, -3, 0) ;
	 Equation(1, 0, -6) ;
	 Equation(1, 0, 6) ;
	 Equation(0, 2, 6) ;
}

template <typename T> void Equation(T a, T b)
{
	double x;
	x = -(b / a);
	cout << "Х = "<<x << endl;
	
}

template <typename T> void Equation(T a, T b, T c)
{
	double x1, x2;

	if (a != 0)
	{
		if (b!=0 && c!=0)
		{
			double D;
			D = b*b - 4*a*c;//дискриминант 

			if (D < 0)
			{
				cout << "Решений нет!" << endl << endl;
				
			}
			else if (D==0)
			{
				x1 = (-b) / 2 * a;
				cout << "Решение имеет один корень! Х = " << x1<<endl << endl;
				
			}
			else if (D>0)
			{
				x1 = (-b + sqrt(D)) / 2 * a;
				x2 = (-b - sqrt(D)) / 2 * a;
				cout << "Решение имеет два корня!" << endl;
				cout << "Х1 = " << x1 << endl;
				cout << "Х2 = " << x2 << endl << endl;
				
			}
		}
		else if (b==0)
		{
			if ((-c/a)<0)
			{
				cout << "Корней нет!"<< endl << endl;
			}
			else
			{
				x1 = sqrt(-c / a);
				x2 = -sqrt(-c / a);
				cout << "Решение имеет два корня!" << endl;
				cout << "Х1 = " << x1 << endl;
				cout << "Х2 = " << x2 << endl << endl;
				
			}
		}
		else if (c==0)
		{
			x1 = -(b / a);
			cout << "Решение имеет два корня!" << endl;
			cout << "Х1 = " << x1 << endl;
			cout << "Х2 = 0" << endl << endl;
			
		}
	}
	else
	{
		Equation(b, c);
	}
}
