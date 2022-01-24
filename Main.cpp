#include <iostream>
#include "TestClass.h"

//using bubble sort
template <typename T>
void bubbleSort(T item[], int size)
{
	
	for (int i = 0; i < size; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			if (item[j] < item[i])
			{
				T temp = item[i];
				item[i] = item[j];
				item[j] = temp;
			}
		}
	}
}

template <typename T>
void insertionSort(T item[], int size)
{
	int j = 0;
	int key = 0;

	for (int i = 1; i < size; i++)
	{
		key = item[i];
		j = i - 1;

		while (j >= 0 && item[j] > key)
		{
			item[j + 1] = item[j];
			j--;
		}

		item[j + 1] = key;
	}
}

//prints the array
template <typename T>
void printArray(T item[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		std::cout << item[i] << std::endl;
	
}

//the main display
int main()
{
	int i, j;
	//int item[] = { 10, 20, 55, 1, 37, 15, 88};
	float itemf[] = { 10.9f, 20.0f, 55.6f, .1f, 37.9f, 15.5f, 88.8f };

	std::cout << "Inital array: \n";
	printArray(itemf, 7);
	
	insertionSort(itemf, 7);
	std::cout << "Sorted array: \n";
	printArray(itemf, 7);

	TestClass<int> test = TestClass<int>();
	int result = test.add(1, 2);

	return 0;
}