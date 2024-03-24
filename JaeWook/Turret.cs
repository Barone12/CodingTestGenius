using System;


//결국엔 두 원의 교점을 구하는 문제
//두 원의 위치관계를 생각하면 쉬울 듯 하다.

class Turret
{

    static int TurretRange()
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

        if (x1 == x2 && y1 == y2)
        { //두 원 위치가 같을 때
            if (r1 == r2) return -1; // 반지름도 같을 때
            if (r1 != r2) return 0; //반지름 다를 때
        }


        int distanceOfCircles = (int)Math.Sqrt((int)(Math.Pow((int)x2 - (int)x1, (int)2.0d) + Math.Pow((int)y2 - (int)y1, (int)2.0d))); ;// 두 원사이의 거리 
        int sumOfRadius = r1 + r2;//두 원의 반지름의 합
        int differenceOfRadius = Math.Abs(r1 - r2);

        if (distanceOfCircles == sumOfRadius) return 1;//외접
        if (distanceOfCircles == differenceOfRadius) return 1;//내접
        if (distanceOfCircles < sumOfRadius && distanceOfCircles > differenceOfRadius) return 2;//반지름 차< 두 원사이 거리 < 반지름 합 ==> 교점 2개

        return 0;

    }

    static void Main(string[] args)
    {
        int count = int.Parse(Console.ReadLine());
        for (int i = 0; i < count; i++)
        {
            Console.Write(TurretRange());
        }


    }
}



