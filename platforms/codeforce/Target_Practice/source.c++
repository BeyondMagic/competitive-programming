/**
	*	author:		beyondmagic
**/
#include <bits/stdc++.h>

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

using namespace std;

#define endl '\n'

array<array<size_t, 10>, 10> ans{{
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
	{1, 2, 3, 3, 3, 3, 3, 3, 2, 1},
	{1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
	{1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
	{1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
	{1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
	{1, 2, 3, 3, 3, 3, 3, 3, 2, 1},
	{1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
}};

int solve()
{
	array<string, 10> grid;
	for (auto &l : grid)
		cin >> l;
	size_t p = 0;
	for (size_t i = 0; i < 10; ++i)
	{
		for (size_t j = 0; j < 10; ++j)
		{
			if (grid[i][j] == 'X')
			{
				p += ans[i][j];
			}
		}
	}
	return cout << p << endl, 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	size_t t = 1;
	cin >> t;
	while (t--)
		solve();
}
