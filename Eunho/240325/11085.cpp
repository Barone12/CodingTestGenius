#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int p, w, c, v;
vector<vector<int>> edges;
int parent[1000];

int find(int u)
{
    if (u == parent[u])
    {
        return u;
    }
    else
    {
        return find(parent[u]);
    }
}

bool merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
    {
        return false;
    }
    parent[u] = v;
    return true;
}

bool isMerged(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
    {
        return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> p >> w >> c >> v;
    for (int i = 0; i < p; ++i)
    {
        parent[i] = i;
    }
    for (int i = 0; i < w; ++i)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edges.push_back({-z, x, y});
    }
    sort(edges.begin(), edges.end());
    int result = 1001;
    for (vector<int> edge : edges)
    {
        if (merge(edge[1], edge[2]))
        {
            result = min(result, -edge[0]);
            if (isMerged(c, v))
            {
                break;
            }
        }
    }
    cout << result;
    return 0;
}

/*
* ����� �������� �ּ� ���д� Ʈ���� �����.
* ����� ū �������� ���ʷ� ����� c, v�� ���Ͽµɶ����� ����.
* c~v�� �մ� ������ ������ ������ ������ �����ϸ� �ȴ�.
* �ð����⵵�� O(n)�̶� ���� ����(O(nlgn))�� �ϸ� ������ ���� �� �ִ�.
*/