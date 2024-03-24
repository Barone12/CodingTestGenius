#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int swirl(int r, int c)
{
    int k = max(abs(r), abs(c));
    if (k == 0) return 1;
    int mx = (2 * k - 1) * (2 * k - 1);
    int len = 2 * k;
    int half = k;
    if (c == k && r < c)
    {
        return mx + half - r;
    }
    else if (r == -k && c < k)
    {
        return mx + len + half - c;
    }
    else if (c == -k && -k < r)
    {
        return mx + len * 2 + half + r;
    }
    else
    {
        return mx + len * 3 + half + c;
    }
}

string blank(int n)
{
    string result = "";
    for (int i = 0; i < n; ++i)
    {
        result += " ";
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    vector<vector<int>> result;
    int maxlen = 0;
    for (int i = r1; i <= r2; ++i)
    {
        vector<int> temp;
        for (int j = c1; j <= c2; ++j)
        {
            int cell = swirl(i, j);
            maxlen = max(maxlen, (int)to_string(cell).length());
            temp.push_back(cell);
        }
        result.push_back(temp);
    }
    for (int i = 0; i < result.size(); ++i)
    {
        for (int j = 0; j < result[i].size(); ++j)
        {
            cout << blank(maxlen - to_string(result[i][j]).length()) << result[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}

/*
* 주어진 범위가 작기 때문에 시간이나 메모리는 고려하지 않아도 된다.
* 특정 좌표에서의 값을 f(x, y)라 할 때 f(x, x) = (2x + 1) ^ 2이다. 이를 M(x)라 두자.
* f(x, y)에서 k = max(|x|, |y|)일 때, M(k - 1) < f(x, y) <= M(k)이다.
* 위 식을 함수로 만들어 수를 저장하고, 이를 토대로 공백 크기를 결정해 출력한다.
*/