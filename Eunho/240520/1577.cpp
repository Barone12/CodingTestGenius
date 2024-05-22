#include <iostream>
using namespace std;

int N, M, K;
bool road[101][101][2];
long long cache[2][101];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N >> M >> K;
    for (int i = 0; i < K; ++i)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a != c)
        {
            if (a < c)
            {
                road[a][b][0] = true;
            }
            else
            {
                road[c][d][0] = true;
            }
        }
        else
        {
            if (b < d)
            {
                road[a][b][1] = true;
            }
            else
            {
                road[c][d][1] = true;
            }
        }
    }
    cache[0][0] = 1;
    for (int i = 0; i <= N; ++i)
    {
        for (int j = 0; j <= M; ++j)
        {
            if (i == 0 && j == 0) continue;
            long long down = ((i - 1 >= 0) ? (road[i - 1][j][0] ? 0 : cache[(i - 1) % 2][j]) : 0);
            long long left = ((j - 1 >= 0) ? (road[i][j - 1][1] ? 0 : cache[i % 2][j - 1]) : 0);
            cache[i % 2][j] = down + left;
        }
    }
    cout << cache[N % 2][M];
    return 0;
}

/*
* 최단거리로 이동하므로 오른쪽 혹은 위쪽길만 사용한다.
* 메모리 관리가 중요하다. 최단거리 규칙을 통해 시작 좌표와 2개 방향으로만 데이터를 저장한다.
* 또한 반복적 DP를 진행할 때 바로 아래 좌표에 대한 값만 기억하면 되므로 
* 슬라이딩 윈도 기법을 사용해 배열의 크기를 2 * M으로 줄일 수 있다.
*/