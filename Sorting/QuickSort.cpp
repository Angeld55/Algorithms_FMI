#include <iostream>

template <class T>
void swap(T* arr,int i ,int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j]=temp;
}

template <class T>
int Partition (T* arr, int start, int end)  
{  
    T pivot = arr[end]; 
    int i = start - 1; 
  
    for (int j = start; j <= end - 1; j++)  
    { 
        if (arr[j] < pivot)  
            swap(arr,++i,j); 
    }  
    swap(arr,i+1,end);  
    return (i + 1);  
}  
template <class T>
 void QuickSortHelp(T* arr,int start,int end)
{
	if(end-start<1)
		return;
	int indPivot = Partition(arr,start,end);
	QuickSortHelp<T>(arr,start,indPivot-1);
	QuickSortHelp<T>(arr,indPivot+1,end);
}
template <class T>
void QuickSort(T* arr,int len)
{
	QuickSortHelp<T>(arr,0,len-1);
}

int main()
{
	int arr[] = {5,4,3,2,1};
	QuickSort<int>(arr,5);
	for(int i =0;i<5;i++)
		std::cout<<arr[i]<<" "; 
    
}
