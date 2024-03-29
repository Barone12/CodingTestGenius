#include <iostream>
using namespace std;

struct Box
{
    int x1, y1, x2, y2;
};

int n;
Box boxes[1001];
int parent[1001];
int cnt = 0;

int find(int u)
{
    if (u == parent[u])
    {
        return u;
    }
    return parent[u] = find(parent[u]);
}

void merge(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u != v)
    {
        parent[v] = u;
        cnt--;
    }
}

bool meet(Box a, Box b)
{
    if (a.x1 < b.x1 && b.x2 < a.x2 && a.y1 < b.y1 && b.y2 < a.y2) 
    {
		return false;
	}
	if (a.x1 > b.x1 && b.x2 > a.x2 && a.y1 > b.y1 && b.y2 > a.y2) 
    {
		return false;
	}
	if (b.x1 > a.x2 || b.x2 < a.x1 || b.y1 > a.y2 || b.y2 < a.y1) 
    {
		return false;
	}
	return true;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    boxes[0] = { 0, 0, 0, 0 };
    parent[0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        boxes[i] = { x1, y1, x2, y2 };
        parent[i] = i;
    }
    cnt = n + 1;
    int result = 0;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            if (meet(boxes[i], boxes[j]))
            {
                merge(i, j);
            }
        }
    }
    cout << cnt - 1;
    return 0;
}

/*
* 한붓 그리기 문제. 이어진 도형은 같은 집합으로 분류한다.
* 도형의 관계를 파악할 떄는 우선 추상적 관계를 분류하고,
* 이후 각 관계에 대한 조건식을 세우는 방향으로 접근한다.
* 관계의 종류가 적다면 소거법으로 접근하는 것도 고려해볼 수 있다.
*/