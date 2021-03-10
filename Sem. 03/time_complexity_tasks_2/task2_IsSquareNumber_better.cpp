#include <iostream>

bool isPowerOfTwo2_better(int n)
{
	if (n != 0)
		return (n & (n - 1)) == 0;
	return false;
}

int main()
{
	std::cout << isPowerOfTwo2_better(32);
}