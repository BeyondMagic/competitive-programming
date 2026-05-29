#include "library.hpp"

using namespace std;

long long INF = LONG_LONG_MAX;

int main()
{
	fast_io();

	int n, m, input_c;
	long long k;
	if (!(cin >> n >> m >> input_c >> k))
		return 0;

	vector<int> p(input_c);
	bool has_1 = false, has_n = false;
	for (int i = 0; i < input_c; ++i) {
		cin >> p[i];
		if (p[i] == 1) has_1 = true;
		if (p[i] == n) has_n = true;
	}

	// Ensure rooms 1 and N are strictly in our people array as per constraints
	if (!has_1) p.push_back(1);
	if (!has_n) p.push_back(n);
	int c = p.size();

	// 1D Forward Star graph
	vector<int> head(n + 1, -1);
	vector<int> to(m);
	vector<long long> weight(m);
	vector<int> nxt(m);
	vector<int> in_degree(n + 1, 0);

	for (int i = 0; i < m; ++i) {
		int u, v;
		long long w;
		cin >> u >> v >> w;
		to[i] = v;
		weight[i] = w;
		nxt[i] = head[u];
		head[u] = i;
		in_degree[v]++;
	}

	// Kahn's Topological Sort
	vector<int> topo;
	topo.reserve(n);
	queue<int> q;
	for (int i = 1; i <= n; ++i) {
		if (in_degree[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		topo.push_back(u);
		for (int e = head[u]; e != -1; e = nxt[e]) {
			if (--in_degree[to[e]] == 0) {
				q.push(to[e]);
			}
		}
	}

	// Massive 1D array to compute distances from all people SIMULTANEOUSLY
	// dist[u * c + i] = shortest distance from person index 'i' to room 'u'
	vector<long long> dist((n + 1) * c, INF);

	// Initialise sources
	for (int i = 0; i < c; ++i) {
		dist[p[i] * c + i] = 0;
	}

	// The Magic: Single-Pass Vectorised Graph Traversal
	for (int u : topo) {
		int u_base = u * c;
		for (int e = head[u]; e != -1; e = nxt[e]) {
			int v = to[e];
			long long w = weight[e];
			int v_base = v * c;

			// This inner loop runs entirely in L1 Cache
			for (int i = 0; i < c; ++i) {
				long long du = dist[u_base + i];
				if (du != INF) {
					if (dist[v_base + i] > du + w) {
						dist[v_base + i] = du + w;
					}
				}
			}
		}
	}

	// Sort people topologically so our DP is mathematically sound
	vector<int> pos_in_topo(n + 1, -1);
	auto sz = int(topo.size());
	for (int i = 0; i < sz; ++i) {
		pos_in_topo[topo[i]] = i;
	}

	vector<int> sorted_p_idx(c);
	for (int i = 0; i < c; ++i) sorted_p_idx[i] = i;
	sort(sorted_p_idx.begin(), sorted_p_idx.end(), [&](int a, int b) {
			return pos_in_topo[p[a]] < pos_in_topo[p[b]];
			});

	// DP on the extracted C x C Graph
	vector<long long> dp(c, INF);

	int start_idx = -1, end_idx = -1;
	for (int i = 0; i < c; ++i) {
		if (p[i] == 1) start_idx = i;
		if (p[i] == n) end_idx = i;
	}

	dp[start_idx] = 0;

	for (int i : sorted_p_idx) {
		if (dp[i] == INF) continue;

		for (int j : sorted_p_idx) {
			if (i == j) continue;

			long long d = dist[p[j] * c + i]; // Extracted distance
			if (d != INF) {
				long long time_cost = max(0LL, d - k);
				if (dp[j] > dp[i] + time_cost) {
					dp[j] = dp[i] + time_cost;
				}
			}
		}
	}


	cout << (dp[end_idx] == INF ? -1 : dp[end_idx]) << endl;
}
