#include <iostream>
using namespace std;

int task5(int n)
{
	int res = 0;
	for (int i = 1; i <= n; i*=2)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int i = 0; i <= 1000; i++)
				res++;
		}
	}
	return res;
}

int main()
{
	cout << task5(10000);
}