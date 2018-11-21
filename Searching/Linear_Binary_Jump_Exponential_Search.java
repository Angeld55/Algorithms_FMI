
public class Search
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        int[] arr = {1,2,3,4,5,6,11};
        System.out.println(ExponentialSearch(arr,4));
    }
            
    public static int LinearSearch(int[] arr,int x)
    {
        for (int i = 0; i < arr.length; i++) {
            if(arr[i]==x)
                return i;
        }
        return -1;
        
    }
    public static int BinarySearch(int[] arr,int start,int end,int x)
    {
        int mid = (start+end)/2;
        
        if(start<=end)
        {
        if(arr[mid]==x)
            return mid;
        
        if(arr[mid]>x)
           return  BinarySearch(arr,start,mid-1,x);
        if(arr[mid]<x)
           return  BinarySearch(arr,mid+1,end,x);
        }
        return -1;
    }
    public static int JumpSearch(int[] arr,int x)
    {
        int step =(int)Math.floor(Math.sqrt(arr.length));
        int curStep=0;
        int prev=0;
        while(arr[Math.min(curStep, arr.length-1)]<x)
        {
            prev=curStep;
            curStep+=step;
            if(prev>=arr.length)
                return -1;
        }
       return BinarySearch(arr,prev,curStep,x);
        
    }
    public static int ExponentialSearch(int[] arr,int x)
    {
        if(arr[0]==x)
            return 0;
        int i=1;
        while(i<arr.length&&arr[i]<=x)
            i*=2;
        return BinarySearch(arr,i/2,Math.min(i,arr.length-1),x);
    }       
}
