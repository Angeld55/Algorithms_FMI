#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
const int ENGLISH_ALPHABET_SIZE = 26;

size_t Kadane(const vector<int>& arr) //Maximum subarray problem
{
	int m = 0; //максималната сума на подмасив в подмасива arr[0...i-1].
	int l = 0; //максималната сума на подмасив в подмасива arr[0...i-1], който завръшва на arr[i-1].

	for (int i = 0; i < arr.size(); i++)
	{
		l += arr[i];

		if (l < 0)
			l = 0;

		if (l > m)
			m = l;
	}
	return m;
}
int main()
{
	vector<int> v = {-3,-4,44,-5,99};

	std::cout << Kadane(v);
}
