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
#define MAX 2 * 100'000 + MIN
#define oo SIZE_MAX / 2

bitset<MAX> visited;

void depth_first_search (vector<vector<size_t>> &graph, size_t root)
{
	if (visited[root])
		return;

	visited[root] = true;

	// process
	cout << ' ' << root;

	for (auto next : graph[root])
		depth_first_search(graph, next);
}

void connected_components(vector<vector<size_t>> &graph)
{
	visited.reset();

	for (size_t i = 1, count = 0; i + 1 <= graph.size(); ++i)
		if (not visited[i] and graph[i].size())
		{
			cout << "Component " << ++count << " : ";
			depth_first_search(graph, i);
			cout << endl;
		}
}

int solve()
{
	size_t n, m;
	cin >> n >> m;
	vector<size_t> red(n + 1);
	for (size_t i = 1; i <= m; ++i)
		cin >> red[i];

	vector<size_t> blue(n + 1);
	for (size_t i = 1; i <= m; ++i)
		cin >> blue[i];

	vector<vector<size_t>> graph(n + 10);
	for (size_t i = 1; i <= m; ++i)
	{
		debug(red[i], blue[i]);
		graph[red[i]].emplace_back(blue[i]),
		graph[blue[i]].emplace_back(red[i]);
	}
	
	connected_components(graph);

	for (size_t i = 1; i <= n; ++i)
	{
		debug(i, graph[i]);
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
