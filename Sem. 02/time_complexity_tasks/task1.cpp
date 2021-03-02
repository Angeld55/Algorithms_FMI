#include <iostream>
using namespace std;

int task1(int n)
{
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i % 2 == j % 2)
				res++;
		}
	}
	
	for(int i = 0; i< n/2; i++)
		res*=2;
	
	return res;
}

int main()
{
	cout << task1(10000);
}