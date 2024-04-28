#include <iostream>
using namespace std;

int N, K;
int arr[11];
int answer = 0;

void print(int cnt)
{
	for (int i = 0; i < cnt; i++)
	{
		cout << arr[i];
		if (i != cnt - 1)
			cout << "+";
	}
	cout << "\n";	
}

void backtrack(int sum, int cnt)
{
	if (sum == N)
	{
		answer++;
		if (answer == K)
		{
			print(cnt);
			exit(0);
		}
		return;
	}
	else if (sum > N)
		return;

	for (int i = 1; i <= 3; i++)
	{
		arr[cnt] = i;
		backtrack(sum + i, cnt + 1);		
	}
}

int main()
{	
	cin >> N >> K;	
	backtrack(0, 0);
	if (answer < K)
		cout << "-1\n";
}