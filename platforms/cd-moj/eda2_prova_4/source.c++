#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
	#include "debug.h"
#else
	#define debug(...)
#endif

#define endl '\n'

#define oo INT_MAX

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k, c;
	cin >> n >> m >> k >> c;
	vector<vector<int>> adj(n);
	for (int u, v; cin >> u >> v;)
		adj[u].emplace_back(v),
		adj[v].emplace_back(u);

	queue<int> q;
	vector<int> dist(n, oo);
	dist[c] = 0;

	q.emplace(c);
	while (not q.empty())
	{
		int u = q.back();
		q.pop();

		for (auto &v : adj[u])
			if (dist[v] == oo)
				q.emplace(v),
				dist[v] = dist[u] + 1;
	}

	int ans = 0;
	for (auto &d : dist)
		ans += d <= k ? 1 : 0;

	cout << ans << endl;
}
