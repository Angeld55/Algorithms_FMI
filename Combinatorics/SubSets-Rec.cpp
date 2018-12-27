#include <iostream>

const int MAX = 20;
void PrintIt(const int* arr, int len)
{
	for (int i = 0; i < len; i++)
		std::cout << arr[i]<<" ";
	std::cout<<std::endl;
}
void SubSets(int B[], int n, int pos)
{
	if (pos == n)
		PrintIt(B, n);
	else
	{
		B[pos] = 0;
		SubSets(B, n, pos + 1);
		B[pos] = 1;
		SubSets(B, n, pos + 1);
	}
}
int main()
{
	// All bitstrings of subsets

	int B[MAX+1];
	unsigned int n;
	std::cin>> n;
	
	if (n > 20)
		return -1; //too large

	for (int i = 0; i < MAX+1; i++)
		B[i] = 0;  //first bitstring 0000...
	
	SubSets(B, n, 0);

}