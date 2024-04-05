#include <iostream>
#include <map>
using namespace std;

int main()
{
	string input;
	cin >> input;

	map<char, int> ducks;
	int answer = -1;
	bool canExist = true;
	for (int i = 0; i < input.size(); i++)
	{
		switch (input.at(i))
		{
		case 'q':
			ducks['q']++;
			break;
		case 'u':
			ducks['u']++;
			if (ducks['u'] > ducks['q'])
				canExist = false;
			break;
		case 'a':
			ducks['a']++;
			if (ducks['a'] > ducks['u'] || ducks['u'] > ducks['q'])
				canExist = false;
			break;
		case 'c':
			ducks['c']++;
			if (ducks['c'] > ducks['a'] || ducks['a'] > ducks['u'] || ducks['u'] > ducks['q'])
				canExist = false;
			break;
		case 'k':
			ducks['k']++;
			answer = max(answer, ducks['q']);
			if (ducks['k'] > ducks['c'] || ducks['c'] > ducks['a'] || ducks['a'] > ducks['u'] || ducks['u'] > ducks['q'])
				canExist = false;
			ducks['q']--;
			ducks['u']--;
			ducks['a']--;
			ducks['c']--;
			ducks['k']--;
			break;
		default:
			canExist = false;
			break;
		}

		if (canExist == false)
		{
			answer = -1;
			break;
		}
	}

	if (ducks['q'] == 0 && ducks['u'] == 0 && ducks['a'] == 0 && ducks['c'] == 0 && ducks['k'] == 0)
		cout << answer << "\n";
	else
		cout << "-1\n";
	return 0;
}