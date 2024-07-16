#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int min(int a, int b){
	return a < b ? a : b;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

	int N;
	vector<int> H;
	
	cin >> N;
	for(int i = 0; i < N; i++){
		int h; cin >> h;
		H.push_back(h);
	}
	sort(H.begin(), H.end());
	
	int l1, r1, l2, r2;
	int ans = 2000000000;
	
	
	for(l1 = 0; l1 < N-3; l1++){
		for(r1 = l1 + 3; r1 < N; r1++){
			l2 = l1 + 1; r2 = r1 - 1;
			while(l2 < r2){
				int snowman1 = H[l1] + H[r1];
				int snowman2 = H[l2] + H[r2];
				int diff = abs(snowman1-snowman2);
				
				ans = min(ans, diff);
				if(snowman1 < snowman2){
					r2--;
				}else{
					l2++;
				}
			} 
		}
	}
	cout << ans;
}
