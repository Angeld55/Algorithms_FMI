#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

unsigned long long fact(unsigned long long n)
{
	if (n == 0)
		return 1;
	return n * fact(n-1);
}
int main()
{
	
	cout << fact(3);

	return 0;
}