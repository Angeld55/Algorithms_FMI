#include <iostream>
using namespace std;

template <typename T>
void swap(T* arr, int i, int j)
{
	T temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

template <typename T>
void Heapyfy(T* arr, int el, int count) //Not the best implementation (good for education purposes)
{
	int elIndex = el;
	while (true)
	{
		int leftChIndex = elIndex*2 + 1;
		int rightChIndex = elIndex*2 + 2;

		bool isSmallerThanLeft = leftChIndex<count && arr[elIndex]<arr[leftChIndex];
		bool isSmallerThanRight = rightChIndex<count && arr[elIndex]<arr[rightChIndex];

		if (isSmallerThanLeft&&!isSmallerThanRight)
		{
			swap(arr,elIndex, leftChIndex);
			elIndex = leftChIndex;
		}
		else if (!isSmallerThanLeft&&isSmallerThanRight)
		{
			swap(arr,elIndex, rightChIndex);
			elIndex = rightChIndex;
		}
		else if (isSmallerThanLeft&&isSmallerThanRight)
		{
			if (arr[leftChIndex]>arr[rightChIndex])
			{
				swap(arr,elIndex, leftChIndex);
				elIndex = leftChIndex;
			}
			else
			{
				swap(arr,elIndex,rightChIndex);
				elIndex = rightChIndex;
			}
		}
		else
			break;

	}
}
template <typename T>
void HeapSort(T* arr,int len)
{
   for (int i = len / 2; i >= 0; i--)
		Heapyfy<T>(arr, i, len); //Build Heap.
	
	 
		
	for(int i = 0;i<len-1;i++)	
	{
        swap<T>(arr,0,len-1-i);//the biggest element(the root of the heap) goes to the end of the array.(Or we can use minheap without swaping)
        Heapyfy<T>(arr,0,len-1-i);
	}
}

int main()
{
   int arr[] = {9,8,7,6,1,2,3,4,5};
   HeapSort<int>(arr,9);
   for (int i = 0; i < 9; i++) 
       cout<<arr[i]<<" ";
      
    return 0;
}
