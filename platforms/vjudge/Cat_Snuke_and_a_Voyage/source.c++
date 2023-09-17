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
	// on island 1
	// wants to go to n
	size_t n, m;
	cin >> n >> m;
	vector<vector<size_t>> boats(n + 1);
	for (size_t i = 1, a, b; i <= m; ++i)
	{
		cin >> a >> b;
		boats[a].emplace_back(b);
		// boats[b].emplace_back(a);
	}

	for (auto &t : boats[1])
		for (auto &s : boats[t])
			if (s == n)
				return puts("POSSIBLE"), 0;
	return puts("IMPOSSIBLE"), 0;
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
