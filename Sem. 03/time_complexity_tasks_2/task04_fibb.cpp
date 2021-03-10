#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

unsigned long long fibb(unsigned long long n)
{
	if (n <= 1)
		return 1;
	return fibb(n - 1) + fibb(n - 2);
}
int main()
{
	
	cout << fibb(30);

	return 0;
}