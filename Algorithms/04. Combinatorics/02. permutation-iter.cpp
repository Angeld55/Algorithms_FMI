

#include <iostream>
#include <vector>

using namespace std;

void print(const std::vector<int>& arr)
{
    for(size_t i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

bool next(std::vector<int>& arr)
{
    if(arr.size() <= 1)
        return false;
	
    int k = arr.size() - 2;
    while(k >= 0 && arr[k] > arr[k+1])
        k--;
        
    if(k < 0)
        return false;
        
    size_t j = arr.size() - 1;
    
    while(j>=0 && arr[k] > arr[j])
        j--;
        
    std::swap(arr[k], arr[j]);
    size_t r = arr.size() - 1;
    size_t s = k + 1;
    
    while(r > s)
        std::swap(arr[r--],arr[s++]);
        
    return true;
}

void genAllPermutations(std::vector<int> v)
{
    do
    {
        print(v);
        
    }  while(next(v)); 
}



int main()
{
	std::vector<int> v{1, 2, 3, 4, 5, 6};
    
	genAllPermutations(v);

}

