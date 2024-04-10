#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> graph[500001];
int parent[50001];
int depth[50001] = { 0, };

void dfs(int n, int p)
{
    parent[n] = p;
    depth[n] = depth[p] + 1;
    for (int i = 0; i < graph[n].size(); ++i)
    {
        if (graph[n][i] != p)
        {
            dfs(graph[n][i], n);
        }
    }
}

int lca(int a, int b)
{
    if (depth[a] > depth[b])
    {
        swap(a, b);
    }
    while (depth[a] < depth[b])
    {
        b = parent[b];
    }
    while(a != b)
    {
        a = parent[a];
        b = parent[b];
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> N;
    for (int i = 0; i < N - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 0);
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
    return 0;
}

/*
* 최소 공통 조상은 깊이를 통해 찾는다.
* 두 노드의 깊이가 같아질 떄까지 한 노드만 거슬러 올라간 후 이후 한칸씩 같이 올라가도록 한다.
* 트리의 구조가 그래프처럼 되어 있기 때문에 그래프를 트리로 고치는 과정이 필요하다. DFS를 활용했다.
*/