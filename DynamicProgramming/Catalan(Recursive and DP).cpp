unsigned long int Catalan(int n)
{

	if (n <= 1) 
		return 1;
	unsigned long int res = 0;
	for (int i = 0; i<n; i++)
		res += Catalan(i)*Catalan(n - i - 1);
	return res;
}
unsigned long int CatalanDP(unsigned int n)
{
	unsigned long*  CAT = new unsigned long[n + 1];

	CAT[0] = CAT[1] = 1;
	
	for (int i = 2; i <= n; i++)
	{
		CAT[i] = 0;
		for (int j = 0; j<i; j++)
			CAT[i] += CAT[j] * CAT[i - j - 1];
	}
	int res = CAT[n];
	delete[] CAT;
	return res;
}

//сравнение за време
//time comparison
int main()
{
	begin = clock();

	cout << Catalan(20)<<endl;

	end = clock();
	elapsed_secs = double(end - begin);
	cout << "No DP: "<<elapsed_secs << endl;

	begin = clock();

	cout << CatalanDP(20)<<endl;

	end = clock();
	elapsed_secs = double(end - begin);
	cout << "With DP: " << elapsed_secs<<endl;
}
