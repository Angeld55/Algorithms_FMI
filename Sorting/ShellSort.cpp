
template<typename T>
#include <iostream>
using namespace std;

template<typename T>
void ShellSort(T* arr, int len)
{
	int gap = len / 2;

	while (gap >= 1)
	{
		for (int i = gap; i <= len - gap; i += gap)
		{
			T element = arr[i];
			int index = i - gap;

			while (index >= 0 && arr[index] > element)
			{
				arr[index + gap] = arr[index];
				index -= gap;
			}
			arr[index + gap] = element;
		}

		gap /= 2;
	}
}

int main()
{
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	ShellSort<int>(arr, 10);

	for (int i = 0; i < 6; i++)
		cout << arr[i] << " ";
}