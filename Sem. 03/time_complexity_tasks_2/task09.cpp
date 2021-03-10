#include <iostream>
#include <algorithm>


unsigned long long funcHelp(unsigned long long i, unsigned long long j)
{
	if (i == 0 && j == 0)
		return 1;

	if (i == 0)
		return funcHelp(i, j - 1) + funcHelp(i, j - 1);
	if (j == 0)
		return funcHelp(i - 1, j) + funcHelp(i-1, j);

	return  10 * funcHelp(i - 1, j) +  11 * funcHelp(i, j - 1) ;
}

unsigned long long task9(unsigned long long n)
{
	return funcHelp(n, n);
}


int main()
{

	std::cout << task9(10);
}
