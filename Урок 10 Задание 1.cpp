// Маслякова Диана 
/*Урок 10 Задание 1
1.  Дан массив чисел размерностью 10 элементов. Написать
функцию, которая сортирует массив по возрастанию
или по убыванию, в зависимости от третьего пара-
метра функции. Если он равен 1, сортировка идет по
убыванию, если 0, то по возрастанию. Первые 2 па-
раметра функции — это массив и его размер, третий
параметр по умолчанию равен 1.*/


#include <iostream>

using namespace std;

template <typename T> void BubbleSort(T arr[], long size);


int main()
{
	setlocale(LC_ALL, "ru");
	
	const int N = 10;
	int decreasingArr[N] = { 2,5,1,6,3,0,4,8,7,9 };//убывающий массив
	int increasingArr[N] = { 2,5,0,6,3,1,4,8,7,9 };//возрастающий массив
	

	BubbleSort (decreasingArr, N);//сортировка по убыванию
		
	BubbleSort(increasingArr, N);//сортировка по возрастанию
	


}

template <typename T> void BubbleSort(T arr[], long size)
{//пузырьковая сортировка

	long i, j;
	T buffer;
	if (arr[2] == 1)//сортировка по убыванию
	{	
		for (i = 0; i < size; i++)
		{
			for (j = size - 1; j > i; j--)
			{

				if (arr[j - 1] < arr[j])
				{
					buffer = arr[j - 1];
					arr[j - 1] = arr[j];
					arr[j] = buffer;
				}
			}
		}
		
	}
	else if (arr[2] == 0)//сортировка по возрастанию
	{
		for (i = 0; i < size; i++)
		{
			for (j = size - 1; j > i; j--)
			{

				if (arr[j - 1] > arr[j])
				{
					buffer = arr[j - 1];
					arr[j - 1] = arr[j];
					arr[j] = buffer;
				}
			}
		}
		
	}
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}
