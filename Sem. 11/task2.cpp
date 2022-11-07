#include <iostream>
using namespace std;

template <typename T>
int partition(T* arr, int len, T pivot)
{
	int i = 0, j = len - 1;

	while (true)
	{

		while (arr[j] > pivot)
			j--;

		while (arr[i] < pivot)
			i++;

		if (i < j)
			std::swap(arr[i], arr[j]);
		else
			return j;
	}
}

void task2(int* X, size_t len)
{
	partition<int>(X, len, 0);
}
int main()
{
	int X[] = { -4, 1, 5, 6,-3,3,4,-2};
	size_t len = sizeof(X) / sizeof(int);

	task2(X, len);

	for (int i = 0; i < len; i++)
		cout << X[i] << " ";


}
