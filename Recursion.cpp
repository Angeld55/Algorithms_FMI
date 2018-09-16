#include <iostream>
unsigned int FibbIterative(unsigned int n);
unsigned int FibbRecursive(unsigned int n);

unsigned int FactIterative(unsigned int n);
unsigned int FactRecursive(unsigned int n);

unsigned int SumElementsOfArrayRecursive(int* arr,int len);

bool SearchRecursive(int* arr,int len,int num);

int BinarySearch(int* arr,int start,int end,int el);

int EvenCountRecursive(int* arr, int len);

int Max(int a,int b);
int MaxOfArrayRecursive(int* arr,int len);

int main()
{   
    int len = 10;
    int* arr = new int[len];
    for(int i = 0;i<len;i++)
        arr[i]=i;
        
   
    std::cout<BinarySearch(arr,0,len-1);
   
}
int BinarySearch(int* arr,int start,int end,int el)
{
    int mid=(start+end)/2;
    if(start>end)
        return -1;
    if(arr[mid]==el)
        return mid;
    if(arr[mid]>el)
        return BinarySearch(arr,start,mid-1,el);
    else
        return BinarySearch(arr,mid+1,end,el);
}
unsigned int SumElementsOfArrayRecursive(int* arr,int len)
{
    if(len==0)
        return 0;
 return SumElementsOfArrayRecursive(arr,len-1)+arr[len-1];   
}
bool SearchRecursive(int* arr,int len,int num)
{
    if(len==0)
        return false;
    if(arr[len-1]==num)
        return true;
 
    return SearchRecursive(arr,len-1,num);
}
unsigned int FactRecursive(unsigned int n)
{
 if(n==0)
    return 1;
 return FactRecursive(n-1)*n;   
}
unsigned int FactIterative(int n)
{
    int result =1;
    for(int i =2;i<=n;i++)
        result*=i;
    return result;
}
unsigned int FibbRecursive(unsigned int n)
{
 if(n==1||n==2)
    return 1;
 return FibbRecursive(n-1)+FibbRecursive(n-2);   
}
unsigned int FibbIterative(unsigned int n)
{
    int a=1;
    int b =1;
    if(n==1||n==2)
        return 1;
    for(int i = 0;i<n-2;i++)
    {
     int c = a+b;
     a=b;
     b=c;
    }
    return b;
}
int EvenCountRecursive(int* arr, int len)
{
 if(len==0)
    return 0;
 if(arr[len-1]%2==0)
    return EvenCount(arr,len-1)+1;
else
    return EvenCount(arr,len-1);
}
int Max(int a,int b)
{
 if(a>b)
    return a;
 else
    return b;
}
int MaxOfArrayRecursive(int* arr,int len)
{
    if(len==1)
        return arr[0];
    return Max(arr[len-1],MaxOfArray(arr,len-1));
}