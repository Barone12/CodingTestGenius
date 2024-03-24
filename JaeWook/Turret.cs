using System;


//결국엔 두 원의 교점을 구하는 문제
//두 원의 위치관계를 생각하면 쉬울 듯 하다.

class Program
{
    static void Main(string[] args)
    {

        int count = int.Parse(Console.ReadLine());
        for (int i = 0; i < count; i++)
        {
            Console.Write(TurretRange());
        }

        int TurretRange()
        {
            int x1, y1, r1, x2, y2, r2;
            string[] splitNum = Console.ReadLine().Split(' ');

            x1 = int.Parse(splitNum[0]);
            y1 = int.Parse(splitNum[1]);
            r1 = int.Parse(splitNum[2]);
            x2 = int.Parse(splitNum[3]);
            y2 = int.Parse(splitNum[4]);
            r2 = int.Parse(splitNum[5]);

            int distanceOfCircles = (int)Math.Sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
            int sumOfRadius = r1 + r2;//두 원의 반지름의 합
            int differenceOfRadius = Math.Abs(r1 - r2);//두 원의 반지름 차

            if (distanceOfCircles == 0 && r1 == r2) return -1;//같음
            else if (distanceOfCircles == sumOfRadius) return 1;//외접
            else if (distanceOfCircles == differenceOfRadius) return 1;//내접
            else if (distanceOfCircles < sumOfRadius && distanceOfCircles > differenceOfRadius) return 2;//반지름 차< 두 원사이 거리 < 반지름 합 ==> 교점 2개
            else if (distanceOfCircles < differenceOfRadius) return 0;
            else if (distanceOfCircles > sumOfRadius) return 0;
            return 0;

        }


    }
}



