#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#define setting ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define llt long long int
using namespace std;

// 1577번

#pragma region Variable
string input;
int inputLength;
int pelindromNum = -1;
#pragma endregion

void Input() {
	cin >> input;
	inputLength = input.length();
}

bool CheckPelindorm(int idx) {
	int end = inputLength - 1;
	for (int i = idx; i < inputLength; i++) {
		if (i >= end)
			return true;
		if (input[i] != input[end])
			return false;
		end -= 1;
	}
	return false;
}

void Solve() {
	int res = inputLength * 2 - 1;
	for (int i = 0; i < inputLength; i++) {
		if (CheckPelindorm(i)) {
			res = inputLength + i;
			break;
		}
	}
	cout << res << "\n";
}	

int main() {
	setting;
	Input();
	Solve();
	return 0;
}

/*
문자열의 첫번째 문자부터 시작하여 마지막 문자까지 펠린드롬인지 확인합니다.
만약 한번도 펠린드롬이였던이 없다면 문자열 길이*2-1를 출력합니다.
같은 적이 있다면 그 문자의 앞의 문자들의 수만 뒤에 추가하면 펠린드롬이 완성되기에 문자열 길이 + 펠린드롬인 문자열의 인덱스를 출력하면 됩니다.
*/