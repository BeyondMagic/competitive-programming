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
	size_t n, // students
		   m; // laces
	cin >> n >> m;
	vector<vector<size_t>> ties(n + 1);
	for (size_t i = 0, a, b; i < m; ++i)
	{
		cin >> a >> b;
		ties[a].emplace_back(b);
		ties[b].emplace_back(a);
	}

	size_t g = 0;
	set<size_t> to_delete;
	while (true)
	{
		to_delete.clear();
		for (size_t i = 1; i <= n; ++i)
			if (ties[i].size() == 1)
			{
				ties[i].clear();
				to_delete.insert(i) ;
			}

		for (size_t i = 1; i <= n; ++i)
		{
			ties[i].erase( remove_if( begin(ties[i]),end(ties[i]),
				[&] (auto x)
				{
					return binary_search( begin(to_delete) , end(to_delete), x);
				}), end(ties[i]) );
		}

		bool stop = true;
		for (size_t i = 1; i <= n and stop; ++i)
			if (ties[i].size() == 1)
				stop = false;

		if (to_delete.size())
			++g;

		if (not stop)
			continue;

		break;
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
