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
	//       points | id of problem
	vector<int> just_points;
	vector<pair<int, int>> problems;
	for (size_t i = 1, a; i <= m; ++i)
	{
		cin >> a, problems.emplace_back(a, i);
		just_points.emplace_back(a);
	}

	ranges::sort(problems, std::greater<pair<int, int>>());
	vector<int> players(n);
	// iota(begin(players), end(players), 1);
	// for (size_t i = 0; i < m; ++i)
	// {
	// 	debug(i, problems[i]);
	// }

	string s;
	for (size_t i = 0; i < n; ++i)
	{
		cin >> s;
		players[i] += i + 1;
		for (size_t j = 0; j < m; ++j)
		{
			if (s[j] == 'o')
				players[i] += just_points[j];
		}
		// debug(i, players[i]);
	}

	for (size_t i = 0; i < n; ++i)
	{
		// pegar max verdadeiro sem contar o player que estamos usando
		int mx = 0;
		for (size_t j = 0; j < n; ++j)
			if (j != i and players[j] > mx)
				mx = players[j];

		size_t ps = 0;
		int pn = players[i];
		for (size_t j = 0; pn <= mx and j < m; ++j)
			pn += problems[j].first, ++ps;
		debug(i, pn);

		cout << ps << endl;
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
