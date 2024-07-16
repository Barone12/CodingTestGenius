#include <iostream>
using namespace std;
const int MAX = 100000;
int main() {
	int N;
	int honey[MAX];
	int maxHoney = 0;
	int prefix[MAX];
	prefix[0] = 0;
	
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> honey[i];
		if(maxHoney < honey[i]) maxHoney = honey[i];
		if(i == 0) prefix[i] = honey[i];
		else prefix[i] = honey[i] + prefix[i-1];
	}
	
	int ans = 0;
	//Right Dest
	for(int i = 1; i < N; i++){
		int now = 0;
		now += prefix[N-1] - honey[0] - honey[i];
		now += (prefix[N-1] - prefix[i]);
		if(ans < now) ans = now;
	}
	
	//Left Dest
	for(int i = N-2; i >= 1; i--){
		int now = 0;
		now += prefix[N-1] - honey[N-1] - honey[i];
		now += prefix[i-1];
		if(ans < now) ans = now;
	}
	
	//Middle Dest
	for(int i = N-1; i >= 1; i--){
		int now = 0;
		now += prefix[N-1] - honey[0] - honey[N-1] + maxHoney;
		if(ans < now) ans = now;
	}
	
	cout << ans;
}

