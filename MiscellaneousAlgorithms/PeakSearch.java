package com.company;


import java.util.Scanner;

public class Main
{

    public static void main(String[] args)
    {
       int[]arr = {3,-9,1,6,9,-5,9};
        System.out.println( Peak(arr,0,arr.length));

    }
    public static boolean isPeak(int arr[],int ind)
    {
        int left = ind-1;
        int right = ind+1;
        return (left<0 || arr[ind]>=arr[left]) && (right>=arr.length || arr[ind]>=arr[right]);
    }

    public static int Peak(int[] arr,int start,int end)
    {
        int mid = (start+end)/2;
        if(isPeak(arr,mid))
            return mid;

        if(mid-1>=0 && arr[mid] < arr[mid-1])
            return Peak(arr,start,mid-1);
        else
            return Peak(arr,mid+1,end);
    }

}
