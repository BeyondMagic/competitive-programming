/**
	*	author:		beyondmagic
	*	sensei:		Edson Alves
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
	#include "debug.h"
#else
	#define debug(...)
#endif

#define endl '\n'

#define oo 1000000000000000007

auto djikistra (vector<vector<pair<long long, long long>>> &edges, long long source, long long destiny)
{
	int n = int(edges.size());
	int s = source;
	vector<long long> dist(n + 1, oo),
						verts(n + 1, -1);

	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

	pq.emplace(dist[s] = 0, s);

	while (not pq.empty())
	{
		auto [_w, u] = pq.top();
		pq.pop();

		if (_w > dist[u])
			continue;

		for (const auto &[v, w] : edges[u])
			if (dist[u] + w < dist[v])
				pq.emplace(dist[v] = dist[u] + w, v),
				verts[v] = u;
	}

	if (dist[destiny] == oo)
		return (long long)(-1);

	return dist[destiny];
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<pair<long long, long long>>> graph(n + 1);

	for (int i = 1, a, b, x; cin >> a >> b >> x; ++i)
		graph[i].emplace_back(i + 1, a),
		graph[i].emplace_back(x, b);

	cout << djikistra(graph, 1, n) << endl;
}
