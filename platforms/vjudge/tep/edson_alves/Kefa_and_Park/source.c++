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
typedef vector<pair<size_t, vector<size_t>>> Graph;

size_t limit;

#define MIN 10
#define MAX 100'000 + MIN
bitset<MAX> visited;
size_t restaurants = 0, b;

void dfs1 (size_t root, Graph &graph, size_t &count)
{
	if (visited[root])
		return;

	visited[root] = true;

	// ここカウンタんか下までです
	count = graph[root].first ? count + 1 : 0;

	// cannot continue down this tree.
	if (count > limit)
		return;

	// if it's a leaf = restaurant.
	if (root - 1 and graph[root].second.size() == 1)
		++restaurants;

	for (auto &next : graph[root].second)
	{
		size_t other = count;
		dfs1(next, graph, other);
	}
}

int solve()
{
	size_t n, // vertices
		   m; // maximum number of consecutive vertices with cats that is still ok for Kefa.
	cin >> n >> m;
	//         has cat?  edges
	Graph graph(n + 1);
	for (size_t i = 1, a; i <= n; ++i)
		cin >> a, graph[i].first = a;

	for (size_t i = 1, x, y; i + 1 <= n; ++i)
	{
		cin >> x >> y;
		graph[x].second.emplace_back(y);
		graph[y].second.emplace_back(x);
	}

	size_t count = 0;
	limit = m;
	dfs1(1, graph, count);

	return cout << restaurants << endl, 0;
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
