#include <iostream>
#include <vector>

using namespace std;
//We need to find the largest subsequence of increasing numbers within a given sequence
//The subsequence is not necessarily unique or contiguous


int longestIncreesingSubsequenceHelper(const vector<int>& arr, int end);

//Recursive
int longestIncreesingSubsequenceRec(const vector<int>& arr, int len)
{
	int max = -1;
	for (int i = 1; i < len; i++) {
		int curr = longestIncreesingSubsequenceHelper(arr, i);
		if (curr>max)
			max = curr;
	}
	return max;
}
int longestIncreesingSubsequenceHelper(const vector<int>& arr, int end)
{
	if (end == 0)
		return 1;

	int maxPath = 1;
	for (int i = end - 1; i >= 0; i--)
	{
		if (arr[end] > arr[i])
		{
			int path = longestIncreesingSubsequenceHelper(arr, i) + 1;
			if (path > maxPath)
				maxPath = path;
		}
	}
	return maxPath;
}

//With DP
int longestIncreesingSubsequenceDyn(const vector<int>& arr, vector<int>& path)
{
	vector<int> dyn(arr.size());
	vector<int> prev(arr.size());

	for (int i = 0; i < arr.size(); i++)
	{
		int max = 0;
		int prevIndex = -1;
		for (int j = i - 1; j >= 0; j--)
		{
			if (arr[j]< arr[i] && dyn[j] > max)
			{
				max = dyn[j];
				prevIndex = j;
			}
		}
		dyn[i] = max + 1;
		prev[i] = prevIndex;

	}

	//find max
	int max = -1;
	int maxInd = -1;
	for (int i = 0; i < dyn.size(); i++) 
	{
		if (dyn[i] > max)
		{
			max = dyn[i];
			maxInd = i;
		}
	}

	//path
	int pathIter = maxInd;
	while (prev[pathIter] != -1)
	{
		path.push_back(arr[pathIter]);
		pathIter = prev[pathIter];
	}
	std::reverse(path.begin(), path.end());

	return max;
}
int main()
{
	//compare for time for bigger arrays
	vector<int>  arr = { 3, 14, 5, 12, 15, 7, 8, 9, 11, 10, 1 };
	std::cout << longestIncreesingSubsequenceRec(arr, arr.size()) << std::endl;

	vector<int> path;
	std::cout << longestIncreesingSubsequenceDyn(arr, path) << std::endl;

	for (int i = 0; i < path.size(); i++)
		cout << path[i] << " ";
}
