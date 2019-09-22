#include <iostream>

//We need to find the largest subsequence of increasing numbers within a given sequence
//The subsequence is not necessarily unique or contiguous


int LongestIncreesingSubsequenceHelper(int* arr, int end);

//Recursive
int LongestIncreesingSubsequenceRec(int* arr,int len)
{
	int max = -1;
	for (int i = 1; i < len; i++) {
		int curr = LongestIncreesingSubsequenceHelper(arr,i);
		if(curr>max)
			max=curr;
	}
	return max;
}
int LongestIncreesingSubsequenceHelper(int* arr, int end)
{
	if(end==0)
		return 1;

	int maxPath = 1;
	for (int i = end-1; i >= 0; i--)
	{
		if(arr[end] > arr[i])
		{
			int path = LongestIncreesingSubsequenceHelper(arr,i) + 1;
			if(path > maxPath)
				maxPath=path;
		}
	}
	return maxPath;
}

//With DP
int LongestIncreesingSubsequenceDyn(int* arr, int len)
{
	int* dyn = new int[len];


	for (int i = 0; i < len; i++)
	{
		int max =0 ;
		for (int j = i-1; j >=0 ; j--)
		{
			if(arr[j]< arr[i] && dyn[j]>max)
				max=dyn[j];
		}
		dyn[i]=max+1;

	}
	int max = -1;
	for (int i = 0; i < len; i++) {
		if(dyn[i]>max)
			max=dyn[i];
	}
	delete[] dyn;

	return max;

}
int main()
{
 //compare for time for bigger arrays
 int arr[] = {1,2,3,-5,-4,-3,-2,5,6};
 std::cout<<LongestIncreesingSubsequenceRec(arr,9)<<std::endl;
 std::cout<<LongestIncreesingSubsequenceDyn(arr,9)<<std::endl;
}
