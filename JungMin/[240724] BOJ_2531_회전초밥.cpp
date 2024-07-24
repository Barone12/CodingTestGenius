#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, d, k, c;
	cin >> N >> d >> k >> c;

	vector<int> sushi;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		sushi.push_back(temp);
	}

	int result = 0;
	int sushiCount = 0;
	bool check[3001] = { false };
	for (int i = 0; i < N; i++)
	{
		sushiCount = 0;
		for (int j = i; j < i + k; j++)
		{
			int temp = j >= N ? j - N : j;
			if (check[sushi[temp]] == false)
			{
				sushiCount++;
				check[sushi[temp]] = true;
			}
		}

		if (check[c] == false)
			sushiCount++;

		for (int j = 0; j < 3001; j++)
			check[j] = false;

		result = max(result, sushiCount);
	}
	cout << result << "\n";
}