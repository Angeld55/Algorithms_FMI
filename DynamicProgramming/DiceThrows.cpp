#include "HelpFunctions.hpp"
using namespace std;

//Given n dice each with m faces, numbered from 1 to m, 
//We need to find the number of ways to get sum X.
// X is the sum of values on each face when all the dice are thrown.


int DiceThrows(int n, int m, int x)
{
	int** table = createMatrix(n+1, x+1);
	for (int j = 1; j <= m && j <= x; j++)
		table[1][j] = 1;

	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= x; j++)
			for (int k = 1; k <= m && k < j; k++)
				table[i][j] += table[i - 1][j - k];

	int res = table[n][x];
	deleteMatrix(table,n);
	return res;
}
int main()
{
	cout << DiceThrows(3, 6, 8);
}
