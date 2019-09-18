package com.company;

import java.util.Arrays;

public class Combinatorics
{

    public static void VariationsWithRep(int[] arr,int[] free,int k,int index)
    {
        if(index>=k)
            System.out.println(Arrays.toString(free));
        else
        {
            for (int i = 0; i < arr.length; i++) {
                free[index]=arr[i];
                VariationsWithRep(arr,free,k,index+1);
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
