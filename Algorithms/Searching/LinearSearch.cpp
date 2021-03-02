#include <iostream>
using namespace std;


int linearSearch(const int* arr, int len, int searched)
{
	for (int i = 0; i < len; i++)
	{
		if (arr[i] == searched)
			return i;//връщаме индекса.
	}
	return -1;//елементът го няма
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };

	cout << linearSearch(arr, 7, 10);
}