#include<iostream>
#include "HelpFunctions.hpp"
using namespace std;

int longestPalindromicSubsequence(string str)
{
	int n = str.size();
	int** DP = createMatrix(n, n);
	for (int i = 0; i < n; i++)
		DP[i][i] = 1;

	for (int len = 2; len <= n; len++)
	{
		for (int i = 0; i < n-len+1; i++)
		{
			int j = i + len - 1;
			if (str[i] == str[j] && len == 2)
				DP[i][j] = 2;
			else if (str[i] == str[j])
				DP[i][j] = DP[i + 1][j - 1] + 2;
			else
				DP[i][j] = max(DP[i][j - 1], DP[i + 1][j]);
		}

	}
	int res = DP[0][n-1];
	deleteMatrix(DP, n);
	return res;
}
int main()
{
	cout << longestPalindromicSubsequence("ABCDBGA");
}
