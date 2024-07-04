#include <iostream>
using namespace std;

const int MAX = 300001;

int main() {
	int N, B, W;
	cin >> N >> B >> W;

	char path[MAX];
	for(int i = 0; i < N; i++){
		cin >> path[i];
	}
	int bCount = 0;
	int wCount = 0;
	int ans = 0;
	
	int pathStart = 0;
	int pathEnd = 0;	
	
	while(pathEnd < N){
		if(bCount > B){
			if(path[pathStart++] == 'W') wCount--;
			else bCount--;
		}else{
			if(pathEnd != N){
				if(path[pathEnd++] == 'W') wCount++;
				else bCount++;
			}
		}
		
		if(wCount >= W && bCount <= B){
			int pathLength = pathEnd - pathStart;
			if(ans < pathLength) ans = pathLength;
		}
	}
	
	cout << ans;
}

