//Маслякова Диана
//Урок №9
//Задание 1.  Написать шаблон функции для поиска среднего арифметического значений массива.


#include <iostream>

using namespace std;

template <typename T, typename T2> T Average(T2 N, T array[])
{
	T summ = 0;
	for (int i = 0; i <N ; i++)
	{
		summ += array[i];
	}
	T average = summ / N;
	return average;
}

int main()
{
	
	double arr[] = { 2.5,3.5,4.3,2,6.33,5.9 };
	int arr2[] = { 2,3,5,9,6,4,7,5 };

	cout << Average(6,arr)<<endl;
	cout << Average(8, arr2)<<endl;

}
