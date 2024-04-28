#include <iostream>
using namespace std;

int N, K;
int cache[12];

int count(int n)
{
    if (n < 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }
    int& res = cache[n];
    if (res != -1)
    {
        return res;
    }
    return res = count(n - 1) + count(n - 2) + count(n - 3);
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N >> K;
    for (int i = 1; i <= N; ++i)
    {
        cache[i] = -1;
    }
    if (K > count(N))
    {
        cout << -1;
        return 0;
    }
    while (N > 0)
    {
        for (int i = 1; i <= 3; ++i)
        {
            if (K > count(N - i))
            {
                K -= count(N - i);
            }
            else
            {
                cout << i;
                N -= i;
                break;
            }
        }
        if (N > 0)
        {
            cout << '+';
        }
    }
    return 0;
}

/*
* 앞에서부터 1,2,3을 만들어낸다는 생각으로 접근한다.
*/