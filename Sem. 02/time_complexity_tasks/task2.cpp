#include <iostream>
using namespace std;


int task2(int n)
{
	int res = 5;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i*i; j++)
		{
			res *= (j % 3);
		}

	}
	
	for(int i = 0; i < 9999999; i++)
	{
		if(res % 3 ==0)
			res/3;
		else
			res*=res;
	}
	
	return res;
}

int main()
{
	cout << task2(20);
}