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
#define oo 1'000'000'000'000'000

int solve()
{
	size_t n, m;
	cin >> n >> m;

	// ler
	vector<vector<pair<long long, long long>>> edges(n + 1);
	for (size_t i = 1, a, b, w; i <= m; ++i)
	{
		cin >> a >> b >> w;
		edges[a].emplace_back((long long)b, (long long)w);
		edges[b].emplace_back((long long)a, (long long)w);
	}

	// djikstra
	size_t s = n;
	vector<long long> dist(n + 1, oo),
				verts(n + 1, -1);


	priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

	pq.emplace(dist[s] = 0, s);

	while(not pq.empty())
	{
		auto [_w, u] = pq.top();
		pq.pop();

		if (_w > dist[size_t(u)])
			continue;

		for (const auto &[v, w] : edges[size_t(u)])
			if(dist[size_t(u)] + w < dist[size_t(v)])
				pq.emplace(dist[size_t(v)] = dist[size_t(u)] + w, v), verts[size_t(v)] = u;
	}

	if (dist[1] == oo)
		return cout << -1, 0;

	for (long long u = 1; u != -1; u = verts[size_t(u)])
		cout << u << ' ';
	return cout << endl, 0;
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
