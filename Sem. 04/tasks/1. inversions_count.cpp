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
int countInversionsAndSort(T* arr, int len)
{

	int end = len - 1;

	int inversionsCount = 0;
	for (int i = 0; i < len; i++)
	{
		int lastSwappedIndex = 0;

		for (int j = 0; j < end; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr, j, j + 1);
				lastSwappedIndex = j;

				inversionsCount++;
			}
		}

		end = lastSwappedIndex;
		if (lastSwappedIndex == 0) //Масив дали вече е сортиран? 
			return inversionsCount;
	}
}


const size_t SIZE = 10;
int main()
{

	int arr[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

	cout << "Count of inversions in: [";
	for (int i = 0; i < SIZE; i++)
		cout << " " << arr[i];
	cout << "] is " << countInversionsAndSort(arr, SIZE) << endl;
	 

}
