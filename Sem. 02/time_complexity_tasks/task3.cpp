#include <iostream>
using namespace std;


unsigned long long task3(unsigned long long n)
{
	unsigned long long res = 0;
	for (unsigned long long i = 1; i <= n; i*=2)
	{
		for (unsigned long long j = 1; j <= i; j++)
			res++;
			
	}
	return res;
}

int main()
{
	cout << task3(20);
}