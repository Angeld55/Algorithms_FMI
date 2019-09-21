package com.company;


import java.util.Scanner;

public class Main
{

    public static void main(String[] args)
    {
       int[]arr = {3,-9,1,6,4,-5,9};
        System.out.println(Kadane(arr));
    }
    public static int Kadane(int[] arr)
    {
        int maxSubArraySumEndsOnIthIndex = 0;
        int maxSubArraySum = 0;
        for (int i = 0; i < arr.length; i++)
        {
            maxSubArraySumEndsOnIthIndex+=arr[i];
            if(maxSubArraySumEndsOnIthIndex<0)
                maxSubArraySumEndsOnIthIndex=0;
            if(maxSubArraySumEndsOnIthIndex>maxSubArraySum)
                maxSubArraySum=maxSubArraySumEndsOnIthIndex;

        }
        return maxSubArraySum;
    }

}
