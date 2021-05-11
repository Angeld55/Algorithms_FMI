#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
const int ENGLISH_ALPHABET_SIZE = 26;

std::string sortString(const std::string& str)
{
	vector<size_t> hist(ENGLISH_ALPHABET_SIZE);

	for (int i = 0; i < str.size(); i++)
		hist[str[i] - 'a']++;

	for (int i = 1; i < hist.size(); i++)
		hist[i] += hist[i - 1];

	std::string res(str.size(), ' ');
	

	for (int i = 0; i < str.size(); i++)
	{
		size_t index = --hist[str[i] - 'a'];
		res[index] = str[i];
	}
	return res;
}
int main()
{
	std::string res = sortString("bcdade");

	std::cout << res;
}
