#include <iostream>

const int MAX = 20;
void PrintIt(const int* B, int len)
{
	for (int i = 0; i < len; i++)
		std::cout << B[i] << " ";
	std::cout << std::endl;
}
bool Next(int* B, int n, int k)
{
	int j = k - 1;
	while (j >= 0 && B[j] == n - k + j + 1)  //n-k+j+1 - the max el possible for position j
		j--;
	if (j < 0)
		return false;
	B[j]++;
	for (int i = j + 1; i < k; i++)
		B[i] = B[i - 1] + 1;
	return true;
}
int main()
{
	// All bitstrings of subsets

	int B[MAX + 1];
	int n, k;
	std::cin >> n >> k;
	//B[0] = 0;//santinel
	for (int i = 0; i < k; i++)
		B[i] = i + 1;

	bool res = true;
	do
	{
		PrintIt(B, k);
		res = Next(B, n, k); //we scan from the right for the rightmost index j whose corresponding element can be increased

	} while (res);

	while (true){}

}