#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Snowman
{
	int height;
	int index[2];
};

bool cmp(Snowman a, Snowman b)
{
	return a.height < b.height;
}

bool isOverlap(Snowman a, Snowman b)
{
	return a.index[0] == b.index[0] || a.index[0] == b.index[1]
		|| a.index[1] == b.index[0] || a.index[1] == b.index[1];
}

int main()
{
	int N;
	cin >> N;

	vector<int> ball;
	vector<Snowman> snowmans;
	int temp;
	
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		ball.push_back(temp);
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			Snowman s;
			s.height = ball[i] + ball[j];
			s.index[0] = i;
			s.index[1] = j;
			snowmans.push_back(s);
		}
	}
	
	int answer = 1000000001;
	sort(snowmans.begin(), snowmans.end(), cmp);
	for (int i = 1; i < snowmans.size(); i++)
	{
		int diff = 1;
		while (isOverlap(snowmans[i], snowmans[i - diff]))
		{
			diff++;
			if (i - diff < 0)
				break;
		}
		if (i - diff < 0)
			continue;
		answer = min(answer, snowmans[i].height - snowmans[i - diff].height);
	}
	cout << answer << "\n";
}