using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodingTest
{
    class Calculate
    {

        static void Main(string[] args)
        {
            string inputNum;
            string[] splitNum;
            int sum;
            inputNum = Console.ReadLine();
            splitNum = inputNum.Split();
            Console.WriteLine(int.Parse(splitNum[0]) + int.Parse(splitNum[1]));
        }
    }
}
