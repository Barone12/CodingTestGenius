#include <iostream>
#include <cmath>
#define MAX 10000001
using namespace std;

bool prime[MAX];

void InitializePrime()
{
	for (int i = 2; i < MAX; i++)	
		prime[i] = true;	
	
	for (long long i = 2; i < MAX; i++)
	{
		if (prime[i] == false)
			continue;

		for (long long j = i * i; j < MAX; j += i)
		{
			prime[j] = false;
		}
	}
}

int Solve(long long A, long long B)
{
	int answer = 0;
	long long upper = static_cast<long long>(sqrt(B));
	for (long long i = 2; i <= upper; i++)
	{
		if (prime[i] == true)
		{
			long long temp = i;
			while (temp <= B / i)
			{
				temp *= i;
				if (temp >= A)
					answer++;
			}
		}
	}
	return answer;
}

int main()
{
	long long A, B;
	cin >> A >> B;

	InitializePrime();		
	cout << Solve(A, B) << "\n";	

	return 0;
}