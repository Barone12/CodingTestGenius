#include <iostream>
using namespace std;
const int PEOPLE_MAX = 26;
const int LINE_MAX = 1000;

int main() {
	int K, N;
	cin >> K >> N;
	
	char start[PEOPLE_MAX];
	char res[PEOPLE_MAX];
	for(int i = 0; i < K; i++){
		start[i] = 'A' + i;
		cin >> res[i];
	}
	
	int qmLine;
	char ladder[LINE_MAX][PEOPLE_MAX-1];
	for(int i = 0; i < N; i++){
		for(int j = 0; j < K-1; j++){
			cin >> ladder[i][j];
			if(ladder[i][j] == '?') qmLine = i;
		}
	}
	
	// From Bottom To QMLine
	for(int i = N-1; i > qmLine; i--){
		for(int j = 0; j < K-1; j++){
			if(ladder[i][j] == '-'){
				char tmp = res[j];
				res[j] = res[j+1];
				res[j+1] = tmp;
			}
		}
	}
	
	// To Start From QMLine
	for(int i = 0; i < qmLine; i++){
		for(int j = 0; j < K-1; j++){
			if(ladder[i][j] == '-'){
				char tmp = start[j];
				start[j] = start[j+1];
				start[j+1] = tmp;
			}
		}
	}
	
	// QMLine Guess
	for(int i = 0; i < K-1; i++){
		if(start[i] == res[i]) ladder[qmLine][i] = '*';
		else {
			ladder[qmLine][i] = '-';
			ladder[qmLine][i+1] = '*';
			i++;
		}
	}
	
	// QMLine Down
	for(int i = 0; i < K-1; i++){
		if(ladder[qmLine][i] == '-'){
			char tmp = start[i];
			start[i] = start[i+1];
			start[i+1] = tmp;
		}
	}
	
	// Answer Check
	bool canConnect = true;
	for(int i = 0; i < K; i++){
		if(start[i] != res[i]) canConnect = false;
	}
	
	for(int i = 0; i < K-1; i++){
		if(canConnect){
			cout << ladder[qmLine][i];
		}else{
			cout << 'x';
		}
	}
}

