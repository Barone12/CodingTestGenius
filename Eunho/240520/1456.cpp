#include <iostream>
using namespace std;

long long A, B;
bool prime[10000001];
long long n = 10000000;

void sieve()
{
    for (int i = 2; i <= n; ++i)
    {
        prime[i] = true;
    }
    for (int i = 2; i * i <= n; ++i)
    {
        if (prime[i])
        {
            for (int j = i * 2; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> A >> B;
    sieve();
    long long answer = 0;
    for (int i = 2; i < 50; ++i)
    {
        for (long j = 2; j <= min(n, B); ++j)
        {
            if (!prime[j])
            {
                continue;
            }
            long long temp = j;
            for (int k = 1; k < i; ++k)
            {
                temp *= j;
            }
            if (temp < A)
            {
                continue;
            }
            else if (temp > B)
            {
                break;
            }
            else
            {
                answer ++;
            }
        }
    }
    cout << answer;
    return 0;
}

/*
* 제곱인 수를 비교하는 것이므로 2부터 10^14의 제곱근까지 수들 중 소수만 순회한다.
* 10^14는 10^7의 제곱이므로, 2^50 > 10^14 이므로, 
* 시간복잡도를 생각했을 때 소수 판별 후 순회하는 최대 횟수는 5억회이다.
* 일반적으로 이는 1초 안에 순회할 수 있는 수준이다.
* 소수 판별은 에라토스테넷의 채를 사용한다.
*/