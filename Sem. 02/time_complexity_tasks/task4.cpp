#include <iostream>
using namespace std;

int f(int num)
{
	int n = 0;
	for (int i = 0; i < num; i++)
	{
		n += 2;
	}
	return n % 2;
}

int task4(int n)
{
	int res = 1;
	for (int i = n; i >= 0; i /= 2)
	{
		res = f(res);
	}
	return res;
}


int main()
{
	task4(30);
}