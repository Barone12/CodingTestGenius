#include <iostream>
#include <vector>
using namespace std;

int desks[100000][2];
int main()
{
	int N;
	cin >> N;
		
	int len = 0, grade = 0;
	int arr[5] = { 0,0,0,0,0 };
	int a, b;
	for (int i = 0; i < N; i++)
	{
		cin >> desks[i][0] >> desks[i][1];
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			if (desks[i][0] == j || desks[i][1] == j)
				continue;
			arr[j - 1] = 0;
		}

		if (desks[i][0] == desks[i][1])
			arr[desks[i][0] - 1]++;
		else
		{
			arr[desks[i][0] - 1]++;
			arr[desks[i][1] - 1]++;
		}

		for (int j = 0; j < 2; j++)
		{
			if (len < arr[desks[i][j] - 1])
			{
				len = arr[desks[i][j] - 1];
				grade = desks[i][j];
			}
			else if (len == arr[desks[i][j] - 1])
			{
				if (grade > desks[i][j])
					grade = desks[i][j];
			}
		}
	}
	cout << len << " " << grade << "\n";
}
