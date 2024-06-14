#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	string S;
	cin >> S;

	int len = S.length();
	int answer = S.length() * 2 - 1;

	// �ǹ� ���� ���� ��� ��Ī üũ. ex) abcba
	for (int pivot = len - 1; pivot >= len / 2; pivot--)
	{
		bool isSymmetry = true;
		for (int j = 1; j < len - pivot; j++)
		{
			if (S.at(pivot + j) != S.at(pivot - j))			
				isSymmetry = false;			
		}

		if (isSymmetry)		
			answer = pivot * 2 + 1;		
	}

	// ���� ƴ ���� ��� ��Ī üũ. ex) bcaaaa
	int range;
	if (len % 2 == 0)
		range = len / 2;
	else
		range = len / 2 + 1;

	for (int pivot = len - 1; pivot >= range; pivot--)
	{
		bool isSymmetry = true;		
		for (int j = 1; j <= len - pivot; j++)
		{						
			if (S.at(pivot + j - 1) != S.at(pivot - j))					
				isSymmetry = false;			
		}		

		if (isSymmetry)		
			answer = min(answer, pivot * 2);		
	}

	cout << answer << "\n";
}