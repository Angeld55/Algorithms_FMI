#include <iostream>
#include <string>
 
using namespace std;
 
bool isPerfectSquare(int n)
{
    if(n != 0)
	   return (n & (n - 1)) == 0;    
    return true;
}
 
int g(int n)
{
    if(isPerfectSquare(n))
    {
     int sum = 0;
      
     for(int i = n; i >= 0; i--)
        sum++;
     return sum;    
    }
    else
        return 0;
}
int f(int n)
{
    int res = 0;
    for(int i = 0; i < n; i++)
        res += g(i);
    return res;
}
 
int main()
{
    cout << f(17);
}