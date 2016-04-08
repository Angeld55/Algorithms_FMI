#include <iostream>;
using namespace std;

const int SizeOfBoard = 4;
const int necesseryMoves = (SizeOfBoard*SizeOfBoard) - 1;

bool CheckPath(int x,int y,int Size, bool visited[][SizeOfBoard],int moves)
{
	
	if ((x<0) || (x >= Size) || (y<0) || (y >= Size))
	{
		return false;
	}
	if (visited[x][y]==true)
	{
		
		return false;
	}
	if (moves == necesseryMoves)
	{
		cout << x << y << endl;
		visited[x][y] = true;
	
	}
	else
	{
		visited[x][y] = true;
		bool res = false;
		res = (res || (CheckPath(x + 2, y + 1, Size, visited, moves + 1)));
		if (res == false)
		{
			res = (res || (CheckPath(x + 2, y - 1, Size, visited, moves + 1)));
		}
		if (res == false){
			res = (res || (CheckPath(x - 2, y + 1, Size, visited, moves + 1)));
	}
		if (res == false)
		{
			res = (res || (CheckPath(x - 2, y - 1, Size, visited, moves + 1)));
	    }
		if (res == false){
			res = (res || (CheckPath(x + 1, y + 2, Size, visited, moves + 1)));
	}
		if (res == false){
			res = (res || (CheckPath(x + 1, y - 2, Size, visited, moves + 1)));
	}
		if (res == false){
			res = (res || (CheckPath(x - 1, y + 2, Size, visited, moves + 1)));
	}
		if (res == false){
			res = (res || (CheckPath(x - 1, y - 2, Size, visited, moves + 1)));
		}
		if (res==true)
		{
			cout << x <<"---"<< y << endl;
			
			
			return true;
		}
		else
		{
			visited[x][y] = false;
			return false;
		}
	}
}
int main()
{
	cout << "c++";
	bool visitedFeilds[SizeOfBoard][SizeOfBoard] = { false };


	if (CheckPath(0, 0, SizeOfBoard, visitedFeilds, 0) == true)
	{
		cout << "true";
	}
	else
	{
		cout << "false";
	}

	int x;
	cin >> x;
}
