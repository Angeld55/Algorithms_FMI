#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


//Compare for time! See the difference!
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

int levensteinDistanceRec(const string& str1, const string& str2, int m, int n)
{
	if (m == 0)
		return n;
	if (n == 0)
		return m;
	if (str1[m - 1] == str2[n - 1])
		return levensteinDistanceRec(str1, str2, m - 1, n - 1);


	return 1 + min({ levensteinDistanceRec(str1, str2, m, n - 1),    // Insert 
		levensteinDistanceRec(str1, str2, m - 1, n),   // Remove 
		levensteinDistanceRec(str1, str2, m - 1, n - 1) } // Replace 
		);
}
int levensteinDistanceDP(const string& str1, const string& str2)
{

	int n = str1.size();
	int m = str2.size();

	vector<vector<int>> DP;
	DP.resize(n + 1, vector<int>(m + 1));

	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (i == 0)
				DP[i][j] = j;
			else if (j == 0)
				DP[i][j] = i;
			else if (str1[i - 1] == str2[j - 1])
				DP[i][j] = DP[i - 1][j - 1];
			else
				DP[i][j] = 1 +
				min({DP[i][j - 1],  // Insert 
				DP[i - 1][j],  // Remove 
				DP[i - 1][j - 1]  // Replace 
				});
		}
	}
	//print(DP);

	return DP[n][m];

}

int main()
{
	cout << levensteinDistanceRec("abcd", "abcd", 4, 4);
}
