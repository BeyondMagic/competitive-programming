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

int solve()
{
	size_t y, x;
	cin >> y >> x;
	for (size_t i = 1; i <= y; ++i)
	{
		for (size_t j = 1; j <= x; ++j)
		{
			if (i & 1)
				putchar('#');
			else if (i & 3)
				putchar(j == x ? '#' : '.');
			else
				putchar(j == 1 ? '#' : '.');
		}
		putchar('\n');
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	size_t t = 1;
	// cin >> t;
	while (t--)
		solve();
}
