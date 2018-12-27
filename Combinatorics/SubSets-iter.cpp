#include <iostream>

const int MAX = 20;
void PrintIt(const int* arr, int len)
{
	for (int i = 0; i < len; i++)
		std::cout << arr[i]<<" ";
	std::cout<<std::endl;
}
bool Next(int B[], int n)
{
	int k = n - 1;
	while (k >= 0 && B[k] == 1)
		B[k--] = 0;
	if (k < 0)
		return false;
	B[k] = 1;
	return true;
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
	

	bool res = true;
	do
	{
		PrintIt(B, n); 
		res = Next(B, n);
	} while (res);

}