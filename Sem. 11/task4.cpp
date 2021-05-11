#include <iostream>
#include <vector>
#include <algorithm>
#include "Pick.hpp"
using namespace std;

template <typename T>
int partition(T* arr, int len, int p)
{

	T pivot = p;
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
size_t countCandyICanBuy(int* candy, size_t len, size_t money)
{
	if (len == 0)
		return 0;

	if (len == 1)
		return candy[0] < money;

	size_t mid = len / 2;

	size_t m = PICK<int>(candy, len, mid); // O(n)

	partition<int>(candy, len, m); // O(n)

	size_t S = 0; 
	for (int i = 0; i < mid; i++)
		S += candy[i];

	if (S == money)
		return mid;

	if (S > money)
		return countCandyICanBuy(candy, mid, money);

	if (S < money)
		return mid + countCandyICanBuy(candy += mid, len - mid, money - S);
}
int main()
{
	int candy[] = { 39, 4, 6, 1, 2, 66, 20 };

	cout << countCandyICanBuy(candy, sizeof(candy) / sizeof(int), 40);
}
