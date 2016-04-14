namespace Longest_Increasing_Subsequence
{
    using System;

    public class LongestIncreasingSubsequence
    {
        public static void Main()
        {
            var sequence = new[] { 3, 14, 5, 12, 15, 7, 8, 9, 11, 10,
            1, 12, 13, 14, 20, 15, 30, 16, 17, 40, 18, 19, 20 };
            var longestSeq = FindLongestIncreasingSubsequence(sequence);
            Console.WriteLine("Longest increasing subsequence (LIS)");
            Console.WriteLine("  Length: {0}", longestSeq.Length);
            Console.WriteLine("  Sequence: [{0}]", string.Join(", ", longestSeq));
        }

        public static int[] FindLongestIncreasingSubsequence(int[] sequence)
        {
            int[] longestSequence = new int[sequence.Length];
            int[] prevElement = new int[sequence.Length];
            int biggestSeqence = 0;
            int indexLastLongesSequence = -1;
            for (int i = 0; i < sequence.Length; i++)
            {
                longestSequence[i] = 0;
                prevElement[i] = 0;
                for (int j = i-1; j >= 0; j--)
                {
                    if (sequence[j] < sequence[i])
                    {
                        if (longestSequence[j] >= longestSequence[i])
                        {
                            longestSequence[i] = longestSequence[j];
                            prevElement[i] = j;
                        }
                    }
                }
                longestSequence[i]++;
                if (longestSequence[i]>biggestSeqence)
                {
                    indexLastLongesSequence = i;
                    biggestSeqence = longestSequence[i];
                }
            }
            int[] LongestIncreasingSubsequence = new int[biggestSeqence];
            for (int i = LongestIncreasingSubsequence.Length - 1; i >= 0; i--)
            {
                LongestIncreasingSubsequence[i] = sequence[indexLastLongesSequence];
                indexLastLongesSequence = prevElement[indexLastLongesSequence];  
            }
            return LongestIncreasingSubsequence;


        }
    }
}
