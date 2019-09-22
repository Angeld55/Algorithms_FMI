#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

const int BITS = 4;

//Help functions
void PrintInBinary(int n)
{
	bitset<BITS> x(n);
	cout << x << endl;
}
template<typename T>
void PrintVector(const vector<T>& v, bool newLine)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];
		if (newLine)
			cout << endl;
	}
	cout << endl;

}
void ConcatCharToVector(vector<string>& v, char ch)
{
	for (int i = 0; i < v.size(); i++)
		v[i] = ch + v[i];
}

//standard subset alg
bool Next(vector<bool>& v)
{
	int ind = v.size() - 1;
	while (ind >= 0 && v[ind])
	{
		v[ind] = 0;
		ind--;
	}
	if (ind < 0)
		return true;

	v[ind] = 1;

	return false;


}
void SubSetGen(int n)
{
	vector<bool> s;
	for (int i = 0; i < n; i++) //add first subset - 000000...0
		s.push_back(0);
	bool done;
	do
	{
		PrintVector(s, false);
		done = Next(s);
	} while (!done);
}

vector<string> BRGC_rec(int n)
{
	if (n == 0)
	{
		vector<string> result;
		result.push_back("");
		return result;
	}
	vector<string> brgcN1 = BRGC_rec(n - 1);

	vector<string> f1 = brgcN1;
	ConcatCharToVector(f1, '0');


	vector<string> f2 = brgcN1;
	reverse(f2.begin(), f2.end());
	ConcatCharToVector(f2, '1');

	f1.insert(f1.end(), f2.begin(), f2.end()); //concat the two vectors.

	return f1;
}
void BRGC_RECURSIVE_PRINT(int n)
{
	vector<string> res = BRGC_rec(n);
	PrintVector(res, true);
}

// fast generating with XOR.
void BRGC_XOR_Fast(int n)
{
	int count = pow(2, n);
	for (int i = 0; i < count; i++)
	{
		int GC = i ^ (i >> 1);
		PrintInBinary(GC);
	}
}
int main()
{
	//SubSetGen(BITS);

	//BRGC_RECURSIVE_PRINT(BITS);

	BRGC_XOR_Fast(BITS);
}
