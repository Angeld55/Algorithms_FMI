#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


template <class T>
void  merge(T* arr1, int len1, T* arr2, int len2, T* res)
{
	T* result = new T[len1 + len2];

	int cursor1 = 0;
	int cursor2 = 0;
	int resultCursor = 0;

	while (cursor1 < len1 && cursor2 < len2)
	{
		if (arr1[cursor1] < arr2[cursor2])
			result[resultCursor++] = arr1[cursor1++];
		else
			result[resultCursor++] = arr2[cursor2++];
	}
	while (cursor1 < len1)
		result[resultCursor++] = arr1[cursor1++];

	while (cursor2 < len2)
		result[resultCursor++] = arr2[cursor2++];

	for (int i = 0; i < len1 + len2; i++)
		res[i] = result[i];

	delete[] result;

}
void task3(vector<int>& x)
{
	vector<int> even;
	vector<int> odd;

	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] % 2 == 0)
			even.push_back(x[i]);
		else
			odd.push_back(x[i]);
	}

	std::reverse(odd.begin(), odd.end());

	merge<int>(even.data(), even.size(), odd.data(), odd.size(), x.data());

}

int main()
{
	vector<int> X = { 2, 5, 8, 3, 12, 14, 20, 1 };

	task3(X);

	for (int i = 0; i < X.size(); i++)
		cout << X[i] << " ";
}
