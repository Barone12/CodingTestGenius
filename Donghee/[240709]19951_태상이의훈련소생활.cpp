#include <iostream>
using namespace std;
const int MAX = 100000;

int main() {
	int N, M;
	int H[MAX];
	int HDiff[MAX];
	int prefix[MAX];
	
	cin >> N >> M;
	
	for(int i = 0; i < N; i++){
		cin >> H[i];
		HDiff[i] = 0;
		prefix[i] = 0;
	}
	
	int a[MAX], b[MAX], k[MAX];
	for(int i = 0; i < M; i++){
		cin >> a[i] >> b[i] >> k[i];
	}
	
	for(int i = 0; i < M; i++){
		HDiff[a[i]-1] += k[i];
		if(b[i] < N) HDiff[b[i]] += -1 * k[i];
	}
	
	for(int i = 0; i < N; i++){
		if(i == 0) prefix[i] = HDiff[i];
		else prefix[i] = prefix[i-1] + HDiff[i];
		
		cout << prefix[i] + H[i] << " "; 
	}
}

