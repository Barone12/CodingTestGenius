#include <iostream>
using namespace std;

int N, K;
int S[10000];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; ++i)
    {
        cin >> S[i];
    }
    long long lo = 0;
    long long hi = 2147483647;
    long long mid;
    int res = 0;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        int cnt = 0;
        for (int i = 0; i < N; ++i)
        {
            cnt += S[i] / mid;
        }
        if (cnt >= K)
        {
            res = mid;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    cout << res;
    return 0;
}

/*
* 이분탐색을 통해 1~1000000 사이 값을 대입해 문제를 푼다.
* 탐색 범위가 int 크기의 끝에 걸쳐 있어 자료형을 long long 으로 두어야 한다.
*/