template <class T>
void swap(T* arr,T i ,T j)
{
 T temp = arr[i];
 arr[i]=arr[j];
 arr[j]=temp;
}
