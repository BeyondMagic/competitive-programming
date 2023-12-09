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

//                 c          a    b
using edge = tuple<long long, int, int>;

struct UnionFind
{
	vector<int> parents, rank;

	UnionFind (int n) : parents(n + 1), rank(n + 1, 0)
	{
		iota(begin(parents), end(parents), 0);
	}

	bool same_set (int a, int b)
	{
		return find_set(a) == find_set(b);
	}

	void union_set (int a, int b)
	{
		if (same_set(a, b))
			return;

		int p = find_set(a),
			q = find_set(b);

		if (rank[p] > rank[q])
			parents[q] = p;
		else if (rank[q] > rank[p])
			parents[p] = q;
		else
			parents[q] = p,
			++rank[p];
	}

	int find_set (int a)
	{
		return parents[a] == a ? a : (parents[a] = find_set(parents[a]));
	}
};

pair<long long, int> kruskal (int n, vector<edge> &graph)
{
	sort(begin(graph), end(graph));

	long long cost = 0, amount = 0;

	UnionFind ufds(n);

	for (auto &[c, a, b] : graph)
		if (not ufds.same_set(a, b))
		{
			cost += c,
			ufds.union_set(a, b);
			++amount;
		}

	return make_pair(cost, amount);
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<edge> graph(m);
	for (auto &[c, a, b] : graph)
		cin >> a >> b >> c;

	auto [ans, amount] = kruskal(n, graph);
	if (amount == n - 1)
		cout << ans << endl;
	else
		puts("IMPOSSIBLE");
}
