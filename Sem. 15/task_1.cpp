#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

size_t getMinOperation(size_t n)
{
	vector<int> arr(n + 1, 99999);

	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;

	for (int i = 4; i <= n; ++i)
	{
		int v1 = 99999, v2 = 99999, v3 = 99999;

		if (i % 3 == 0)
			v1 = arr[i / 3];

		if (i % 2 == 0)
			v2 = arr[i / 2];

		v3 = arr[i - 1];
		arr[i] = min({ v1, v2, v3 }) + 1;
	}
	return arr[n];
}
int main()
{
	
	cout << getMinOperation(40);
}