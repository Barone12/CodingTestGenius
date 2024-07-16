#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

// SET Container.... T.T
int main() {
	int N;
	cin >> N;
	
	map<int, int> list;
	set< pair<int ,int> > listSet;
	for(int i = 0; i < N; i++){
		int P, L;
		cin >> P >> L;
		listSet.insert({L, P});
		list[P] = L;
	} 

	int M;
	cin >> M;
	for(int i = 0; i < M; i++){
		string command;
		cin >> command;
		if(command == "recommend"){
			int x;
			cin >> x;
			cout << (x == -1 ? (*listSet.begin()).second : (*listSet.rbegin()).second) << endl;
		}else if(command == "add"){
			int P, L;
			cin >> P >> L;
			listSet.insert({L, P});
			list[P] = L;
		}else if(command == "solved"){
			int P;
			cin >> P;
			listSet.erase({list[P], P});
			list.erase(P);
		}
	}
}

