#include <iostream>
#include <chrono>

using namespace std;


void f(int n)
{
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			num++;
	}

}
void measureAndPrint(int n)
{
	auto begin = std::chrono::high_resolution_clock::now();
	f(n);
	auto end = std::chrono::high_resolution_clock::now();
	cout << "n = " << n << ", Time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "ns" << std::endl;
}
int main()
{
	measureAndPrint(500);
	measureAndPrint(5000);
	measureAndPrint(50000);
	measureAndPrint(500000);
	measureAndPrint(5000000);


	
}