#include <iostream>
using namespace std;

const int dy[4] = { 1, -1, 0, 0 };
const int dx[4] = { 0, 0, 1, -1 };

int N;
int order[400];
int like[401][4];
int grid[20][20] = { 0, };

bool InRange(int y, int x)
{
    return 0 <= y && y < N && 0 <= x && x < N;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N;
    for (int i = 0; i < N * N; ++i)
    {
        cin >> order[i];
        cin >> like[order[i]][0] >> like[order[i]][1] >> like[order[i]][2] >> like[order[i]][3];
    }
    for (int k = 0; k < N * N; ++k)
    {
        int maxLikeCount = -1;
        int maxBlankCount = -1;
        int index[2] = { -1, -1 };
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (grid[i][j] != 0)
                {
                    continue;
                }
                int likes = 0;
                int blank = 0;
                for (int u = 0; u < 4; ++u)
                {
                    int nextY = i + dy[u];
                    int nextX = j + dx[u];
                    if (InRange(nextY, nextX))
                    {
                        if (grid[nextY][nextX] == 0)
                        {
                            blank++;
                        }
                        else if (grid[nextY][nextX] == like[order[k]][0] ||
                            grid[nextY][nextX] == like[order[k]][1] ||
                            grid[nextY][nextX] == like[order[k]][2] ||
                            grid[nextY][nextX] == like[order[k]][3])
                        {
                            likes++;
                        }
                    }
                }
                if (maxLikeCount < likes)
                {
                    maxLikeCount = likes;
                    maxBlankCount = blank;
                    index[0] = i;
                    index[1] = j;
                }
                else if (maxLikeCount == likes && maxBlankCount < blank)
                {
                    maxBlankCount = blank;
                    index[0] = i;
                    index[1] = j;
                }
            }
        }
        grid[index[0]][index[1]] = order[k];
    }
    int result = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int likes = 0;
            for (int u = 0; u < 4; ++u)
            {
                int nextY = i + dy[u];
                int nextX = j + dx[u];
                if (InRange(nextY, nextX))
                {
                    if (grid[nextY][nextX] == like[grid[i][j]][0] ||
                        grid[nextY][nextX] == like[grid[i][j]][1] ||
                        grid[nextY][nextX] == like[grid[i][j]][2] ||
                        grid[nextY][nextX] == like[grid[i][j]][3])
                    {
                        likes++;
                    }
                }
            }
            switch (likes)
            {
            case 1:
                result += 1;
                break;
            case 2:
                result += 10;
                break;
            case 3:
                result += 100;
                break;
            case 4:
                result += 1000;
                break;
            default:
                break;
            }
        }
    }
    cout << result;
    return 0;
}

/*
* 브루트포스 구현 문제. 20^3이므로 계산 횟수가 1억을 넘지 않는다.
*/