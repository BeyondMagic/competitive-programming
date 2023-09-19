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

#define oo SIZE_MAX / 2

size_t breadth_first_search (vector<vector<size_t>> &graph, size_t &start, size_t &destiny)
{
	vector<vector<size_t>> dist(graph.size(), vector<size_t>(3, oo));
	dist[start][0] = 0;

	queue<pair<size_t, size_t>> fila;
	fila.push({start, 0});
	
	while (not fila.empty())
	{
		const auto [u, d] = fila.front(); fila.pop();

		for (auto next : graph[u])
		{
			size_t normalised = (d + 1) % 3;

			if (dist[next][normalised] == oo)
			{
				dist[next][normalised] = dist[u][d] + 1;
				fila.push({next, normalised});
			}
		}
	}

	size_t total = dist[destiny][0];

	return total == oo ? total : total / 3;
}

int solve()
{
	size_t n, m;
	cin >> n >> m;
	vector<vector<size_t>> graph(n + 1);

	for (size_t u, v; m--;)
		cin >> u >> v, graph[u].emplace_back(v);

	size_t start, destiny;
	cin >> start >> destiny;

	const auto ans = breadth_first_search(graph, start, destiny);
	if (ans == oo)
		return puts("-1"), 0;
	return cout << ans << endl, 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	size_t u = 1;
	// cin >> t;
	while (u--)
		solve();
}
