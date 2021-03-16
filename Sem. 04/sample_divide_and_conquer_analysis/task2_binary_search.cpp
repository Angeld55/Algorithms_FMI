#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

bool isPowerOfTwo(int n)
{
	while (n > 1)
	{
		if (n % 2 == 1)
			return false;
		n /= 2;
	}
	return true;
}
int CountPowerOfTwos(const int* arr, int start, int end)
{

	if (start > end)
		return 0;

	int mid = (start + end) / 2;

	int count = isPowerOfTwo(arr[mid]) ? 1 : 0;

	return count + CountPowerOfTwos(arr, start, mid - 1) + CountPowerOfTwos(arr, mid + 1, end);
	
}
const int SIZE = 7;

int main()
{
	int arr[SIZE] = { 1, 2, 3, 4, 5, 8, 7 };
	cout << CountPowerOfTwos(arr, 0, SIZE - 1);

	//f << 1000000;

	return 0;
}