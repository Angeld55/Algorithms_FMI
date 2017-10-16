import java.util.Arrays;
import java.util.Scanner;


public class SelectionSort
{

    public static void main(String[] args) 
    {
     int[] arr = { 4,3,5,6,7,2,1,14,3,55,3,12,6,4,2,66};   
     
     QuickSort(arr,0,arr.length-1);
        System.out.println( Arrays.toString(arr));
    }
    public static void BubbleSort(int[] arr)
    {
        int lastSwap = arr.length-1;
        for (int j = 0; j < arr.length; j++) {
          boolean isSwapped = false;
          int lastSwapTemp=lastSwap;
        for (int i = 0; i < lastSwap; i++) {
        if(arr[i]>arr[i+1]) 
        {
           swap(arr,i,i+1);
           lastSwap=i+1;
           isSwapped=true;
        }  
          }
        if(!isSwapped)
            return;
       
    }
        
    }
    
    public static void SelectionSort(int[] arr)
    {
        for (int i = 0; i < arr.length; i++) {
           
            int min=Integer.MAX_VALUE;
            int index = -1;
            for (int j = i; j < arr.length; j++) {
                
              if(arr[j]<min)
              {
                  min=arr[j];
                   index=j;
              }
            }
            if(index!=-1)
                swap(arr,i,index);
        }
    }
    public static void InsertionSort(int[] arr)
    {
        
        for (int i = 0; i < arr.length-1; i++) {
           
             if(arr[i+1]<arr[i])
             {
                 for (int j = i+1; j > 0; j--) {
                     if(arr[j]<arr[j-1])
                    {  
                     swap(arr,j,j-1);
                    }
                     else
                     {
                         break;
                     }
                     
                 }
             }
           } 
    }
     public static void QuickSort(int[] arr,int startIndex,int endIndex)
     {
         int pivot = arr[startIndex+(endIndex-startIndex)/2];
         int i = startIndex;
         int j = endIndex;
         
         while(i<=j)
         {
             while(arr[i]<pivot)
                 i++;
             while(arr[j]>pivot)
                 j--;
             if(i<=j)
             {
                 swap(arr,i,j);
                 i++;
                 j--;  
             }
         }
         if(startIndex<j)
             QuickSort(arr,startIndex,j);
         if(endIndex>i)
             QuickSort(arr,i,endIndex);
         
         
     }
             
    public static void swap(int[] arr,int ind1,int ind2)
    {
     int temp= arr[ind1];
    arr[ind1]=arr[ind2];
    arr[ind2]=temp;
    
    }
}
