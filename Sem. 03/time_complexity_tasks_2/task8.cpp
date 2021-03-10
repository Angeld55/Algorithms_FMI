#include <iostream>
#include <algorithm>


int funcHelp(int i, int j)
{
	if (i == 0 && j == 0)
		return 1;

	if (i == 0)
		return funcHelp(i,j-1) + funcHelp(i,j-1);
	if (j == 0)
		return funcHelp(i - 1, j) + funcHelp(i-1, j);

	return  10 * funcHelp(i - 1, j) +  11 * (i, j - 1) ;
}

int task9(int n)
{
	return funcHelp(n, n);
}


int main()
{

	std::cout << task9(10);
}