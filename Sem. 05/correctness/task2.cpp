#include <iostream>
#include <fstream>

using namespace std;
 
int taskMystery(unsigned x, unsigned y);


int main()
{

	cout << taskMystery(5, 4);
}




int taskMystery(unsigned int x, unsigned y)
{
	unsigned int z = x;
	unsigned t = y;
	unsigned p = 1;

	while (t > 0)
	{
		if (t % 2 == 0)
		{
			z = z*z;
			t =  t / 2;
		}
		else
		{
			p = p * z;
			t = t - 1;
		}
	}
	return p;
}
