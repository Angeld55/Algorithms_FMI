#include <iostream>
#include <vector>
using namespace std;

unsigned long long task4(unsigned n)
{
	if (n == 15)
		return 1307674368000;
			   
	return task4(n + 1) / (n + 1);

}

int main()
{
	cout << task4(5);

} 
