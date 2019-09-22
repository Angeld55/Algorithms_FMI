int** createMatrix(int n, int m)
{
	int** res = new int*[n];
	for (int i = 0; i < n; i++)
		res[i] = new int[m];
	return res;
}
void deleteMatrix(int** m,int n)
{
	for (int i = 0; i < n; i++)
		delete m[i];
	delete[] m;
}
void printMatrix(int** m, int rows, int colls)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colls; j++)
			std::cout << m[i][j] << " ";
		std::cout << std::endl;
	}
}
int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
