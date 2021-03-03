#include <iostream>
using namespace std;


int binarySearch(const int* arr, int len, int searched)
{
	int leftIndex = 0;
	int rightIndex = len - 1;
	while (leftIndex <= rightIndex)
	{
		int midIndex = (leftIndex + rightIndex) / 2;
		if (arr[midIndex] == searched)
			return midIndex;
		if (arr[midIndex] > searched)
			rightIndex = midIndex - 1;
		else
			leftIndex = midIndex + 1;
	}
	return -1;

}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };

	cout << binarySearch(arr, 7, 10);
}