#include <iostream>
#include "Person.h"
using namespace std;

unsigned power(unsigned n, unsigned k)
{
	if (k == 0)
		return 1;

	if (k % 2 == 0)
	{
		unsigned res = power(n, k / 2);
		return res * res;
	}
	else
	{
		return n * pow(n, k - 1);
	}
}



int main()
{
	cout << power(3, 5);

} 
