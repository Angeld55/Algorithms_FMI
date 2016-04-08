using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace exercise
{
    class KnightsTour
    
 {
        
        static void Main(string[] args)
        {
            int x =7;
            bool[,] visited = new bool[x, x];

            int necesseryMoves = (x * x) - 1;
            Console.WriteLine(Move(0, 0, 0, necesseryMoves, visited));

        }
        static bool Move(int x, int y, int moves, int necesseryMoves, bool[,] visited)
        {

            
            if ((x < 0) || (x >= visited.GetLength(0) || (y < 0) || (y >= visited.GetLength(1))))
            {
                return false;
            }
            
            if (visited[x, y] == true)
            {
                return false;
            }

            if (moves == necesseryMoves)
            {
                visited[x,y] = true;
                return true;
            }
            else
            {
                visited[x, y] = true;
                bool res = false;
                res = (res || (Move(x + 1, y + 2, moves + 1, necesseryMoves, visited)));
                res = (res || (Move(x + 2, y - 1, moves + 1, necesseryMoves, visited)));
                res = (res || (Move(x + 2, y + 1, moves + 1, necesseryMoves,visited)));
                res = (res || (Move(x + 2, y - 1, moves + 1, necesseryMoves, visited)));
                res = (res || (Move(x - 2, y + 1,  moves + 1, necesseryMoves, visited)));
                res = (res || (Move(x - 2, y - 1,  moves + 1, necesseryMoves, visited)));
                res = (res || (Move(x + 1, y - 2,  moves + 1, necesseryMoves, visited)));
                res = (res || (Move(x - 1, y + 2,  moves + 1, necesseryMoves, visited)));
                res = (res || (Move(x - 1, y - 2,  moves + 1, necesseryMoves, visited)));
                if (res == true)
                {
                    Console.WriteLine("x --> " + x);
                    Console.WriteLine("y --> " + y);
                    Console.WriteLine();
                    
                    return true;
                   
                }
                else
                {
                    visited[x,y] = false;
                    return false;
                }
            }
        }



    }
}
