#include <iostream>
#include <map>
using namespace std;

int main()
{
	string input;
	cin >> input;
		
	map<char, int> index_Map
	{
		{'q', 0},
		{'u', 1},
		{'a', 2},
		{'c', 3},
		{'k', 4},
	};
	int ducks[5] = { 0,0,0,0,0 };
	int answer = -1;
	bool canExist = true;

	for (int i = 0; i < input.size(); i++)
	{
		int index = index_Map[input.at(i)];
		ducks[index]++;
		for (int i = index; i > 0; i--)
		{
			if (ducks[index] > ducks[index - 1])
				canExist = false;
		}

		if (index == 4)
		{
			answer = max(answer, ducks[0]);
			for (int i = 0; i < 5; i++)
			{
				ducks[i]--;
			}
		}

		if (canExist == false)
		{
			answer = -1;
			break;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		if (ducks[i] != 0)
		{
			answer = -1;
			break;
		}
	}	

	cout << answer << "\n";	
	return 0;
}