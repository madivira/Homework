//Маслякова Диана
//Урок 10 Задание 2.  
/*Дан массив случайных чисел в диапазоне от –20 до +20. 
Необходимо найти позиции крайних отрицательных
элементов(самого левого отрицательного элемента
и самого правого отрицательного элемента) и отсо -
ртировать элементы, находящиеся между ними.*/


#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

template <class T> void insertSort(T a[], long size, T begin, T end);

int main()
{
	int left;//крайний левый отрицательный элемент
	int right;//крайний правый отрицательный элемент

	setlocale(LC_ALL, "ru");
	const int N = 20;
	int array[N];

	for (int i = 0; i < N; i++)//заполняем массив
	{
		array[i] = rand() % (-40) - 20;
		cout << array[i] << ", ";
	}
	cout << endl;
	cout << endl;

	for (int i = 0; i < N; i++)//находим крайнее левое отрицательное число
	{
		if (array[i] < 0)
		{
			left = i;
			break;
		}	
	}

	for (int i = N-1; i >=0; i--)//находим крайнее правое отрицательное число
	{
		if (array[i] < 0)
		{
			right = i;
			break;
		}
	}
	
	insertSort(array, N, left, right);//сортировка массива в заданных пределах

	for (int i = 0; i < N; i++)
	{
		cout << array[i] << ", ";
	}

}

template <class T> void insertSort(T a[], long size, T begin,T end) 
{// сортировка вставками
	T x;
	long i, j;
	
	for (i = begin; i < end; i++) 
	{
		x = a[i];
				
		for (j = i - 1; j >= 0 && a[j] > x; j--)
		{
			a[j + 1] = a[j];
		}

		a[j + 1] = x;
		
	}
}
