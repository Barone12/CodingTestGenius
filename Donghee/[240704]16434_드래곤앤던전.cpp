#include <iostream>
using namespace std;
const long long int MAX = 123455876544123456;

long long int heroMaxHP;
long long int heroCurHP;
long long int heroIniATK;
long long int heroATK;

int room[3][123456];
	
bool Combat(long long int a, long long int h){
	long long int combatCount;
	
	long long int heroCombat;
	if(h % heroATK > 0) heroCombat = h / heroATK + 1; 
	else heroCombat = h / heroATK;
	
	long long int monsterCombat;
	if(heroCurHP % a > 0) monsterCombat = heroCurHP / a + 1;
	else monsterCombat = heroCurHP / a;
	
	if(heroCombat <= monsterCombat){
		heroCurHP -= (heroCombat-1) * a;
		return true;
	}
	else {
		heroCurHP = -1;
		return false;
	}
}

void Potion(long long int a, long long int h){
	heroATK += a;
	heroCurHP += h;
	if(heroCurHP > heroMaxHP) heroCurHP = heroMaxHP;
}

void Dungeon(int N){	
	for(int i = 0; i < N; i++){
		if(room[0][i] == 1){
			bool combatRes = Combat(room[1][i], room[2][i]);
			if(!combatRes) break;
		}
		else if(room[0][i] == 2){
			Potion(room[1][i], room[2][i]);
		}
	}
}

int main() {
	int N;
	cin >> N >> heroIniATK;
	
	for(int i = 0; i < N; i++){
		cin >> room[0][i] >> room[1][i] >> room[2][i];
	}
	
	long long int start = 1;
	long long int end = MAX;
	while(start <= end){
		long long int mid = (start + end) / 2;
		heroMaxHP = heroCurHP = mid;
		heroATK = heroIniATK;
		
		Dungeon(N);
		if(heroCurHP <= 0) start = mid + 1;
		else {
			end = mid - 1;
		}
	}
	
	cout << start;
}

