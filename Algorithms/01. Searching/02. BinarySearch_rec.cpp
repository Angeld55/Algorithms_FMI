#include <iostream>
using namespace std;

template <class T>
int BinarySearch(const int* arr, int len, const T& searched)
{
	if (len == 0)
		return -1;

	int midIndex = len / 2;

	if (arr[midIndex] == searched)
		return midIndex;
	
	if (arr[midIndex] < searched)
		return BinarySearch(arr + midIndex + 1, len - midIndex - 1, searched);
	else
		return BinarySearch(arr, midIndex, searched);
}

int main()
{
	int arr[] = { 1, 2, 2, 6, 19, 55 };
	cout << BinarySearch(arr, 6, 19);
}
