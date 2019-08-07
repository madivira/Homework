// Маслякова Диана
/*Урок 9 Задание 3 
Написать функцию, которая принимает в качестве 
параметров вещественное число и количество знаков 
после десятичной точки, которые должны остаться. 
Задачей функции является округление вышеуказан-
ного вещественного числа с заданной точностью */



#include <iostream>
using namespace std;

template <typename T> T Digit(T digitEnter, int dozens);

int main()
{
	cout << Digit(12.541222584,3) << endl;

}

template <typename T> T Digit(T digitEnter, int dozens)//digitEnter-вводимое число, dozens- количество знаков после десятичной точки
{
	int roundTheNumber = 1;

	for (int i = 0; i < dozens; ++i)//накапливаем то количество знаков, которые должны остаться после округления
	{
		roundTheNumber *= 10;
	}

	return T(int(digitEnter*roundTheNumber)) / roundTheNumber;//в скобках избавляемся от ненужных чисел- умножаем и превращаем его в целочисленное, а потом делим и таким образом передвигаем запятую
}
