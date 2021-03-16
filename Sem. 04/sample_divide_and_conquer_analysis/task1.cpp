#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int findMax(const int* arr, int start, int end)
{

	if (start == end)
		return arr[start];

	int mid = (start + end) / 2;
	return std::max(findMax(arr, start, mid), findMax(arr, mid+1, end));
	
}
const int SIZE = 7;

int main()
{
	int arr[SIZE] = { 1, 2, 3, 4, 5, 6, 7 };
	cout << findMax(arr, 0, SIZE-1);

	//f << 1000000;

	return 0;
}