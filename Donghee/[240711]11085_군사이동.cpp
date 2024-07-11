#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int MAX = 1000;

int parent[MAX];

int FindParent(int a){
	if(parent[a] == a) return a;
	return FindParent(parent[a]);
}

void Union(int a, int b){
	a = FindParent(a); b = FindParent(b);
	parent[b] = a;
}

bool Cmp(const pair<pair<int, int>, int> &p1, const pair<pair<int, int>, int> &p2){
	if(p1.second > p2.second) return true;
	else return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int p, w;
	cin >> p >> w;
	
	int c, v;
	cin >> c >> v;
	
	vector<pair<pair<int, int>, int> > path;
	for(int i = 0; i < w; i++){
		int start, end, width;
		cin >> start >> end >> width;
		path.push_back(make_pair(make_pair(start, end), width));
	}
	
	sort(path.begin(), path.end(), Cmp);
	for(int i = 0; i < p; i++){
		parent[i] = i;
	}

	vector<pair<pair<int, int>, int> > route;
	int idx = 0;
	for(int i = 0; i < path.size(); i++){
		pair<pair<int, int>, int> biggest = path[i];
		int start = biggest.first.first;
		int end = biggest.first.second;
		
		Union(start, end);
		route.push_back(biggest);
		if(FindParent(c) == FindParent(v)) break;
	}
	
	cout << route.back().second;
}

