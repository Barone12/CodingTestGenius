#include <iostream>
using namespace std;

int n;
int files[500];
int cache[501][501];
int prefix[501];

int shortest(int start, int end)
{
    int & res = cache[start][end];
    if (res != -1)
    {
        return res;
    }
    if (start == end - 1)
    {
        return res = 0;
    }
    res = 987654321;
    for (int i = start + 1; i < end; ++i)
    {
        res = min(res, shortest(start, i) + shortest(i, end));
    }
    return res = res + prefix[end] - prefix[start];
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 0; i <= n; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                cache[i][j] = -1;
            }
        }
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> files[i];
            prefix[i] = sum;
            sum += files[i];
        }
        prefix[n] = sum;
        cout << shortest(0, n) << '\n';
    }
    return 0;
}

/*
* 연속한 파일을 합쳐야 한다.
* 점화식으로 단계별로 쪼개 합친다.
* 누적합으로
*/