#include "library.hpp"

using namespace std;

int n, m;
int a, b;
char c;
vector<vector<pair<int, char>>> adj;
const int INF = 1e9;

int main ()
{
	cin >> n >> m;
	adj.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}

	vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
	queue<pair<int, int>> q;

	// Start with the pair (1, N) with cost 0.
	dist[1][n] = 0;
	q.push({1, n});

	int ans = INF;

	while (not q.empty())
	{
		auto [u, v] = q.front();
		q.pop();
		int d = dist[u][v];

		// --- Check if we can finish the palindrome ---
		// (1) Even-length case: if the two pointers meet.
		if (u == v)
			ans = min(ans, d);

		// (2) Odd-length case: if there is an edge directly connecting u and v.
		// This works because the middle edge (with any character) does not need a matching partner.
		for (auto &edge : adj[u])
			if (edge.first == v)
				ans = min(ans, d + 1);

		// --- Transition: extend both ends simultaneously ---
		// For every edge from u with label c and every edge from v with label c,
		// we can move to state (u', v') and add 2 to the cost.
		for (auto &edge1 : adj[u])
		{
			int u2 = edge1.first;
			char letter = edge1.second;

			for (auto &edge2 : adj[v])
				if (edge2.second == letter)
				{
					int v2 = edge2.first;
					if (dist[u2][v2] > d + 2)
					{
						dist[u2][v2] = d + 2;
						q.push({u2, v2});
					}
				}
			
		}
	}

	print << (ans == INF ? -1 : ans) << endl;
}
