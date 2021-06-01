#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//You are given a matrix of numbers.
//Find the largest sum of cells
//starting from the top left corner
//ending at the bottom right corner
//going down or right at each step

int MoveDownOrRightRec(const vector<vector<int>>& matrix, int endX, int endY)
{

	if (endX == 0 && endY == 0)
		return matrix[0][0];
	else if (endX == 0)
		return MoveDownOrRightRec(matrix, endX, endY - 1) + matrix[endX][endY];
	else if (endY == 0)
		return MoveDownOrRightRec(matrix, endX - 1, endY) + matrix[endX][endY];
	else
		return max(MoveDownOrRightRec(matrix, endX - 1, endY), MoveDownOrRightRec(matrix, endX, endY - 1)) + matrix[endX][endY];

}

void print(const vector<vector<int>>& m)
{
	for (int i = 0; i < m.size(); i++)
	{
		for (int j = 0; j < m[0].size(); j++)
			cout << m[i][j] << "   ";
		cout << endl;
	}
	cout << endl << endl << endl;
}

std::vector<int> getPath(const vector<vector<int>>& matrix, const vector<vector<int>>& DP)
{
	std::vector<int> path;

	int currentRow = matrix.size() - 1;
	int currentCol = matrix[0].size() - 1;

	path.push_back(matrix[currentRow][currentCol]);

	while (currentRow != 0 || currentCol != 0)
	{
		if (currentRow == 0)
			path.push_back(matrix[currentRow][--currentCol]);
		else if (currentCol == 0)
			path.push_back(matrix[--currentRow][currentCol]);
		else
		{
			if (DP[currentRow - 1][currentCol] > DP[currentRow][currentCol - 1])
				path.push_back(matrix[--currentRow][currentCol]);
			else
				path.push_back(matrix[currentRow][--currentCol]);
		}
	}
	std::reverse(path.begin(), path.end());
	return std::move(path);
}

int MoveDownOrRightDP(const vector<vector<int>>& matrix, std::vector<int>& path)
{
	int rows = matrix.size();
	if (rows == 0)
		return 0;

	int colls = matrix[0].size();

	vector<vector<int>> DP;
	DP.resize(rows, vector<int>(colls));

	DP[0][0] = matrix[0][0];
	for (int i = 1; i < colls; i++)
		DP[0][i] = DP[0][i - 1] + matrix[0][i];

	for (int i = 1; i < rows; i++)
		DP[i][0] = DP[i - 1][0] + matrix[i][0];


	for (int row = 1; row < rows; row++)
	{
		for (int col = 1; col < colls; col++)
		{
			int better = std::max(DP[row - 1][col], DP[row][col - 1]);
			DP[row][col] = better + matrix[row][col];
		}

	}

	int res = DP[rows - 1][colls - 1];

	cout << "DP matrix: " << endl;
	print(DP);

	path = getPath(matrix, DP);

	return res;
}

int main()
{
	std::vector<std::vector<int>> matrix = { { 8, 10, 16, 8 }, { 11, 19, 1, 6 }, { 4, 7, 5, 18 }, {15, 20, 17, 3} };

	print(matrix);

	cout << "Rec. result: " << MoveDownOrRightRec(matrix, matrix.size()-1, matrix[0].size()-1) << endl << endl;

	std::vector<int> path;
	cout << MoveDownOrRightDP(matrix, path) << endl << endl;

	cout << "Path:" << endl;
	for (int i = 0; i < path.size(); i++)
		cout << path[i] << (i == path.size() -1 ? "" : " -> ");
	cout << endl;

}
