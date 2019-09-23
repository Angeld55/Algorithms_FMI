
#include <iostream>

bool isPrime(int n)
{
  if(n <= 3)
    return n>1;
  else if(n%2==0 || n%3==0)
    return false;
  for(int i = 5; (i*i) < n; i+=6)
  {
     if(n%i==0 || n%(i+2)==0)
        return false;
  }
  return true;
}
int main()
{
 std::cout<<isPrime(41);
}
