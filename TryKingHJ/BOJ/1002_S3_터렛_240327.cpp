#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int T, x, x2, y, y2, r1, r2;

int main()
{
	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		scanf("%d %d %d", &x, &y, &r1);
		scanf("%d %d %d", &x2, &y2, &r2);

		double dist = sqrt(pow(abs(x - x2), 2) + pow(abs(y - y2), 2));
		int answer = 0;

		if (dist == 0 && r1 == r2)
			answer = -1;
		else if (dist == r1 + r2 || dist == max(r1, r2) - min(r1, r2))
			answer = 1;
		else if (abs(r1 - r2) < dist && dist < r1 + r2)
			answer = 2;
		else
			answer = 0;

		printf("%d\n", answer);
	}

	return 0;
}