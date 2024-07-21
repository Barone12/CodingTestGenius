#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> costs(N + 1, 0);
    vector<int> dp(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        cin >> costs[i];
    }        

    for (int i = 1; i <= N; i++)
    {
        dp[i] = costs[i];
        for (int j = 1; j <= i; j++)
        {
            dp[i] = max(dp[i], dp[j] + dp[i - j]);
        }
    }

    cout << dp[N] << "\n";
    return 0;
}