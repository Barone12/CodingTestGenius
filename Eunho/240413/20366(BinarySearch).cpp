#include <iostream>
#include <algorithm>
using namespace std;

int N;
int ball[600];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> ball[i];
    }
    sort(ball, ball + N);
    int result = 9876543210;
    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            for (int k = j + 1; k < N; ++k)
            {
                int lo = k + 1, hi = N;
                int mid;
                int target = -ball[i] + ball[j] + ball[k];
                while (lo <= hi)
                {
                    mid = (lo + hi) / 2;
                    result = min(result, abs(target - ball[mid]));
                    if (target > ball[mid])
                    {
                        lo = mid + 1;
                    }
                    else
                    {
                        hi = mid - 1;
                    }
                }
            }
        }
    }
    cout << result;
    return 0;
}
