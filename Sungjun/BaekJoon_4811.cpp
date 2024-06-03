#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#define setting ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define llt long long int
#define ll long long
using namespace std;

#pragma region Variable
int n = 1;
int dp[31][31] = {0,};
#pragma endregion

void Input() {
	
}

void Solve() {

}	

int main() {
	setting;
	for (int i = 0; i <= 30; i++) {
		for (int j = 0; j <= 30; j++) {
			if (i > j)
				continue;
			else if (i == 0)
				dp[j][i] = 1;
			else
				dp[j][i] = dp[j - 1][i] + dp[j][i - 1];
		}
	}

	while (true) {
		int n;
		cin >> n;
		if (n == 0)
			return 0;
		else
			cout << dp[n][n] << '\n';
	}
	return 0;
}