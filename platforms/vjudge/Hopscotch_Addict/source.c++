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

#define MIN 10
#define MAX 100'000 + MIN

bitset<MAX> visited;

typedef vector<vector<size_t>> Graph;

void dfs(size_t &s, size_t &t, Graph &graph, size_t &ans)
{
	if (visited[s])
		return;

	visited = true;

	for (auto &next : graph[s])
	{
		dfs(graph[], t, 
	}
}

int solve()
{
	size_t n, m;
	cin >> n >> m;
	vector<vector<size_t>> adjs(n + 1);
	for (size_t i = 1, u, v; i + 1<= n; ++i)
	{
		cin >> u >> v;
		adjs[u].emplace_back(v);
		adjs[v].emplace_back(u);
	}
	size_t s, t;
	cin >> s >> t;
	debug(s, t);

	size_t p = 0;
	dfs(s, t, adjs, p);

	return cout << p << endl, 0;
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
