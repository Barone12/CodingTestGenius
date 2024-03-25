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
* 비용을 기준으로 최소 스패닝 트리를 만든다.
* 비용이 큰 간선부터 차례로 만들어 c, v가 유니온될때까지 진행.
* c~v를 잇는 간선을 제외한 나머지 간선은 무시하면 된다.
* 시간복잡도가 O(n)이라서 최초 정렬(O(nlgn))만 하면 빠르게 구할 수 있다.
*/