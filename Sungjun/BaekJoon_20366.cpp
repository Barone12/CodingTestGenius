#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#define setting ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define llt long long int
#define ll long long
using namespace std;

// 20366번 골드3 같이 눈사람 만들래?

#pragma region Variable
int n;
vector<int> hvec;
vector<pair<int, pair<int, int>>>all; // 눈사람의 키, 인덱스1, 인덱스2
#pragma endregion

void Input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll num;
		cin >> num;
		hvec.push_back(num);
	}
}

void Solve() {
	// nc2 경우의 수
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			all.push_back(make_pair(hvec[i] + hvec[j], make_pair(i, j)));
		}
	}
	sort(all.begin(), all.end());
	
	int mini = 1000000001;

	int length = all.size() - 1;
	for (int i = 0; i < length; i++) {
		for (int j = i + 1; j < length + 1; j++) {
			int st1 = all[i].second.first;
			int ed1 = all[i].second.second;
			int st2 = all[j].second.first; 
			int ed2 = all[j].second.second;
			if ((st1!=st2)&&(st1!=ed2)&&(ed1!=st2)&&(ed1!=ed2)) {
				mini = mini > all[j].first - all[i].first ? all[j].first - all[i].first : mini;
				break;
			}
		}
	}
	cout << mini << endl;
}	

int main() {
	setting;
	Input();
	Solve();
	return 0;
}

/*
1. n개 중에서 2개를 뽑아 만들 수 있는 모든 경우의 수를 저장
2. 눈사람의 키, 인덱스1, 인덱스2를 저장
3. 눈사람의 키를 첫번째 인수로 받는 Vector에 sort 함수를 사용했을 때, 첫번째 인수를 기준으로 정렬한다.
4. 바로 뒤에 있는 값이 최소로 차이나는 눈사람의 키이다.
5. 인덱스가 겹치면 안된다는 점을 조건으로 넣어주어 계산하면 최소값을 구할 수 있다.
*/