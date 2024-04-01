#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int m[101];
int c[101];
int cache[101][10001] = {0, };

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        cin >> m[i];
    }
    for (int i = 1; i <= N; ++i)
    {
        cin >> c[i];
    }
    
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 0; j <= 10000; ++j)
        {
            if (j - c[i] >= 0)
            {
                cache[i][j] = max(cache[i][j], cache[i - 1][j - c[i]] + m[i]);
            }
            cache[i][j] = max(cache[i][j], cache[i - 1][j]);
        }
    }

    for (int i = 0; i <= 10000; i++)
	{
		if (cache[N][i] >= M)
		{
			cout << i;
			break;
		}	
	}
    return 0;
}

/*
* 01배낭문제.
* dp[i][j] : i번째 앱까지 확인했을 때 j의 비용으로 얻을 수 있는 최대의 메모리 일 때
* 사용할 수 있는 j의 비용이 늘어날수록 얻을 수 있는 메모리도 늘어날 텐데 
* 처음으로 메모리가 M을 넘는 때의 j값이 바로 이 문제의 정답이 된다.
* 메모리 값이 음수가 될 수 없기 때문.
* 배열을 다시 순회해야 하므로 재귀보다는 반복문 사용이 더 깔끔하다.
* https://cocoon1787.tistory.com/319
*/