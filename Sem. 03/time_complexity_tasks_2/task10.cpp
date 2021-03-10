#include <iostream>

unsigned long long task10(unsigned long long n)
{
	if (n == 0)
		return 1;

	int res = 0;
	for (int i = 0; i < (1 << n); i++)
		res++;

	return res + task10(n - 1);
}

int main()
{
	std::cout << task10(5);
}