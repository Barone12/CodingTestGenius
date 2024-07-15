#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
const int MAX = 100;

int R, C;
string board[MAX];
string direction;
int arduinoBoard[MAX][MAX];
int crazyArduinoBoard[MAX][MAX];
int arduino;
vector<int> crazyArduino;

int Move(int coord, int dir) {
  int r = coord / C;
  int c = coord % C;
  switch (dir) {
  case 1:
    r++;
    c--;
    break;
  case 2:
    r++;
    break;
  case 3:
    r++;
    c++;
    break;
  case 4:
    c--;
    break;
  case 5:
    break;
  case 6:
    c++;
    break;
  case 7:
    r--;
    c--;
    break;
  case 8:
    r--;
    break;
  case 9:
    r--;
    c++;
    break;
  }
  if(r >= R || r < 0 || c >= C || c < 0) return MAX*MAX+1;
  return r * C + c;
}

bool MoveArduino(int dir){
	int nextCoord = Move(arduino, dir);
	int nextR = nextCoord / C;
	int nextC = nextCoord % C;
	
	if(crazyArduinoBoard[nextR][nextC] > 0) return false;
	arduinoBoard[arduino/C][arduino%C] = 0;
	arduinoBoard[nextR][nextC] = 1;
	arduino = nextCoord;
	return true;
}

bool MoveCrazy() {
  int targetR = arduino / C;
  int targetC = arduino % C;
	
  for(int i = 0; i < crazyArduino.size(); i++){
  	  int coord = crazyArduino[i];
	  int minDist = MAX * MAX;
	  int resultCoord;
	  for (int dir = 1; dir <= 9; dir++) {
	  	if(dir == 5) continue;
	    int tmpCoord = Move(coord, dir);
	    if(tmpCoord > MAX*MAX) continue;
	    int tmpR = tmpCoord / C;
	    int tmpC = tmpCoord % C;
	    
	    int dist = abs(targetR - tmpR) + abs(targetC - tmpC);
	    if (dist < minDist) {
	      minDist = dist;
	      resultCoord = tmpCoord;
	    }
	  }
	  if(arduinoBoard[resultCoord/C][resultCoord%C] > 0) return false;
	  crazyArduinoBoard[coord/C][coord%C]--;
	  crazyArduinoBoard[resultCoord/C][resultCoord%C]++;
	  crazyArduino[i] = resultCoord;
  }
  return true;
}

void Explode(){
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (crazyArduinoBoard[i][j] >= 2) {
				crazyArduinoBoard[i][j] = 0;
				for (int k = 0; k < crazyArduino.size(); k++) {
					int curR = crazyArduino[k] / C;
					int CurC = crazyArduino[k] % C;
					if ((curR == i) && (CurC == j)) {
						crazyArduino.erase(crazyArduino.begin() + k);
						k--;
					}
				}
			}
		}
	}
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> R >> C;


  for (int r = 0; r < R; r++) {
    cin >> board[r];
    for (int c = 0; c < C; c++) {
      if (board[r][c] == 'I'){
      	arduino = r*C+c;
      	arduinoBoard[r][c] = 1;
	  }
      else if (board[r][c] == 'R') {
      	crazyArduino.push_back(r*C+c);
      	crazyArduinoBoard[r][c] = 1;
      }
    }
  }

  cin >> direction;

  bool isWin = true;
  int turn;
  for (turn = 0; turn < direction.length(); turn++) {
    // 1, 2
    if(!MoveArduino(direction[turn]-48)){
    	isWin = false;
    	break;
	}

    // 3, 4
    if(!MoveCrazy()){
    	isWin = false;
    	break;
	}

    // 5
    Explode();
  }
  
  if (isWin) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arduinoBoard[i][j] == 1) {
				board[i][j] = 'I';
			}
			else{
				board[i][j] = '.';
			}
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (crazyArduinoBoard[i][j] != 0) {
				board[i][j] = 'R';
			}
		}
	}
	for (int i = 0; i < R; i++) {
		cout << board[i];
      cout << '\n';
	}
  } else {
    cout << "kraj " << turn+1;
  }
}

