using System;
using System.ComponentModel.Design;

//백준 1004 어린왕자 문제

namespace _20240130
{
    internal class LittlePrince
    {
        static void Main(string[] args)
        {
            int count = 0;
            count = int.Parse(Console.ReadLine());

            for (int x = 0; x < count; x++)
            {
                int result = 0; //결과값
                string input = Console.ReadLine();//출발점, 도착점 입력

                string[] inputStrings;


                inputStrings = input.Split(" ");
                int[] startPoint = new int[2];
                int[] endPoint = new int[2];

                int[] startAndEndPoint = new int[4];

                for (int i = 0; i < inputStrings.Length; i++)
                {
                    startAndEndPoint[i] = int.Parse(inputStrings[i]); //출발 and 도착 좌표 파싱
                }
                startPoint[0] = startAndEndPoint[0];
                startPoint[1] = startAndEndPoint[1];
                endPoint[0] = startAndEndPoint[2];
                endPoint[1] = startAndEndPoint[3];

                int planetInputCount = int.Parse(Console.ReadLine());
                for (int i = 0; i < planetInputCount; i++)
                {
                    int[] planetPoint = new int[3];
                    input = Console.ReadLine();//행성계 좌표및 반지름 입력
                    inputStrings = input.Split(" ");
                    planetPoint[0] = int.Parse(inputStrings[0]);
                    planetPoint[1] = int.Parse(inputStrings[1]);
                    planetPoint[2] = int.Parse(inputStrings[2]);
                    CheckPath(startPoint, endPoint, planetPoint);
                }
                Console.WriteLine(result);


                void CheckPath(int[] start, int[] end, int[] planet)
                {


                    if (CheckPlanetSystem(start, planet) && CheckPlanetSystem(end, planet)) { return; }
                    else if (CheckPlanetSystem(start, planet) || CheckPlanetSystem(end, planet)) { result++; } //exclusive OR




                }

            }
            
            bool CheckPlanetSystem(int[] point, int[] planet) //어느 한 점이 행성계 내에 속하는지 반환하는 함수
            {
                if ((Math.Pow((point[0] - planet[0]), 2) + Math.Pow((point[1] - planet[1]), 2)) < Math.Pow((planet[2]), 2))
                {
                    return true;
                }
                else return false;



            }
        }
    }
}
