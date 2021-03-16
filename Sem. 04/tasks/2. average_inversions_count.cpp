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
T* copyArr(const T* arr, int len)
{
	T* copy = new T[len];
	
	for (int i = 0; i < len; i++)
		copy[i] = arr[i];

	return copy;
}

unsigned fact(int n)
{
	if (n == 0)
		return 1;
	return n * fact(n - 1);
}


template <class T>
size_t generateAllPermutationsAndSumInversions(T* arr, int len, int index)
{
	if (index >= len)
	{
		//new permutaion is generated;
		T* currentPermutaion = copyArr(arr, len);
		size_t inversions = countInversionsAndSort<T>(currentPermutaion, len);

		delete[] currentPermutaion;

		return inversions;
	}
	else
	{
		size_t inversions = 0;

		inversions += generateAllPermutationsAndSumInversions(arr, len, index + 1);
		for (int i = index + 1; i < len; i++) 
		{
			swap(arr, index, i);
			inversions += generateAllPermutationsAndSumInversions(arr, len, index + 1);
			swap(arr, index, i);
		}
		return inversions;
	}
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
		if (lastSwappedIndex == 0) //Ìàñèâ äàëè âå÷å å ñîðòèðàí? 
			return inversionsCount;
	}
}

size_t AverageInversionsCountInAllPermutions(int n)
{
	int* arr = new int[n];

	for (int i = 1; i <= n; i++) //creates the array [1,2,3, .. n ]
		arr[i - 1] = i;

	size_t inversionsCount = generateAllPermutationsAndSumInversions(arr, n, 0);

	delete[] arr;

	return inversionsCount / fact(n); // all inversions in the permutaions   /  n! (the count of the permutaions)

}
void averageInversionsCountExample()
{
	cout << "n =  4, max inversions count =  4*(4-1)/2  =  6. Average inversions in all 4! permutations " << AverageInversionsCountInAllPermutions(4) << endl;
	cout << "n =  5, max inversions count =  5*(5-1)/2  = 10. Average inversions in all 5! permutations " << AverageInversionsCountInAllPermutions(5) << endl;
	cout << "n =  6, max inversions count =  6*(6-1)/2  = 15. Average inversions in all 6! permutations " << AverageInversionsCountInAllPermutions(6) << endl;
	cout << "n =  7, max inversions count =  7*(7-1)/2  = 21. Average inversions in all 7! permutations " << AverageInversionsCountInAllPermutions(7) << endl;
	cout << "n =  8, max inversions count =  8*(8-1)/2  = 23. Average inversions in all 8! permutations " << AverageInversionsCountInAllPermutions(8) << endl;
	cout << "n =  9, max inversions count =  9*(9-1)/2  = 36. Average inversions in all 9! permutations " << AverageInversionsCountInAllPermutions(9) << endl;
	cout << "n = 10, max inversions count = 10*(10-1)/2 = 45. Average inversions in all 10! permutations " << AverageInversionsCountInAllPermutions(10) << endl;
	cout << "n = 10, max inversions count = 11*(11-1)/2 = 55. Average inversions in all 11! permutations " << AverageInversionsCountInAllPermutions(11) << endl;
}

int main()
{

	averageInversionsCountExample();

}
