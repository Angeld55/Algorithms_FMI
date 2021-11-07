#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void printVector(const std::vector<size_t>& arr)
{
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
}

bool nextObj(std::vector<size_t>& v, size_t n) //k is v.size()
{
	int j = v.size() - 1;

	while (j >= 0 && v[j] == n - v.size() + j + 1)
		j--;

	if (j < 0)
		return false;

	v[j]++;

	for (size_t i = j + 1; i < v.size(); i++)
		v[i] = v[i - 1] + 1;

	return true;
}

void generateAllCombinations(size_t n, size_t k)
{
	std::vector<size_t> v(k);
	for (int i = 0; i < k; i++)
		v[i] = i + 1;

	do
	{
		printVector(v);
	} while (nextObj(v, n));
}


int main()
{
	generateAllCombinations(5, 3);
}
