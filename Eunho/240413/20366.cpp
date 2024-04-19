#include <iostream>
#include <algorithm>
using namespace std;

int N;
int ball[600];
int result = 9876543210;

void MakeSnowman(int start, int end)
{
    int i = start + 1;
    int j = end - 1;
    while (i < j)
    {
        int temp = ball[start] + ball[end] - ball[i] - ball[j];
        result = min(result, abs(temp));
        if (temp > 0)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> ball[i];
    }
    sort(ball, ball + N);
    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            MakeSnowman(i, j);
        }
    }
    cout << result;
    return 0;
}

/*
* 차이가 최소인 조합 두개를 만드는 문제.
* 브루트포스 사용 시 O(nC4)로 N=600에서 시간초과가 발생한다.
* 미리 눈사람 하나를 만들고, 나머지 하나는 투 포인터로 양 끝에서 세면서 
* 차이가 작은 눈사람을 하나 더 만드는 작업을 진행한다.
*/