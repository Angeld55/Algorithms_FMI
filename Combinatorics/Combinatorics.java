package com.company;

import java.util.Arrays;

public class Combinatorics
{
    public static void main(String[] args)
    {
        int[] arr = {0,1,2,3,4};
        VariationsWithRep(arr,new int[4],4,0);

    }
    public static void Permutations(int[] arr,int index)
    {
        if(index>=arr.length)
            System.out.println(Arrays.toString(arr));
        else
        {
            Permutations(arr,index+1);
            for (int i = index+1; i < arr.length; i++) {
                swap(arr,index,i);
                Permutations(arr,index+1);
                swap(arr,index,i);
            }
        }

    }
    public static void VariationsNoRep(int[] arr,int[] free, int k ,int index)
    {
        if(index>=k)
            System.out.println(Arrays.toString(free));
        else
        {
            for (int i = index; i < arr.length; i++) {
                free[index]=arr[i];
                swap(arr,i,index);
                VariationsNoRep(arr,free,k,index+1);
                swap(arr,i,index);
            }
        }
    }
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
