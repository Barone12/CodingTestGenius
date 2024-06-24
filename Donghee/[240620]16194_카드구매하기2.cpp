#include <iostream>
#include <algorithm> 
using namespace std;
const int MAX = 1001;

int main() {
  int N;
  int P[MAX];
  int minCost[MAX]; // i 개를 사는 금액의 최솟값
  
  cin >> N;
  for(int i = 1; i <= N; i++){
  	cin >> P[i];
  	minCost[i] = P[i];
  }
  
  
  for(int i = 2; i <= N; i++){
  	for(int j = i-1; j >= 1; j--){
  		minCost[i] = min(minCost[j] + minCost[i-j], minCost[i]);
	  } 
  }
  
  cout << minCost[N];
}

