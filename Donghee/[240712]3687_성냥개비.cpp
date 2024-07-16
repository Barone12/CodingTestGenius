#include <iostream>
#include <stack>
using namespace std;

int matchNum[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int MinNumByMarch(int march, bool canZero){
	if(march == 2) return 1;
	if(march == 3) return 7;
	if(march == 4) return 4;
	if(march == 5) return 2;
	if(march == 6) return canZero ? 0 : 6;
	if(march == 7) return 8;
	return -1;
}

// 17,,,,,,,,,,,,,,,,,
stack<int> MinMarch(int num){
	stack<int> minNum;
	
	int digit = num / 7;
	digit += num % 7 > 0 ? 1 : 0;
	
	while(digit > 0){
		digit--;
		if(num == 17){
			minNum.push(0);
			minNum.push(0);
			minNum.push(2);
			break;
		}
		if(num <= 7){
			minNum.push(MinNumByMarch(num, false));
			num = 0;
		}else if(num - 7 >= 2){
			if(num - 7 <= 7){
				for(int i = 1; i <= 9; i++){
					int nowNum = MinNumByMarch(num - matchNum[i], true);
					if(nowNum != -1){
						minNum.push(nowNum);
						num -= matchNum[nowNum];
						break;
					}
				}
			}else{
				
				minNum.push(8);
				num -= matchNum[8];
			}
		}else{
			minNum.push(MinNumByMarch(num - 2, true));
			num -= num - 2;
		}
	}
	
	return minNum;
}

stack<int> MaxMarch(int num){
	stack<int> maxNum;
	while(num >= 2){
		if(num == 3){
			maxNum.push(7);
			num -= 3;
		}else{
			maxNum.push(1);
			num -= 2;
		}
	}
	
	return maxNum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		
		stack<int> min = MinMarch(num);
		stack<int> max = MaxMarch(num);
		
		while(!min.empty()){
			cout << min.top();
			min.pop();
		}
		cout << ' ';
		while(!max.empty()){
			cout << max.top();
			max.pop();
		}
		cout << '\n';
	}
}

