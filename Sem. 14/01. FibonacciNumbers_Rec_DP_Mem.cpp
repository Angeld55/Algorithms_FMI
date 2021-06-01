#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

//recirsive
size_t Fibb(int n)
{
	if (n <= 1)
		return 1;
	return Fibb(n - 1) + Fibb(n - 2);
}

//DP
size_t FibbDP(int n)
{
	vector<size_t> f(n+1);
	int i;
	f[0] = 1;
	f[1] = 1;

	for (i = 2; i <= n; i++)
		f[i] = f[i - 1] + f[i - 2];
	int res = f[n];

	return res;
}

//Memoization

size_t FibbMemoization(int n, std::vector<size_t>& mem)
{
	if (n <= 1)
		return 1;

	if (mem[n] != 0)
		return mem[n];
	
	size_t currentNumber = FibbMemoization(n - 1, mem) + FibbMemoization(n - 2, mem);
	mem[n] = currentNumber;
	
	return currentNumber;
}

int main()
{

	const int N = 20;

	auto begin = clock();

	cout << Fibb(N) << endl;

	auto end = clock();
	auto elapsed_secs = double(end - begin);
	cout << "No DP: " << elapsed_secs << endl;

	begin = clock();

	cout << FibbDP(N) << endl;

	end = clock();
	elapsed_secs = double(end - begin);
	cout << "With DP: " << elapsed_secs << endl;

	begin = clock();

	std::vector<size_t> mem(N+1);
	cout << FibbMemoization(N, mem) << endl;

	end = clock();
	elapsed_secs = double(end - begin);
	cout << "With Memoization: " << elapsed_secs << endl;
}
