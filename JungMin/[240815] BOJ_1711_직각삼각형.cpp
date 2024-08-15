#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	vector<pair<long long, long long>> vec;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		long long x, y;
		cin >> x >> y;
		vec.push_back({ x, y });
	}

	int result = 0;
	long long x1, x2, x3;
	long long y1, y2, y3;
	for (int i = 0; i < N; i++)
	{
		x1 = vec[i].first;
		y1 = vec[i].second;
		for (int j = i + 1; j < N; j++)
		{
			x2 = vec[j].first;
			y2 = vec[j].second;
			for (int k = j + 1; k < N; k++)
			{
				x3 = vec[k].first;
				y3 = vec[k].second;

				long long dist1 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
				long long dist2 = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);
				long long dist3 = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);
				
				if (dist1 >= dist2 && dist1 >= dist3)
				{
					if (dist1 == dist2 + dist3)
						result++;
				}
				else if (dist2 >= dist1 && dist2 >= dist3)
				{
					if (dist2 == dist1 + dist3)
						result++;
				}
				else if (dist3 >= dist1 && dist3 >= dist2)
				{
					if (dist3 == dist1 + dist2)
						result++;
				}
			}
		}
	}

	cout << result << "\n";
}