#include <iostream>

//There is a subset A of n positive integers and a value sum.
//Find whether or not there exists any subset of the given set, 
//the sum of whose elements is equal to the given value of sum.

bool subsetSum(int* arr, int n, int sum)
{
	
	bool** dyn  = new bool*[n + 1];
  for(int i = 0; i<n+1;i++)
    dyn[i] = new bool[sum+1];

	
	for (int j = 1; j <= sum; j++)
		dyn[0][j] = false;


	for (int i = 0; i <= n; i++)
		dyn[i][0] = true;

	for (int i = 1; i <= n; i++)
	{

		for (int j = 1; j <= sum; j++)
		{
			if (arr[i - 1] > j)
				dyn[i][j] = dyn[i - 1][j];
			else
				dyn[i][j] = dyn[i - 1][j] || dyn[i - 1][j - arr[i - 1]];
		}
	}


	return dyn[n][sum];
}
int main()
{
	// Input: set of items and a sum
	int arr[] = { 1,2,3,4,5 };




	std::cout<<subsetSum(arr, 5, 4);

}
