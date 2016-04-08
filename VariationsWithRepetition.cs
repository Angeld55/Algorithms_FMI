using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VariationsWithRepetition
{
    class VariationsWithRepetition
    {
        /// find all variations with repetiotions with recursion
      
        
        private static int n = 5;
        private static int k = 2;
        private static int[] array = new int[k];

        static void Main(string[] args)
        {
            GenerateVariations(0);
        }

        static void GenerateVariations(int index)
        {
            if (index == k)
            {
                Print(array);
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    array[index] = i;
                    GenerateVariations(index + 1);
                }
            }
        }
        static void Print(int[] arr)
        {
            Console.WriteLine("({0})", string.Join(", ", array));
        }
    }
}
