#include <iostream>
using namespace std;

int task2(unsigned n)
{
	if (n <= 1)
		return n;

	unsigned res = 1;
	unsigned i = 1;
	while (res <= n)
	{
		i++;
		res = i * i;
	}
	return i - 1;
}


int main()
{
	cout << task2(36);
}