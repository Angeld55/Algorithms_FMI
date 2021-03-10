#include <iostream>

int funcHelp(int i,int j)
{
	if (i == 0)
		return 1;
    if(j == 0)
		return 0;
	
	return 10 * funcHelp(i-1, j) + 11 * funcHelp(i,j-1);
}

int task9(int n)
{
	return funcHelp(n,n);
}


int main()
{

	std::cout << task9(20);
}