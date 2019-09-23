#include<iostream>
#include <cmath>

using namespace std;
bool isPrime(int n)
{
    double temp = sqrt(n);
    for(int i = 2;i <= temp;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;

}
int main()
{
 cout<<isPrime(19);
}
