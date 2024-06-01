#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#define setting ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define llt long long int
using namespace std;

// 1577��

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
���ڿ��� ù��° ���ں��� �����Ͽ� ������ ���ڱ��� �縰������� Ȯ���մϴ�.
���� �ѹ��� �縰����̿����� ���ٸ� ���ڿ� ����*2-1�� ����մϴ�.
���� ���� �ִٸ� �� ������ ���� ���ڵ��� ���� �ڿ� �߰��ϸ� �縰����� �ϼ��Ǳ⿡ ���ڿ� ���� + �縰����� ���ڿ��� �ε����� ����ϸ� �˴ϴ�.
*/