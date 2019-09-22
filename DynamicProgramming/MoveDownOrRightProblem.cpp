#include <iostream>
using namespace std;

int MoveDownOrRightRec(int** matrix,int endX,int endY)
{

	if(endX==0 && endY==0)
		return matrix[0][0];
	else if(endX==0)
		return MoveDownOrRightRec(matrix,endX,endY-1) + matrix[endX][endY];
	else if(endY==0)
		return MoveDownOrRightRec(matrix,endX-1,endY) + matrix[endX][endY];
	else
	   return max(MoveDownOrRightRec(matrix,endX-1,endY),MoveDownOrRightRec(matrix,endX,endY-1))+matrix[endX][endY];

}
int MoveDownOrRightDP(int** m, int rows,int colls)
{
	int** DP = createMatrix(rows, colls);

	DP[0][0] = m[0][0];
	for (int i = 1; i < colls; i++)
		DP[0][i] = DP[0][i - 1] + m[0][i];

	for (int i = 1; i < rows; i++)
		DP[i][0] = DP[i - 1][0] + m[i][0];


	for (int row = 1; row < rows; row++)
	{
		for (int col = 1; col < colls; col++)
		{
			int better = max(DP[row - 1][col], DP[row][col - 1]);
			DP[row][col] = better + m[row][col];
		}

	}
    //printMatrix(DP, 3, 3);
	int res = DP[rows - 1][colls - 1];
	deleteMatrix(DP, 3);
	return res;
}


int main()
{
    int** arr = createMatrix(3, 3);
        
        
    for(int i =0;i<3;i++)
    {
        arr[0][i]=i;
        arr[1][2-i]=i;
        arr[2][2-i]=-1*i*i;
    }

    cout << MoveDownOrRightRec(arr, 2, 2);
    cout << MoveDownOrRightDP(arr, 3, 3);
    //Compare for larger matricies and see the difference
	
    deleteMatrix(arr,3);		
}
