#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

//recursive
size_t catalanRec(int n)
{

	if (n <= 1)
		return 1;
	size_t res = 0;

	for (int i = 0; i<n; i++)
		res += catalanRec(i) * catalanRec(n - i - 1);
	
	return res;
}

//DP
unsigned long int CatalanDP(unsigned int n)
{

	std::vector<size_t> CAT_DP(n + 1);
	
	CAT_DP[0] = CAT_DP[1] = 1;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j<i; j++)
			CAT_DP[i] += CAT_DP[j] * CAT_DP[i - j - 1];
	}
	return CAT_DP[n];
}

//Memoization
size_t catalanMem(int n, std::vector<size_t>& mem)
{

	if (n <= 1)
		return 1;

	if (mem[n] != 0)
		return mem[n];

	size_t res = 0;

	for (int i = 0; i<n; i++)
		res += catalanRec(i) * catalanRec(n - i - 1);

	mem[n] = res;
	return res;
}


//сравнение за време
//time comparison
int main()
{
	const int N = 15;

	auto begin = clock();

	cout << catalanRec(N) << endl;

	auto end = clock();
	auto elapsed_secs = double(end - begin);
	cout << "Rec: " << elapsed_secs << endl;

	begin = clock();

	cout << CatalanDP(N) << endl;

	end = clock();
	elapsed_secs = double(end - begin);
	cout << "With DP: " << elapsed_secs << endl;

	begin = clock();

	std::vector<size_t> mem(N + 1);
	cout << catalanMem(N, mem) << endl;

	end = clock();
	elapsed_secs = double(end - begin);
	cout << "With memoization: " << elapsed_secs << endl;
}
