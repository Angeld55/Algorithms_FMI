#include <iostream>
#include <fstream>

using namespace std;

void print(const int* arr, int len)
{
	for (int i = 0; i < len; i++)
		cout << arr[i] << " ";
	cout << endl;
}
void generateCombinationsNoRepetiotion(int* arr, int len, int* currentComb, int k, int index, int start)
{
	if (index >= k)
		print(currentComb, k);
	else
	{
		for (int i = start; i < len; i++) 
		{
			currentComb[index] = arr[i];
			generateCombinationsNoRepetiotion(arr, len, currentComb, k, index + 1, i + 1);
		}
	}

}



int main()
{
	int arr[4] = { 1, 2, 3, 4 };
	int var[2];
	generateCombinationsNoRepetiotion(arr, 4, var, 2, 0, 0);
	
}
 