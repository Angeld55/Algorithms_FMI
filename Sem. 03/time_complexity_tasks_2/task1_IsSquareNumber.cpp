#inlude <iostream>

bool isPowerOfTwo(int n)
{
	while (n > 1)
	{
		if (n % 2 == 1)
			return false;
		n /= 2;
	}
	return true;
}

int main()
{
	
}