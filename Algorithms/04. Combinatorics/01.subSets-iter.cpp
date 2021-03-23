#include <iostream>

const int MAX = 20;
void print(const int* arr, int len, const int* bitString)
{
	std::cout << "{ ";

	bool isFirst = true;
	for (int i = 0; i < len; i++)
	{
		if (bitString[i] == 1)
		{
			if (!isFirst)
				std::cout << ", ";

			std::cout << arr[i];
			
			isFirst = false;
		}
	}
	std::cout << " }" << std::endl;
}
bool next(int* bitString, int n)
{
	int i = n - 1;

	while (i >= 0 && bitString[i] == 1)
		bitString[i--] = 0;

	if (i < 0)
		return false;

	bitString[i] = 1;
	return true;
}

void generateAllSubests(const int* arr, int len)
{
	int*  bitString = new int[len];
	for (int i = 0; i < len; i++)
		bitString[i] = 0;
	//the first is the empty set.

	for (int i = 0; i < 1 << len; i++)
	{
		print(arr, len , bitString);
		next(bitString, len);
	}

	delete[] bitString;
}
int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };

	generateAllSubests(arr, 5);


}