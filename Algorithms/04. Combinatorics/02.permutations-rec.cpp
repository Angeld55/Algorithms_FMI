	#include <iostream>
#include <fstream>

using namespace std;

void print(const int* arr, int len)
{
	for (int i = 0; i < len; i++)
		cout << arr[i] << " ";
	cout << endl;
}
void generatePermutations(int* arr, int len,  int index)
{
	if (index >= len)
		print(arr, len);
	else
	{
		generatePermutations(arr, len, index + 1);

		for (int i = index + 1; i < len; i++) 
		{
			std::swap(arr[index], arr[i]);
			generatePermutations(arr, len, index + 1);
			std::swap(arr[index], arr[i]); //back to the original place; 
		}
	}

}



int main()
{
	int arr[4] = { 1, 2, 3, 4 };
	generatePermutations(arr ,4 , 0);
	
}
 