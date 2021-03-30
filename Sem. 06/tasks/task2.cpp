#include <iostream>

using namespace std;

unsigned int reverse(unsigned int n)
{
	int result = 0;

	int temp = n;
	while (temp != 0)
	{
		int lastDigit = temp % 10; //extract last digit.

		(result *= 10) += lastDigit; //concat last digit in the end of the result
		temp /= 10;
	}

	return result;
}

int main()
{
	cout << reverse(1234);
}