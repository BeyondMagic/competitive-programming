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

array<size_t, 5> groups{0};

int solve()
{
	size_t n, a;
	cin >> n;
	while (n--)
		cin >> a, ++groups[a];

	// 1 to 3
	if (groups[1] >= 4)
	{
		groups[4] += groups[1] / 4;
		groups[1] = groups[1] % 4;
	}
	debug(groups);

	// 1 to 3
	if (groups[3] and groups[1])
	{
		size_t delta = min(groups[3], groups[1]);
		groups[3] -= delta;
		groups[1] -= delta;
		groups[4] += delta;
	}
	debug(groups);

	// 1 to 2
	if (groups[1])
	{
		size_t delta = groups[1] / 2;
		groups[1] -= delta;
		groups[2] += delta;
	}
	debug(groups);

	// 2 to 4
	if (groups[2] >= 2)
	{
		size_t delta = groups[2] & 1 ? groups[2] - 1 : groups[2];
		groups[2] -= delta;
		groups[4] += delta / 2;
	}
	debug(groups);
	return cout << accumulate(begin(groups), end(groups), 0) << endl, 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	size_t t = 1;
	while (t--)
		solve();
}
