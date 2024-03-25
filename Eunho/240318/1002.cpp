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
* ������ �������� �־��� �� ���� ���� ������ �ľ��ϴ� ����.
* �� �� �߽ɰ� �Ÿ��� D�� �� �� ������ �����Ѵ�.
* 1. D > r1 + r2 -> �� ���� ������ �ִ�. (���� 0)
* 2. D == r1 + r2 -> �� ���� �ܺο��� ���Ѵ�. (���� 1)
* 3. r1 + r2 > D > |r1 - r2| -> �� ���� �� ������ ������. (���� 2)
* 4. |r1 - r2| == D -> �� ���� ���ο��� ���Ѵ�. (���� 1)
* 5. |r1 - r2| > D -> �� ���� �ٸ� ���� �����Ѵ�. (���� 0)
* �� ��, 4���� r1 == r2�̸� ��� ������ ���ϹǷ� -1�� ����Ѵ�.
*/