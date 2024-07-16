#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

typedef struct line{
	int start;
	int end;
	int cost;
}line;

const int MAX = 500*500;
int parent[MAX];

bool Cmp(line &a, line &b){
	if(a.cost < b.cost) return true;
	return false;
}

int FindParent(int a){
	if(parent[a] == a) return a;
	return FindParent(parent[a]);
}

void Union(int a, int b){
	a = FindParent(a); b = FindParent(b);
	if(a < b) parent[a] = b;
	else parent[b] = a;
}

bool IsSameParent(int a, int b){
	if(FindParent(a) == FindParent(b)) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T;
	cin >> T;
	
	for(int i = 0; i < T; i++){
		int R, C;
		cin >> R >> C;
		
		vector<line> v;
		for(int r = 0; r < R; r++){
			for(int c = 0; c < C-1; c++){
				int cost; cin >> cost;
				int start = (r * C) + c;
				int end = (r * C) + c + 1;
				v.push_back({start, end, cost});
			}
		}
		
		for(int r = 0; r < R-1; r++){
			for(int c = 0; c < C; c++){
				int cost; cin >> cost;
				int start = (r * C) + c;
				int end = ((r + 1) * C) + c;
				v.push_back({start, end, cost});
			}
		}
		
		for (int l = 0; l < (R * C); l++) {
			parent[l] = l;
		}
		
		sort(v.begin(), v.end(), Cmp);
		vector<line> network;
		int maxSize = R * C - 1;
		int idx = 0;
		int ans = 0;
		while(network.size() < maxSize){
			line min = v[idx++];
			if(IsSameParent(min.start, min.end)) continue;
			Union(min.start, min.end);
			network.push_back(min);
			ans += min.cost;
		}
		
		cout << ans << '\n';
	}
}

