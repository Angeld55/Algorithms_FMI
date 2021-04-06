#include <iostream>
using namespace std;


template <class T>
void swap(T* arr, int i, int j)
{
	T temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

template <class T>
void BubbleSort(T* arr, int len)
{

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(arr, j, j + 1);
		}
	}
}

int main()
{
	int arr[] = { 7, 6, 5, 4, 3, 2, 1 };

	BubbleSort<int>(arr, 7);

	for (int i = 0; i < 7; i++)
		cout << arr[i] << " ";
}
