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
	size_t n;
	cin >> n;
	string s;
	//          wins ID
	vector<pair<int, int>> players(n, make_pair(0, 0));
	for (size_t i = 0; i < n; ++i)
	{
		cin >> s;
		players[i].second = int(i + 1);
		for (size_t j = 0; j < n; ++j)
			if (s[j] == 'o')
			{
				++players[i].first;
			}
	}

	sort(begin(players), end(players), [&](pair<int, int> a, pair<int, int> b){
		if (a.first > b.first)
		{
			return true;
		} else if (a.first == b.first) {
			if (a.second < b.second)
				return true;
			else
				return false;
		}
			return false;
			});

	for (int i = 0; i < n; ++i)
	{
		cout << players[i].second << (i + 1 == n ? endl : ' ');
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
