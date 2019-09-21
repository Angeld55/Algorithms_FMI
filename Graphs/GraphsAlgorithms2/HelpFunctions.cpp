#include <iostream>
using namespace std;

const int MAX = 1000000;
const int MIN = -1000000;
int** createMatrix(int len)
{
	int** matrix = new int*[len];
	for (int i = 0; i < len; i++)
		matrix[i] = new int[len];
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			matrix[i][j] = MAX;
		}
	}
	return matrix;
}
void deleteMatrix(int** matrix, int len)
{
	for (int i = 0; i < len; i++)
		delete[] matrix[i];
	delete[] matrix;
}
void printMatrix(int** matrix, int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (matrix[i][j] == MAX)
				cout << '+' << " ";
			else
				cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
}
void printArray(const int* arr, int len)
{
	for (int i = 0; i < len; i++)
	{	
		if (arr[i] == MIN)
			cout << "- ";
		else
			cout << arr[i]<<" ";
	}
	cout << endl;
	cout << endl;
}