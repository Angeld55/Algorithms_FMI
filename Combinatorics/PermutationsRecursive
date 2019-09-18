public class Combinatorics
{
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

    public static void swap(int[] arr, int index1,int index2)
    {
        int temp = arr[index1];
        arr[index1]= arr[index2];
        arr[index2]=temp;
    }

}
