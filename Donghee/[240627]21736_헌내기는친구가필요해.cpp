#include <iostream>
using namespace std;

const int MAX = 601;
char campus[MAX][MAX];

bool visited[MAX][MAX];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int ans = 0;

void DFS(int x, int y, int N, int M){
	for(int dir = 0; dir < 4; dir++){
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		
		if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
		
		if(visited[nx][ny]) continue;
		visited[nx][ny] = true;
		
		if(campus[nx][ny] == 'X') continue;
		if(campus[nx][ny] == 'P') ans++;
		DFS(nx, ny, N, M);
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	
	int startCoord[2];
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> campus[i][j];
			if(campus[i][j] == 'I') { startCoord[0] = i; startCoord[1] = j; }
		}
	}
	
	DFS(startCoord[0], startCoord[1], N, M);
	
	if(ans == 0) cout << "TT";
	else cout << ans;
}

