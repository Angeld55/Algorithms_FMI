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


void generateAllSubests(const int* arr, int len, int*  bitString, int pos)
{


	if (pos == len)
		print(arr, len, bitString); // we ignore this in the analysis. This could be any action. 
	else
	{
		bitString[pos] = 0;
		generateAllSubests(arr, len, bitString, pos + 1);
		bitString[pos] = 1;
		generateAllSubests(arr, len, bitString, pos + 1);
	}

}
int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };

	int bitString[5] = { 0, 0, 0, 0, 0 };

	generateAllSubests(arr, 5, bitString, 0);


}