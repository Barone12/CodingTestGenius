#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> card(N+1, 0);
	vector<int> dp(N+1, 0);
	for (int i = 1; i <= N; i++)
	{		
		cin >> card[i];
	}
	
	dp[1] = card[1];
	for (int i = 2; i <= N; i++)
	{
		dp[i] = card[i];
		for (int j = 1; j < i; j++)
		{
			dp[i] = min(dp[i], dp[i - j] + dp[j]);
		}
	}

	cout << dp[N] << "\n";
}