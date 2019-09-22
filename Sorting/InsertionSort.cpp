void swap(int* arr,int i ,int j)
{
 int temp = arr[i];
 arr[i]=arr[j];
 arr[j]=temp;
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
