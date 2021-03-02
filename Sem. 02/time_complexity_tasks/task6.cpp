#include <iostream>
using namespace std;


unsigned long long task6(unsigned long long n)
{
	unsigned long long res = 0;
	for (unsigned long long i = 1; i <= n; i++)
	{
		for (unsigned long long j = 1; j <= n; j += i)
		{
			if(res>300)
				res *= 2;
			else
				res--;
		}
			
	}
	return res;
}

int main()
{
	cout << task6(100);
}