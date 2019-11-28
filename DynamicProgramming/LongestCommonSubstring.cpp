#include<iostream>
#include <string>
#include "HelpFunctions.h"

using namespace std;


int LongestCommonSubstring(string str1, string str2)
{
	int** DP = createMatrix(str1.size() + 1, str2.size() + 1);
	int ret = 0;
	
	for (int i = 0; i <= str1.size(); i++)
		DP[i][0] = 0;
	for (int i = 0; i <= str2.size(); i++)
		DP[0][i] = 0;

	for (int i = 1; i <= str1.size(); i++)
	{
		for (int j = 1; j <= str2.size(); j++)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				DP[i][j] = DP[i - 1][j - 1] + 1;
				if (DP[i][j]>ret)
					ret = DP[i][j];
			}
			else
				DP[i][j] = 0;
		}

	}
	deleteMatrix(DP, str1.size());
	return ret;
}

int main()
{
	cout << LongestCommonSubstring("baab", "cccaab");
}
