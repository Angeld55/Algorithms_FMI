#include <iostream>

unsigned long long task8(unsigned long long n)
{
	if (n == 0)
		return 1;

	unsigned long long res = 0;
	for (int i = n-1; i >= 0; i--)
		res += task8(i);
	return res;
}

int main()
{
	std::cout << task8(8);
}
