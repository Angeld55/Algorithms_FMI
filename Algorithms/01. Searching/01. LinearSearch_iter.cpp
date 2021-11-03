#include <iostream>
using namespace std;

template <class T>
int linearSearch(const T* arr, int len, const T& searched)
{
	for (int i = 0; i < len; i++)
	{
		if (arr[i] == searched)
			return i;
	}
	return -1;
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };

	cout << linearSearch<int>(arr, 7, 10);
}
