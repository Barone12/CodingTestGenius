using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeTest
{
    class Plus
    {
        static int Solution()
        {
            string inputNum = Console.ReadLine();
            string[] splitNum = inputNum.Split(' ');
            int a, b;

            a = int.Parse(splitNum[0]);
            b = int.Parse(splitNum[1]);

            return a + b;
        }
        static void Main(string[] args)
        {
            Console.WriteLine(Solution());


        }
    }
}
