#include <iostream>
#include <vector>

using namespace std;

//There is a subset A of n positive integers and a value sum.
//Find whether or not there exists any subset of the given set, 
//the sum of whose elements is equal to the given value of sum.

void print(const vector<vector<bool>>& m)
{
	cout << "      ";
	for (int i = 0; i < m[0].size(); i++)
		cout << i << "   ";
	cout << endl << endl << endl;

	for (int i = 0; i < m.size(); i++)
	{
		cout << i << "      ";
		for (int j = 0; j < m[0].size(); j++)
			cout << m[i][j] << "   ";
		cout << endl;
	}
	cout << endl << endl << endl;
}
bool subsetSum(const vector<int>& arr, int sum, vector<int>& subset)
{
	int rows = arr.size() + 1;
	int colls = sum + 1;

	vector<vector<bool>> DP;
	DP.resize(rows, vector<bool>(colls));


	for (int j = 1; j <= sum; j++)
		DP[0][j] = false;


	for (int i = 0; i <= arr.size(); i++)
		DP[i][0] = true;

	for (int i = 1; i <= arr.size(); i++)
	{

		for (int j = 1; j <= sum; j++)
		{
			if (arr[i - 1] > j)
				DP[i][j] = DP[i - 1][j];
			else
				DP[i][j] = DP[i - 1][j] || DP[i - 1][j - arr[i - 1]];
		}
	}

	print(DP);

	//recover elements

	if (!DP[arr.size()][sum])
		return false;

	int sumForRecovery = sum;
	for (int i = arr.size()-1; i >= 0 && sum > 0; i--)
	{
		if (sumForRecovery - arr[i] < 0)
			continue;
		if (DP[i][sumForRecovery - arr[i]])
		{
			subset.push_back(arr[i]);
			sumForRecovery -= arr[i];
		}
	}


	return DP[arr.size()][sum];

}
int main()
{
	// Input: set of items and a sum
	vector<int> arr = { 1, 2, 3, 4, 5 };

	vector<int> result; //if exists
	std::cout << subsetSum(arr, 10, result) <<endl;

	for (int i = 0; i < result.size(); i++)
		std::cout << result[i] << "  ";

}
