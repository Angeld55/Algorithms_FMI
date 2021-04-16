#include <iostream>
#include <vector>
using namespace std;

unsigned power(unsigned n, unsigned k)
{
	if (k == 0)
		return 1;
	return n * power(n, k - 1);
}

unsigned task3(unsigned n)
{
	if (n == 0)
		return 1;

	unsigned res = task3(n - 1) + task3(n - 1);

	if (n % 2 == 1)
		res += power(task3(n / 2), 2);
	else
		res += 3 * power( task3((n-1) / 2), 2);

	return res;
}
 
 
 
int main()
{
	cout << task3(4);

} 
