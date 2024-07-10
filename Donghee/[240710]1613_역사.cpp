#include <iostream>
using namespace std;
const int MAX = 400;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, k;
	cin >> n >> k;
	
	int dist[MAX][MAX];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			dist[i][j] = MAX+1;
		}
	}
	
	for(int i = 0; i < k; i++){
		int before, after;
		cin >> before >> after;
		before--; after--;
		dist[before][after] = 1;
	}
	
	// Floyd-Warshall
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	
	int s;
	cin >> s;
	for(int i = 0; i < s; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		if(dist[a][b] > MAX && dist[b][a] > MAX) cout << 0 << '\n';
		else if(dist[a][b] <= MAX) cout << -1 << '\n';
		else cout << 1 << '\n';
	}
}

