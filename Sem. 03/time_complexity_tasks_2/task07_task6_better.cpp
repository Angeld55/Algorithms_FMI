#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

unsigned long long func(unsigned long long n)
{
	if (n == 0 || n==1)
		return 1;
	return 5*func(n - 1) + 5*func(n - 2);
}
int main()
{
	
	cout << func(20);

	return 0;
}