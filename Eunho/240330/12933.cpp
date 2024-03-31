#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin >> s;
    int result = 0;
    int cnt = 0;
    vector<int> ducks;
    for (int i = 0; i < s.length(); ++i)
    {
        int index = 0;
        switch (s[i])
        {
        case 'q':
            index = 0;
            break;
        case 'u':
            index = 1;
            break;
        case 'a':
            index = 2;
            break;
        case 'c':
            index = 3;
            break;
        case 'k':
            index = 4;
            break;
        default:
            cout << -1;
            return 0;
        }
        int found = false;
        for (int j = 0; j < ducks.size(); ++j)
        {
            if (ducks[j] == index)
            {
                ducks[j]++;
                found = true;
                if (index == 4)
                {
                    result = max(result, cnt);
                    cnt --;
                }
                break;
            }
        }
        if (!found)
        {
            if (index == 0)
            {
                ducks.push_back(1);
                cnt++;
            }
            else
            {
                cout << -1;
                return 0;
            }
        }
    }
    for (int i = 0; i < ducks.size(); ++i)
    {
        if (ducks[i] != 5)
        {
            cout << -1;
            return 0;
        }
    }
    cout << result;
    return 0;
}

/*
* 울음소리가 얼마나 겹치는지 파악하는 문제.
*/