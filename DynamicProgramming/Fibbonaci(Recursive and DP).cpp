
unsigned long Fibb(int n)
{
	if (n <= 1)
		return 1;
	return Fibb(n - 1) + Fibb(n - 2);
}
unsigned long FibbDP(int n)
{
	unsigned long * f = new unsigned long [n + 1];
	int i;
	f[0] = 1;
	f[1] = 1;

	for (i = 2; i <= n; i++)	
		f[i] = f[i - 1] + f[i - 2];
	int res = f[n];
	delete[] f;
	return res;
}
// сравнение за време! Има и 3-ти начин (с мемоизация).

int main()
{
	
	begin = clock();

	cout << Fibb(25)<<endl;

	end = clock();
	elapsed_secs = double(end - begin);
	cout << "No DP: "<<elapsed_secs << endl;

	begin = clock();

	cout << FibbDP(25)<<endl;

	end = clock();
	elapsed_secs = double(end - begin);
	cout << "With DP: " << elapsed_secs<<endl;
}
