#include <iostream>
using namespace std;

const int SIZE = 10000001;
int isPrime[SIZE];

int main() {
  long long A, B;
  cin >> A >> B;

  for (int idx = 2; idx < SIZE; idx++) {
    isPrime[idx] = 1;
  }

  for (long long num = 2; num * num < SIZE; num++) {
    if (!isPrime[num]) continue;
    for (long long multiple = 2 * num; multiple < SIZE; multiple += num) {
      isPrime[multiple] = 0;
    }
  }

  int aUnderCount = 0;
  int bUnderCount = 0;
  for (long long num = 2; num * num <= B; num++) 
  {
    if (!isPrime[num]) continue;
    // almostPrime <= B; 로 조건을 작성하면 마지막 분기에서 오버플로우 발생
    for (long long almostPrime = num; almostPrime <= B / num; almostPrime *= num) 
    {
      if (almostPrime * num < A) aUnderCount++;
      bUnderCount++;
    }
  }

  cout << bUnderCount - aUnderCount;
}

