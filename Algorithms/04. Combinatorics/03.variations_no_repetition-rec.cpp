#include <iostream>
#include <fstream>

using namespace std;

void print(const int* arr, int len)
{
	for (int i = 0; i < len; i++)
		cout << arr[i] << " ";
	cout << endl;
}
void generateVariationsNoRepetiotion(int* arr, int len, int* currentVar, int k, int index)
{
	if (index >= k)
		print(currentVar, k);
	else
	{
		for (int i = index; i < len; i++) 
		{
			currentVar[index] = arr[i];
			std::swap(arr[i], arr[index]);
			generateVariationsNoRepetiotion(arr, len, currentVar, k, index + 1);
			swap(arr[i], arr[index]);
		}
	}

}



int main()
{
	int arr[4] = { 1, 2, 3, 4 };
	int var[2];
	generateVariationsNoRepetiotion(arr, 4, var, 2, 0);
	
}
 