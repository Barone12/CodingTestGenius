using System;


//결국엔 두 원의 교점을 구하는 문제
//두 원의 위치관계를 생각하면 쉬울 듯 하다.

class Program
{
    static void Main(string[] args)
    {
        string inputCount = Console.ReadLine();
        int count = int.Parse(inputCount);
        for (int i = 0; i < count; i++)
        {
            Console.Write(TurretRange());
            Console.Write("\n");
        }

        int TurretRange()
        {
            int x1, y1, r1, x2, y2, r2;
            string inputNum = Console.ReadLine();
            string[] splitNum = inputNum.Split(' ');

            x1 = int.Parse(splitNum[0]);
            y1 = int.Parse(splitNum[1]);
            r1 = int.Parse(splitNum[2]);
            x2 = int.Parse(splitNum[3]);
            y2 = int.Parse(splitNum[4]);
            r2 = int.Parse(splitNum[5]);

            int distanceOfCircles = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);//거리 제곱
            int sumOfRadius = (int)Math.Pow((double)(r1 + r2),2.0d);//두 원의 반지름의 합
            int differenceOfRadius = (int)Math.Pow((double)Math.Abs(r1 - r2), 2.0d);//두 원의 반지름 차

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



