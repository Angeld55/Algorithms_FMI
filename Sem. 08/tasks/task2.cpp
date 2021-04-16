#include <iostream>
#include "Person.h"
using namespace std;

unsigned task2(unsigned n)
{
	if (n == 0)
		return 0;

	if (n % 2 == 0)
		return task2(n - 2) + 1;
	else
		return task2(n + 3) - 1;	
}
 
 
 
int main()
{
	cout << task2(10);

} 
