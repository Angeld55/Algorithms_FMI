#include <iostream>
using namespace std;

const int SizeOfBoard = 8;
const int necesseryMoves = (SizeOfBoard*SizeOfBoard)-1;

void print(int visited[][SizeOfBoard])
{
	for (int i = 0; i<SizeOfBoard; i++)
	{
		for (int j = 0; j<SizeOfBoard; j++)
		{
			cout << visited[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
}
static int count = 0;
bool CheckPath(int x, int y, int Size, int visited[][SizeOfBoard], int moves)
{
	if ((x < 0) || (x >= Size) || (y < 0) || (y >= Size))
		return false;
	
	if (visited[x][y]>0)
		return false;
	

	if (moves == necesseryMoves)
	{
		visited[x][y] = moves;
		print(visited);
		return true;
	}
	
	visited[x][y] = moves;
		
	bool res = false;
	int xMovement[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int yMovement[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	for (int i = 0; i<8 && !res; i++)
		res = CheckPath(x + xMovement[i], y + yMovement[i], Size, visited, moves + 1);
	
	if (res)
	{
		visited[x][y] = 0;
		return true;
	}
	visited[x][y] = 0;
	return false;
		
	
}
int main()
{
	int visitedFeilds[SizeOfBoard][SizeOfBoard] = { 0 };

	cout << CheckPath(0, 0, SizeOfBoard, visitedFeilds, 0);


}
