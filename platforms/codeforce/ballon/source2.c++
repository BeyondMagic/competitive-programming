/**
	*	author:		beyondmagic
	*	sensei:		Edson Alves
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
	#include "debug.h"
#else
	#define debug(...)
#endif

#define endl '\n'

// (x, y)
using point = pair<int, int>;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, c;
	cin >> n >> c;

	vector<point> points(n * 2);
	for (auto &[x, y] : points)
		cin >> x >> y;

	ranges::sort(points);

	for (int i = 0; i < n * 2 - 1; i += 2)
	{
		point a = points[i],
			  b = points[i + 1];

		int x, y;

		// perpendicular
		if (a.second == b.second)
			continue;

		// left-hand point
		else if (a.second > b.second)
			x = a.first,
			y = a.second;

		// right-hand point
		else
			x = b.second,
			y = b.second;

		// go to the next line
		for (int j = i + 2; j < n * 2 - 1; j += 2)
		{
			if (x 
		}

	}
}
