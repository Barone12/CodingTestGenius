#include<iostream>
#include<algorithm>
#include<vector>
#define setting ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define llt long long int
using namespace std;

#pragma region Variable
int n,k; // n°³ k¸í 
int ml[10010];

llt maxi = 0;
llt l = 1; 
llt r = 0;
llt mid = 0;
#pragma endregion


void Input() {
	cin >> n;
	cin >> k;
	int maxml = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> ml[i];
		maxml = maxml > ml[i] ? maxml : ml[i];
	}
	r = maxml;
}

void Solve() {
	while (r>=l) {
		int divide = 0;
		mid = (r + l) / 2;
		for (int i = 1; i <= n; i++) {
			divide += ml[i] / mid;
		}
		if (divide < k) {
			r = mid -1;
		}
		else {
			maxi = (mid > maxi) ? mid : maxi;
			l = mid +1;
		}
	}
	cout << maxi;
}

int main() {
	setting;
	Input();
	Solve();
	return 0;
}