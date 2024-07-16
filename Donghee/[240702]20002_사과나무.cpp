#include <iostream>
using namespace std;
const int MAX = 301;

int main() {
	int N;
	cin >> N;
	
	int orchard[MAX][MAX];
	int prefix[MAX][MAX];
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> orchard[i][j];
		}
	}
	
	prefix[0][0] = orchard[0][0];
	for(int i = 1; i < N; i++){
		prefix[i][0] = prefix[i-1][0] + orchard[i][0];
		prefix[0][i] = prefix[0][i-1] + orchard[0][i];
	}
	
	for(int i = 1; i < N; i++){
		for(int j = 1; j < N; j++){
			prefix[i][j] = prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1] + orchard[i][j];
		}
	}
	
	int profit;
	int ans = prefix[0][0];
	for(int K = 0; K < N; K++){
		for(int i = 0; i < N-K; i++){
			for(int j = 0; j < N-K; j++){
				profit = prefix[i+K][j+K] - prefix[i-1][j+K] - prefix[i+K][j-1] + prefix[i-1][j-1];
				if(ans < profit) ans = profit;
			}
		}
	}
	
	cout << ans;
}

