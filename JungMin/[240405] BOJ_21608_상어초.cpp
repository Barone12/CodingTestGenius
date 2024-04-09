#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int main()
{
	int N;
	cin >> N;

	queue<int> order;
	vector<vector<int>> students(N * N + 1, vector<int>(4, 0));
	vector<vector<int>> seats(N, vector<int>(N, 0));
	int num, prefer;
	const int dx[4] = { 0, 0, -1, 1 };
	const int dy[4] = { -1, 1, 0, 0 };

	// �Է�.
	for (int i = 0; i < N * N; i++)
	{
		cin >> num;
		order.push(num);
		for (int j = 0; j < 4; j++)
		{
			cin >> prefer;
			students[num][j] = prefer;
		}
	}

	// ������� �л� ��ġ.
	while (!order.empty())
	{
		int cur = order.front();
		int satisfaction = -1, blank = -1;
		int proper_x = -1, proper_y = -1;
		order.pop();
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int y = i, x = j;
				if (seats[y][x] != 0)
					continue;

				int temp_satisfaction = 0;
				int temp_blank = 0;

				// �����¿� üũ.
				for (int k = 0; k < 4; k++)
				{
					int ny = y + dy[k];
					int nx = x + dx[k];

					if (ny < 0 || ny >= N || nx < 0 || nx >= N)
						continue;

					if (seats[ny][nx] == 0)
						temp_blank++;
					else
					{
						for (int m = 0; m < 4; m++)
						{
							if (seats[ny][nx] == students[cur][m])
							{
								temp_satisfaction++;
								break;
							}
						}
					}
				}

				// ���� ��ǥ ��ó�� ���� ĭ, �� ĭ ���� ����.
				if (temp_satisfaction > satisfaction)
				{
					satisfaction = temp_satisfaction;
					blank = temp_blank;
					proper_x = x;
					proper_y = y;
				}
				else if (temp_satisfaction == satisfaction)
				{
					if (temp_blank > blank)
					{
						blank = temp_blank;
						proper_x = x;
						proper_y = y;
					}
				}
			}
		}
		// ���� �¼� ��ġ.
		seats[proper_y][proper_x] = cur;
	}

	// ��ġ ���� �� ������ ����.
	int answer = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int y = i, x = j;
			int cur = seats[y][x];
			int satisfaction = 0;
			for (int k = 0; k < 4; k++)
			{
				int ny = y + dy[k];
				int nx = x + dx[k];

				if (ny < 0 || ny >= N || nx < 0 || nx >= N)
					continue;

				for (int m = 0; m < 4; m++)
				{
					if (seats[ny][nx] == students[cur][m])
					{
						satisfaction++;
						break;
					}
				}
			}
			answer += satisfaction == 0 ? 0 : pow(10, satisfaction - 1);
		}
	}
	cout << answer << "\n";
}