#include <iostream>

template <class T>
void swap(T* arr,int i ,int j)
{
 T temp = arr[i];
 arr[i]=arr[j];
 arr[j]=temp;
}
template <class T>
void CocktailShakerSort(T* arr,int len) 
{
    bool swapped;
    int iterCount = 0;
    do
    {
        swapped = false;
        for(int i = iterCount; i < len-1-iterCount;i++)
        {
            if(arr[i]>arr[i+1])
            {
                swap(arr,i,i+1);
                swapped = true;
            }
        }
        if(!swapped)
            return;
        for(int i = len-2-iterCount; i>=iterCount; i--)
        {
            if(arr[i]<arr[i-1])
            {
                swap(arr,i,i-1);
                swapped = true;
            }
        }
        iterCount++;
        
    }while(swapped);
}
int main()
{
  int arr[] = {6,5,4,3,2,1};
  CocktailShakerSort<int>(arr,6);
  for(int i = 0 ; i < 6; i++)
    std::cout<<arr[i]<<" ";
}
