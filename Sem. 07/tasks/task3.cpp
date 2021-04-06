#include <iostream>

using namespace std;

bool isPrime(unsigned n)
{
	if (n <= 1)
		return false;

	double temp = sqrt(n);
	for (int i = 2; i <= temp; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}


int main()
{
	cout << isPrime(16);
}