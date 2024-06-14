#include<iostream>
#include<algorithm>
#include<vector>
#define setting ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define llt long long int
using namespace std;

#pragma region Variable
int n,k; // n개 k명 
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

/*
최선의 경우는 주전자들의 용량이 같은 경우이기에 R(최대값)을 주전자 최대 용량으로 설정
최악의 경우는 0이기에 L(최소값)을 주전자 최소 용량으로 설정
두 경우를 조합하여 가운데 값을 구하고, 나눠줄 수 있는 인원이 현재 인원보다 적다면 R을 가운데 값보다 1만큼 줄인 값으로 변경
그 외에는 L을 가운데 값보다 1증가한 값으로 변경
L이 R보다 커지는 경우는 더 이상 가운데 값을 구할 수 없기에 최대값을 출력
=> 이분탐색 알고리즘을 사용
*/