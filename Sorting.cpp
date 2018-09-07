// Example program
#include <iostream>
#include <string>
void BubbleSort(int* arr,int len);
void SelectionSort(int* arr,int size);
void InsertionSort(int* arr,int len);
int main()
{
 int arr[] = {3,2,1,4,10,2,12,15,3};
 InsertionSort(arr,9);
 for(int i = 0;i<9;i++)
    std::cout<<arr[i]<<" " ;
    
}
void swap(int* arr,int i ,int j)
{
 int temp = arr[i];
 arr[i]=arr[j];
 arr[j]=temp;
}
void BubbleSort(int* arr,int len)
{
    for(int j = 0;j<len;j++)
    {
        bool isSwapped= false;
        for(int i = 0;i<len-1-j;i++)
        {
            if(arr[i]>arr[i+1])
            {
             swap(arr,i,i+1);
             isSwapped=true;
            }
        }
        if(!isSwapped)//sortiran l ie masiwa?
            return;
     }
}
void NaiveInsertionSort(int* arr,int len)
{
    for(int i = 1;i<len;i++)
    {
        int elIndex = i;
        while(elIndex>0&&arr[elIndex]<arr[elIndex-1])
        {
         swap(arr,elIndex,elIndex-1);
         elIndex--;
        }
         
    }
}
void InsertionSort(int* arr,int len)
{
    for(int i =1;i<len;i++)
    {
        int element = arr[i];
        int index = i-1;
        while(index>=0&&arr[index]>element)
        {
            arr[index+1]=arr[index];
            index--;
        }
        arr[index+1]=element;
    }
}
void SelectionSort(int* arr,int size)
{
    for(int i = 0;i<size-1;i++)
    {
        int minIndex=i;
        for(int j=i+1; j<size;j++)
        {
            if(arr[j]<arr[minIndex])
                minIndex=j;
        }
        swap(arr,i,minIndex);
    }
}
