//Compare for time! See the difference!

int LevensteinDistanceRec(string str1, string str2, int m, int n)
{
	if (m == 0) 
		return n;
	if (n == 0) 
		return m;
	if (str1[m - 1] == str2[n - 1])
		return LevensteinDistanceRec(str1, str2, m - 1, n - 1);


	return 1 + min(LevensteinDistanceRec(str1, str2, m, n - 1),    // Insert 
		LevensteinDistanceRec(str1, str2, m - 1, n),   // Remove 
		LevensteinDistanceRec(str1, str2, m - 1, n - 1) // Replace 
);
}
int LevensteinDistanceDP(string str1, string str2, int n, int m)
{ 
	int** dp = createMatrix(n+1, m+1);

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			
			if (i == 0)
				dp[i][j] = j;  
			else if (j == 0)
				dp[i][j] = i; 
			else if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = 1 + min(dp[i][j - 1],  // Insert 
				dp[i - 1][j],  // Remove 
				dp[i - 1][j - 1]); // Replace 
		}
	}
	//printMatrix(dp, n+1, m+1);
	int result = dp[n][m];
	deleteMatrix(dp,n+1);
	return result;
}

int main()
{

}
