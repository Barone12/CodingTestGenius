#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        int D = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
        int sum = (r1 + r2) * (r1 + r2);
        int diff = r1 > r2 ? (r1 - r2) * (r1 - r2) : (r2 - r1) * (r2 - r1);
        if (D == sum)
        {
            cout << 1;
        }
        else if (D == diff)
        {
            if (r1 == r2)
            {
                cout << -1;
            }
            else
            {
                cout << 1;
            }
        }
        else if (sum > D && D > diff)
        {
            cout << 2;
        }
        else
        {
            cout << 0;
        }
        cout << '\n';
    }
    return 0;
}

/*
* 중점과 반지름이 주어진 두 원의 접점 개수를 파악하는 문제.
* 두 원 중심간 거리를 D라 할 때 다음이 성립한다.
* 1. D > r1 + r2 -> 두 원은 떨어져 있다. (접점 0)
* 2. D == r1 + r2 -> 두 원은 외부에서 접한다. (접점 1)
* 3. r1 + r2 > D > |r1 - r2| -> 두 원은 두 점에서 만난다. (접점 2)
* 4. |r1 - r2| == D -> 두 원은 내부에서 접한다. (접점 1)
* 5. |r1 - r2| > D -> 한 원이 다른 원을 포함한다. (접점 0)
* 이 때, 4에서 r1 == r2이면 모든 점에서 접하므로 -1을 출력한다.
*/