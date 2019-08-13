//Маслякова Диана
// Урок 10 Задание 3
/*Дан массив из 20 целых чисел со значениями от 1 до 20.
Необходимо:
 ■ написать функцию, разбрасывающую элементы мас-
сива произвольным образом;
 ■ создать случайное число из того же диапазона и найти 
позицию этого случайного числа в массиве;
 ■ отсортировать элементы массива, находящиеся сле-
ва от найденной позиции по убыванию, а элементы 
массива, находящиеся справа от найденной позиции 
по возрастанию.*/


#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

template <typename T> void Random(T array[], long size);
template <typename T> void Left(T array[],int begin,int end);
template <typename T> void Right(T array[], int begin, int end);

int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "ru");

	const int SIZE = 20;//размерность массива
	int arr[SIZE] = {3,12,1,17,19,4,9,11,2,5,10,7,6,8,15,13,18,0,14,16};//массив
	int randomNumber;//поиск случайного числа в массиве
	int element;//позиция рандомного элемента в массиве
	cout << "Вывод изначального массива" << endl;
	for (int i = 0; i < SIZE; i++)
	{		
		cout << arr[i] << "  ";
	}
	cout << endl;
	cout << endl;
	Random(arr, SIZE);//разброс чисел в массиве
	cout << "Вывод разбросанного массива" << endl;
	for (int i = 0; i < SIZE; i++)//вывод разбросанного массива
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
	cout << endl;
	randomNumber = rand() % 19 + 1;//создание рамндомного числа из диапозона
	cout << "Рандомное число из диапазона массива" << endl;
	cout << randomNumber<<endl;

	for (int i = 0; i <SIZE; i++)//поиск этого числа в массива
	{
		if (arr[i] == randomNumber)
		{
			element = i;
			cout << "Номер этого элемента в массиве" << endl;
			cout << element << endl;
		}
	}
	cout << endl;
	cout << "Упорядоченные элементы массива,  а элементы" << endl;
	cout << "находящиеся слева от найденной позиции по убыванию," << endl;
	cout << "массива, находящиеся справа от найденной позиции по возрастанию" << endl;
	//сортировка элементов по убыванию слева от найденного
	Left(arr, 0, element);
	//cортировка элементов по возрастанию справа от найденного
	Right(arr, element, SIZE);
	cout << endl;

}

template<typename T>void Random(T array[], long size)
{//пузырьковая сортировка

	srand(time(NULL));
	T buffer;
	int randomEl_j,randomEl_i;
	
	for (int i = 0; i < size; i++)
	{
		randomEl_i = rand() % 20 ;//рандомные элэменты
		randomEl_j = rand() % 20 ;//рандомные элэменты

		buffer = array[randomEl_i];
		array[randomEl_i] = array[randomEl_j];
		array[randomEl_j] = buffer;
	}
}

template<typename T> void Left(T array[], int begin, int end)
{
	T buffer;
	int i, j;

	for (int i = begin; i < end; i++)
	{
		for (int j = end - 1; j > i; j--)
		{
			if (array[j - 1] < array[j])
			{
				buffer = array[j - 1];
				array[j - 1] = array[j];
				array[j] = buffer;
			}
		}
	}
	for (int i =begin; i < end; i++)
	{
		cout << array[i]<<"  ";
	}
}

template<typename T> void Right(T array[], int begin, int end)
{
	T buffer;
	int i, j;

	for (int i = begin; i < end; i++)
	{
		for (int j = end-1; j > i; j--)
		{
			if (array[j -1] > array[j])
			{
				buffer = array[j - 1];
				array[j - 1] = array[j];
				array[j] = buffer;
			}
		}
	}
	for (int i = begin; i < end; i++)
	{
		cout << array[i] << "  ";
	}
}
