#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[1001];
int cost[1001][1001];

int find(int u)
{
    if (parent[u] == u)
    {
        return u;
    }
    else
    {
        return parent[u] = find(parent[u]);
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

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N, M;
    cin >> N >> M;
    for (int i = 2; i <= N; ++i)
    {
        parent[i] = i;
    }
    for (int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> cost[i][j];
        }
    }
    vector<vector<int>> edges;
    int result = 0;
    vector<vector<int>> addedEdges;
    for (int i = 2; i <= N; ++i)
    {
        for (int j = i + 1; j <= N; ++j)
        {
            edges.push_back({cost[i][j], i, j});
        }
    }
    sort(edges.begin(), edges.end());
    for (int i = 0; i < edges.size(); ++i)
    {
        if (merge(edges[i][1], edges[i][2]))
        {
            result += edges[i][0];
            addedEdges.push_back({ edges[i][1], edges[i][2] });
        }
    }
    cout << result << " " << addedEdges.size() << '\n';
    for (int i = 0; i < addedEdges.size(); ++i)
    {
        cout << addedEdges[i][0] << " " << addedEdges[i][1] << '\n';
    }
    return 0;
}

/*
* 1�� ��ǻ�Ͱ� ��� ��ǻ�Ͱ� ����Ǳ� ������, 1������ �������� ��츸 üũ�ϸ� �ȴ�.
* ���� �׷������� 1������ ������ ���¿��� ��� ������ ����Ʈ�� �߰��ϰ�
* �ش� ����Ʈ�� ũ�罺Į�� �����鼭 �ּ� ���д� Ʈ���� �׸���.
* �� �� �߰��Ǵ� �����鸸 ���� �̾Ƴ� ����ϸ� ���� ���´�.
*/