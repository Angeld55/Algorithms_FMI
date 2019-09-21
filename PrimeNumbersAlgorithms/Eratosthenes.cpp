#include <iostream>
void Eratosthenes(unsigned n)
{
	bool* nums = new bool[n];
	for (int i = 0; i < n; i++) //unnecessary
		nums[i] = true;

	for (int i = 2; i <n; i++)
	{
		if (!nums[i])
			continue;
		int index = i+i;
		while (index < n)
		{
			nums[index] = false;
			index += i;
		}
		
	}
	for (int i = 2; i < n; i++)
	{
		
		if (nums[i])
			std::cout << i<< " ";
	}

}
int main() {
	Eratosthenes(300);  // 2 3 5 7 11........... 191 193 197 199

}
