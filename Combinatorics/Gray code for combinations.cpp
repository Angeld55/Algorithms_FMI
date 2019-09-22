#include <iostream>
#include <string>
#include <vector>

using namespace std;

void PrintVector(const vector<string>& v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
	cout << endl;

}
void ConcatCharToVector(vector<string>& v, char ch)
{
	for (int i = 0; i < v.size(); i++)
		v[i] += ch;
}


vector<string> Comb(int n, int k)
{
	if (k == 0)
	{
		vector<string> res;
		string s(n, '0');
		res.push_back(s);
		return res;
	}
	else if (k == n)
	{
		vector<string> res;
		string s(n, '1');
		res.push_back(s);
		return res;
	}
	vector<string> f1 = Comb(n - 1, k);
	vector<string> f2 = Comb(n - 1, k - 1);

	ConcatCharToVector(f1, '0');
	ConcatCharToVector(f2, '1');

	reverse(f2.begin(), f2.end());

	f1.insert(f1.end(), f2.begin(), f2.end()); //concat the two vectors.

	return f1;
}
void COMB_RECURSIVE_PRINT(int n, int k)
{
	vector <string> result = Comb(n, k);
	PrintVector(result);
}
void gen(int, int);
void neg(int, int);
void gen(int n, int k)
{
	if (0<k& k<n)
	{
		gen(n - 1, k);
		if (k == 1)
			cout << "Swap " << n << " " << (n - 1) << endl;
		else
			cout << "Swap " << n << " " << (k - 1) << endl;
		neg(n - 1, k - 1);
	}
}
void neg(int n, int k)
{
	if (0<k & k <n)
	{
		gen(n - 1, k - 1);
		if (k == 1)
			cout << "Swap " << n << " " << (n - 1) << endl;
		else
			cout << "Swap " << n << " " << (k - 1) << endl;
		neg(n - 1, k);
	}
}

int main()
{
	COMB_RECURSIVE_PRINT(4, 2);
	//gen(4, 2);
}
