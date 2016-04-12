using System;

namespace CombinatoricalAglorithms
{
    class Permutaions
    {
        private static int permutationsCount = 0;
        static void Main(string[] args)
        {
            int n = Convert.ToInt32(Console.ReadLine());
            int[] numbers = new int[n];

            for (int i = 0; i < n; i++)
            {
                numbers[i] = i;
            }
            Permute(numbers);
            Console.WriteLine("Permutations: {0}",permutationsCount);
        }
       static void Permute(int[] numbers,int index=0)
        {
            if (index>=numbers.Length-1)
            {
                permutationsCount++;
                PrintNumbers(numbers);
            }
            else
            {
                for (int i = index; i < numbers.Length; i++)
                {
                    swap(numbers,index, i);
                    Permute(numbers, index + 1);
                    swap(numbers, index, i);
                }
               
            }

        }
      static void PrintNumbers(int[] numbers)
        {
            foreach (var number in numbers)
            {
                Console.Write(number+" ");
            }
            Console.WriteLine();
        }
     static void swap(int[] numbers,int indexOne,int indexTwo)
        {
            int temp = numbers[indexOne];
            numbers[indexOne] = numbers[indexTwo];
            numbers[indexTwo] = temp;
        }
    }
}
