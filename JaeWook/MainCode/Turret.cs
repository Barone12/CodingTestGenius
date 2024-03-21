using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeTest
{
    //결국엔 두 원의 교점을 구하는 문제
    //두 원의 교점을 구하는 방정식을 세우면 될 듯 하다.
    //원 방정식 (x-a)^2+(y-b)^2=r^2
    // 제곱은 Math.Pow(int a, int b) a^b
    //제곱근은 Math.Sqrt(a);
    //절대값은 Math.Abs(a);
    // 제한)  -10,000<=x1,y1,x2,y2<=10,000
    //          1<=r1,r2<=10,000
    class Turret
    {
        static int TurretRange() {
            int x1, y1, r1, x2,y2, r2;
            string inputNum = Console.ReadLine();
            string[] splitNum = inputNum.Split(' ');
            x1 = int.Parse(splitNum[0]);
            y1 = int.Parse(splitNum[1]);
            r1 = int.Parse(splitNum[2]);
            x2 = int.Parse(splitNum[3]);
            y2 = int.Parse(splitNum[4]);
            r2 = int.Parse(splitNum[5]);

            if (x1 == x2 && y1 == y2) { //두 원이 동일한 경우 교점은 무한대
                return -1;
            }

            double a=0, b=0;//임의의 교점
            double c = Math.Pow(a - x1,2);

        }
        static void HelloMain(string[] args)
        {

            TurretRange();

        }
    }
}
