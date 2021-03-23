#include <iostream>
using namespace std;

template <class T>
bool linearSearch(const T* arr, int len, T searched)
{
	if (len == 0)
		return false;
	
	return  arr[0] == searched || linearSearch(++arr, --len, searched);

}
int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	cout << linearSearch<int>(arr, 5, 9);
}