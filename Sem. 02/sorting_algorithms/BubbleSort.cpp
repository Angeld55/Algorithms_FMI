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

	int end = len - 1;

	for (int i = 0; i < len; i++)
	{
		int lastSwappedIndex = 0;

		for (int j = 0; j < end; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr, j, j + 1);
				lastSwappedIndex = j;
			}
		}

		end = lastSwappedIndex;
		if (lastSwappedIndex == 0) //Масив дали вече е сортиран? 
			return;
	}
}

int main()
{
	int arr[] = { 7,6,5,4,3,2,1 };

	BubbleSort<int>(arr, 7);

	for (int i = 0; i < 7; i++)
		cout << arr[i] << " ";
}
