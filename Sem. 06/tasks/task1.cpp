#include <iostream>

using namespace std;

unsigned int GCD(unsigned a, unsigned b)
{
	unsigned x = a;
	unsigned y = b;

	while (x > 0)
	{
		if (y >= x)
			y = y - x;
		else
			std::swap(x, y);
	}
	return y;
}

int main()
{
	cout << GCD(24, 32);
}