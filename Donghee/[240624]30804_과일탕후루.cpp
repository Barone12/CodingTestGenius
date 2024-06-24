#include <iostream>
#include <algorithm> 
using namespace std;

const int MAX = 200001;
int ans = 0;

int GetFruitTypeCount(int* fruit){
	int count = 0;
	for(int i = 1; i <= 9; i++){
		if(fruit[i] > 0) count++;
	}
	return count; 
}

void TwoPointer(int left, int right, int N, int* S, int* fruit){
	if(right >= N) return;
	
	fruit[S[right]]++;
	int typeCount = GetFruitTypeCount(fruit);
	
	if(typeCount > 2){
		fruit[S[left]]--;
		left++;
	}else if(ans < right - left + 1){
		ans = right - left + 1;
	} 
	
	TwoPointer(left, right+1, N, S, fruit);
}
int main() {
  int N;
  int S[MAX];
  
  cin >> N;
  for(int i = 0; i < N; i++){
  	cin >> S[i];
  }
    
  if(N == 1){
  	cout << 1;
  	return 0;
  }
  
  int fruit[10];
  for(int i = 1; i <= 9; i++){
  	fruit[i] = 0;
  }
  
  fruit[S[0]]++;
  TwoPointer(0, 1, N, S, fruit);

  cout << ans;
}

