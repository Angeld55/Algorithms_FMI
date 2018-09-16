#include <iostream>

void BubbleSort(int* arr,int len);

void SelectionSort(int* arr,int size);

void InsertionSort(int* arr,int len);

void QuickSort(int*arr,int l,int r);
int Partition(int* arr,int l,int r);

void MergeSort(int* arr, int len);
void Merge(int* arr1,int len1,int* arr2,int len2,int* result);

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

void QuickSort(int*arr,int l,int r)
{
    if(l<r)
    {
        int pivot= Partition(arr,l,r);
        QuickSort(arr,l,pivot-1);
        QuickSort(arr,pivot+1,r);
    }
}
int Partition(int* arr,int l,int r)
{
    int pivot = arr[l];
    int i =l;
    int j = r;

    while(true)
    {
    while(arr[i]<pivot)
        i++;
    while(arr[j]>pivot)
        j--;
    if(i<j)
      { 
        swap(arr,i,j);
        i++;
        j--;
      }
    else
        break;
    }
    return j;
}
void MergeSort(int* arr, int len) //Not the best implementation.
{
    if(len==1)
        return;
    int mid = len/2;
    int* firstHalf = new int[mid];
    for(int i =0;i<mid;i++)
        firstHalf[i] = arr[i];
    int* secondHalf = new int[len-mid];
    for(int i = mid,j=0;i<len;i++,j++)
        secondHalf[j]=arr[i];
    MergeSort(firstHalf,mid);    
    MergeSort(secondHalf,len-mid);
    Merge(firstHalf,mid,secondHalf,len-mid,arr);
    delete[] firstHalf,secondHalf;
    
}
void Merge(int* arr1,int len1,int* arr2,int len2,int* result)
{
    int cursor1=0;
    int cursor2=0;
    int resultCursor=0;
    while(cursor1<len1&&cursor2<len2)
    {
        if(arr1[cursor1]<arr2[cursor2])
        {
            result[resultCursor]=arr1[cursor1];
            cursor1++;
        }
        else
        {   
            result[resultCursor]=arr2[cursor2];
            cursor2++;
        }
        resultCursor++;
    }
    while(cursor1<len1)
    {
        result[resultCursor]=arr1[cursor1];
        cursor1++;
        resultCursor++;
    }
    while(cursor2<len2)
    {
          result[resultCursor]=arr2[cursor2];
        cursor2++;
         resultCursor++;
    }
    
}
int LinearSearch(const int* arr,int size,int el)
{
    for(int i =0;i<size;i++)
    {
     if(arr[i]==el)
        return i;
    }
    return -1;
}
