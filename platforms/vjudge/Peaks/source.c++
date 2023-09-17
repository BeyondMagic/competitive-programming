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
	size_t n, m;
	cin >> n >> m;
	vector<pair<size_t, vector<size_t>>> data(n + 1, {0, {}});
	
	// elevation
	for (size_t i = 1; i <= n; ++i)
		cin >> data[i].first;

	// roads
	for (size_t i = 1, f, t; i <= m; ++i)
	{
		cin >> f >> t;
		data[t].second.emplace_back(f);
		data[f].second.emplace_back(t);
	}

	size_t g = 0;
	for (size_t i = 1; i <= n; ++i)
	{
		const auto s = data[i].second.size();
		if (s == 0)
		{
			++g;
			continue;
		}
		
		bool good = true;
		for (auto &p : data[i].second)
			if (data[i].first <= data[p].first)
			{
				good = false;
				break;
			}

		if (good)
			++g;

	}

	return cout << g << endl, 0;
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
