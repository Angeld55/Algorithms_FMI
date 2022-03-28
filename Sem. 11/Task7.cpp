#include <iostream>
#include <vector>
#include <algorithm>
#include "Pick.hpp"

template <typename T>
size_t partition(T* arr, size_t len, T p)
{
	T pivot = p;
	size_t i = 0, j = len - 1;

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

size_t maximalStocksMinimalStockholders(size_t* stocks, size_t len, size_t goal)
{
	if (len == 1) // If we have only one element, we take it, so the starting index of the stocks we take is 0.
		return 0;

	size_t mid = len / 2;

	size_t median = PICK<size_t>(stocks, len, mid); // O(n)

	partition<size_t>(stocks, len, median); // O(n)

	size_t totalStocksCount = 0;
	for (size_t i = mid; i < len; i++) // O(n)
		totalStocksCount += stocks[i];

	if (totalStocksCount == goal)
		return mid;

	if (totalStocksCount > goal)
		return mid + maximalStocksMinimalStockholders(stocks + mid, len - mid, goal);

	if (totalStocksCount < goal)
		return maximalStocksMinimalStockholders(stocks, mid, goal - totalStocksCount);
}
size_t maximalStocksMinimalStockholders(size_t* stocks, size_t len)
{
	size_t sum = 0;
	for (size_t i = 0; i < len; i++)
		sum += stocks[i];
	(sum /= 2)++; // We want to buy more than half of the stocks.

	size_t resultIndex = maximalStocksMinimalStockholders(stocks, len, sum);
	return len - resultIndex;
}

int main()
{
	size_t stocks[] = { 39,4,6,1,2,66,33 };
	std::cout << maximalStocksMinimalStockholders(stocks, sizeof(stocks) / sizeof(size_t));
}
