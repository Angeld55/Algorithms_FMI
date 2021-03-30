#include <iostream>
#include <fstream>

using namespace std;
 
int taskMystery(int x, int y);


int main()
{

	cout << taskMystery(5, 4);
}




int taskMystery(int x, int y)
{
	int z = x;
	int t = y;
	int p = 1;

	while (t > 0)
	{
		if (t % 2 == 0)
		{
			z = z*z;
			t =  t/2;
		}
		else
		{
			p = p * z;
			t = t - 1;
		}
	}
	return p;
}
