import java.util.Arrays;

public class Combinatorics
{
 
    public static void CombinationsNoRep(int[] arr,int[] free,int k, int index,int start)
    {
        if(index>=k)
            System.out.println(Arrays.toString(free));
        else    
        {
            for (int i = start; i < arr.length ; i++) {
                free[index]=arr[i];
                CombinationsNoRep(arr,free,k,index+1,i+1);
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

