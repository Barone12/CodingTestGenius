#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> graph[32001];
vector<int> topologicalSort;
bool visited[32001] = { false, };

void dfs(int v)
{
    visited[v] = true;
    for (int i = 0; i < graph[v].size(); ++i)
    {
        if (!visited[graph[v][i]])
        {
            dfs(graph[v][i]);
        }
    }
    topologicalSort.push_back(v);
}

int main() 
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
    reverse(topologicalSort.begin(), topologicalSort.end());
    for (int i = 0; i < topologicalSort.size(); ++i)
    {
        cout << topologicalSort[i] << " ";
    }
    return 0;
}

/*
* 위상 정렬 문제. 대소관계를 간선으로 생각하고 위상정렬하여 푼다.
* 정의에서 해당 문제가 대소 관계를 나타낸다고 했으니 순환이 생길 수 없다.
*/