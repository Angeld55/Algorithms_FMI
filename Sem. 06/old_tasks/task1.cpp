#include <iostream>

int evenCount(const int* arr, int len)
{

	int evenCount = 0;
	for (int i = 0; i < len; i++)
	{
		if (arr[i] % 2 == 0)
			evenCount++;
	}
	return evenCount;

}


int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };

	std::cout << evenCount(arr, 5);


}