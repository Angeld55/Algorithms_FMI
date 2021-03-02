#include <iostream>
using namespace std;

unsigned long long task7(unsigned long long n)
{
	unsigned long long a = 0;
	for (unsigned long long i = 0; i <= n; i++)
	{
		for (unsigned long long j = 0; j <= n; j++)
		{
			for (unsigned long long k = 0; k <= n; k++)
			{
				for (unsigned long long t = 0; t <= n; t++)
				{
					a++;
				}
			}
		}
	}

	for (unsigned long long i = 0; i < (1 << n); i++)
		a /= 2;

	for (unsigned long long i = 0; i <= 99999999; i++)
		a += 4;

	return a;
}

int main()
{
	cout << task7(100);
}