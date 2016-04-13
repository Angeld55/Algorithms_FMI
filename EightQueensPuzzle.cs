using System;
using System.Collections.Generic;
namespace Aglorithms
{
    class EightQueensPuzzle
    {
        private static int[,] chessBoard = new int[8, 8];
        private static int solutionsCount =0;
        private static int[] Queens = new int[8];  //saves the coordinates for the placed queens
      
        static void Main(string[] args)
        {
            PlaceQueen();
            Console.WriteLine(solutionsCount);
           
        }
        static void PlaceQueen(int x=0,int y=0,int numQueen=1)
        {

            if (y == 8)
            {
                if (x == 0)
                {
                    return;
                }
                int prevQueenX = Queens[numQueen - 2] / 10;
                int prevQueenY = Queens[numQueen - 2] % 10;

                MarkBoxesTakenAddRemove(prevQueenX, prevQueenY, numQueen - 1, false);

                PlaceQueen(prevQueenX, prevQueenY + 1, numQueen - 1);
            }
            else
            {


                if (chessBoard[x, y] == 0)
                {
                    if (x == 7)//check if final queen
                    {
                        Queens[numQueen - 1] = (x * 10) + y;
                        solutionsCount++;
                        PrintSolution(); 
                        PlaceQueen(x, y + 1, numQueen);
                    }
                    else
                    {
                        MarkBoxesTakenAddRemove(x, y, numQueen, true);
                        Queens[numQueen-1] = (x * 10) + y;
                        PlaceQueen(x + 1, 0, numQueen + 1);

                    }
                }
                else
                {
                    PlaceQueen(x, y + 1, numQueen);
                }
            }
       

        }
        static void MarkBoxesTakenAddRemove(int x, int y, int numQueen, bool add)
        {
            HashSet<int> boxesToChange = new HashSet<int>();
            ///all boxes attacked by the queen  example :(3,4) ->34 
            for (int i = 0; i < 8; i++)
            {
                boxesToChange.Add(x * 10 + i);
                boxesToChange.Add(i * 10 + y);
            }
            int temp = x;
            for (int i = y; i < 8 && temp < 8; i++)
            {
                boxesToChange.Add(temp * 10 + i);
                temp++;
            }

            temp = x;
            for (int i = y; i >= 0 && temp >= 0; i--)
            {
                boxesToChange.Add(temp * 10 + i);
                temp--;
            }
            temp = x;
            for (int i = y; i < 8 && temp >= 0; i++)
            {
                int proba = temp * 10 + i;
                boxesToChange.Add(i * 10 + temp);
                temp--;
            }
            temp = x;
            for (int i = y; i >= 0 && temp < 8; i--)
            {
                boxesToChange.Add(i * 10 + temp);
                temp++;
            }
            if (add)
            {
                foreach (var box in boxesToChange)
                {
                    chessBoard[box / 10, box % 10] += numQueen;
                }
            }
            else
            {
                foreach (var box in boxesToChange)
                {
                    chessBoard[box / 10, box % 10] -= numQueen;
                }
            }



        }
        static void PrintSolution()
        {
            Console.WriteLine("Solution {0}:",solutionsCount);
            int[,] board = new int[8, 8];
            foreach (var quuenCoordinates in Queens)
            {
                board[quuenCoordinates / 10, quuenCoordinates % 10] = 1;
            }

            for (int i = 0; i < 8; i++)
            {
                for (int j = 0; j < 8; j++)
                {
                    Console.Write(board[i, j]);
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }

    }
}
