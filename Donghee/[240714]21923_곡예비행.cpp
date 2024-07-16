#include <iostream>
using namespace std;
const int MAX = 1000;

int N, M;
int grid[MAX][MAX];
int increaseDP[MAX][MAX];
int decreaseDP[MAX][MAX];
int ans = -1000000000;

int max(int a, int b){
	return a > b ? a : b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	
	for(int n = 0; n < N; n++){
		for(int m = 0; m < M; m++){
			cin >> grid[N-1-n][m];
		}
	}
	
	for(int y = 0; y < N; y++){
		for(int x = 0; x < M; x++){
			if(y == 0 && x == 0) increaseDP[y][x] = grid[y][x];
			else if(y == 0) increaseDP[y][x] = increaseDP[y][x-1] + grid[y][x];
			else if(x == 0) increaseDP[y][x] = increaseDP[y-1][x] + grid[y][x];
			else increaseDP[y][x] = max(increaseDP[y-1][x], increaseDP[y][x-1]) + grid[y][x];
		}
	}
	
	for(int y = 0; y < N; y++){
		for(int x = M-1; x >= 0; x--){
			if(y == 0 && x == M-1) decreaseDP[y][x] = grid[y][x];
			else if(y == 0) decreaseDP[y][x] = decreaseDP[y][x+1] + grid[y][x];
			else if(x == M-1) decreaseDP[y][x] = decreaseDP[y-1][x] + grid[y][x];
			else decreaseDP[y][x] = max(decreaseDP[y-1][x], decreaseDP[y][x+1]) + grid[y][x];
		}
	}
	
	for(int y = 0; y < N; y++){
		for(int x = 0; x < M; x++){
			//cout << "UP:" << increaseDP[y][x] << " DOWN:" << decreaseDP[y][x] << '\n';
			ans = max(ans, increaseDP[y][x] + decreaseDP[y][x]);
		}
	}

	cout << ans;
}

