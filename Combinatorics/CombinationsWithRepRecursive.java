

import java.util.Arrays;

public class Combinatorics
{
 
    public static void CombinationsWithRep(int[] arr,int[] free,int k, int index,int start)
    {
        if(index>=k)
            System.out.println(Arrays.toString(free));
        else
        {
            for (int i = start; i < arr.length ; i++) {
                free[index]=arr[i];
                CombinationsWithRep(arr,free,k,index+1,i);
            }
        }
    }



    public static void swap(int[] arr, int index1,int index2)
    {
        int temp = arr[index1];
        arr[index1]= arr[index2];
        arr[index2]=temp;
    }

}
